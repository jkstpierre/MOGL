/**
 * @file  mogl/context_win32.cpp.
 *
 * Implements the context window 32 class
 */

#include "mogl/context.hpp"
#include "mogl/allocator.hpp"
#include <stdexcept>

#if defined(MOGL_OS_WINDOWS)

namespace mogl
{
Context::Context(uint8_t color, uint8_t depth, uint8_t stencil, uint8_t antialias, HDC dc) : mDeviceContext(nullptr), mOpenGLContext(nullptr)
{
  // Make sure only 1 context is ever active
  if ( sActive )
  {
    throw std::runtime_error("Cannot have more than one active OpenGL context.");
  }

  // Create temp window for loading in the OpenGL function pointers
  HWND tempWindow = CreateWindowA("STATIC", "", WS_POPUP | WS_DISABLED, 0, 0, 1, 1, NULL, NULL, GetModuleHandle(NULL), NULL);
  HDC tempDC = GetDC(tempWindow);

  // Set temporary pixel format descriptor so we can create a temporary context for loading our function pointers from
  PIXELFORMATDESCRIPTOR tempPixelFormatDescriptor =
  {
    sizeof(tempPixelFormatDescriptor), 1, PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
    PFD_TYPE_RGBA, color, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, depth, stencil, 0, PFD_MAIN_PLANE,
    0, 0, 0, 0
  };

  // The chosen temp pixel format 
  int tempPixelFormat = ChoosePixelFormat(tempDC, &tempPixelFormatDescriptor);
  SetPixelFormat(tempDC, tempPixelFormat, &tempPixelFormatDescriptor);

  // Create dummy context
  HGLRC tempContext = wglCreateContext(tempDC);
  wglMakeCurrent(tempDC, tempContext);

  // Load the OpenGL 4.6 extensions
  if ( !gladLoaderLoadGL() )
  {
    throw std::runtime_error("Failed to load OpenGL extensions.");
  }

  // Load the WGL extensions
  if ( !gladLoaderLoadWGL(tempDC) )
  {
    throw std::runtime_error("Failed to load WGL extensions.");
  }

  // Set real pixel attribs for the actual context
  int pixelAttribs[] = {
    WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
    WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
    WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
    WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
    WGL_COLOR_BITS_ARB, color,
    WGL_DEPTH_BITS_ARB, depth,
    WGL_STENCIL_BITS_ARB, stencil,
    WGL_SAMPLE_BUFFERS_ARB, antialias > 1 ? GL_TRUE : GL_FALSE,
    WGL_SAMPLES_ARB, antialias > 1 ? antialias : 0,
    0
  };

  // Choose the pixel format for our new context
  int pixelFormat;
  unsigned int n;
  wglChoosePixelFormatARB(dc, pixelAttribs, nullptr, 1, &pixelFormat, &n);
  if ( n == 0 )
  {
    throw std::runtime_error("Failed to establish a pixel format for the OpenGL context.");
  }
  SetPixelFormat(dc, pixelFormat, &tempPixelFormatDescriptor);

  // The attributes for the context
  const int contextAttribs[] = {
    WGL_CONTEXT_MAJOR_VERSION_ARB, CONTEXT_MAJOR_VERSION,
    WGL_CONTEXT_MINOR_VERSION_ARB, CONTEXT_MINOR_VERSION,
    WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
    0
  };

  // Create the opengl context
  mOpenGLContext = wglCreateContextAttribsARB(dc, nullptr, contextAttribs);
  // Save device context
  mDeviceContext = dc;

  // Destroy temporary context and window 
  wglMakeCurrent(dc, nullptr);
  wglDeleteContext(tempContext);
  wglMakeCurrent(dc, mOpenGLContext);
  DestroyWindow(tempWindow);

  // Indicate successful context creation
  sActive = true;
}

Context::~Context() noexcept
{
  // Free all OpenGL objects
  mAllocator.freeAll();

  // Delete the OpenGL context
  wglMakeCurrent(mDeviceContext, nullptr);
  wglDeleteContext(mOpenGLContext);

  sActive = false;
}
}

#endif