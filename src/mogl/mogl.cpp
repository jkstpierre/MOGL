/**
 * @file mogl.cpp
 * @author jkstpierre (jkstpierre@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2020-07-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <mogl/mogl.hpp>
#include <stdexcept>

namespace mogl
{
  ModernOpenGL *ModernOpenGL::spInstance = nullptr;
#if defined(MOGL_OS_WINDOWS)

#elif defined(MOGL_OS_LINUX)
  ModernOpenGL::ModernOpenGL(uint8_t colorBits, uint8_t depthBits, uint8_t stencilBits,
                             uint16_t samples, const Display &rDisplay, const Window &rWindow) : mrDisplay(rDisplay)
  {
    // Create OpenGL context for the X window

    if (spInstance)
    {
      // There is already an active instance of OpenGL
      throw std::runtime_error("There can only be one active instance of ModernOpenGL.");
    }

    // Load GL extensions from GLAD
    if (!gladLoadGL())
    {
      throw std::runtime_error("Failed to load extensions for OpenGL 4.6.");
    }

    // Get the display and screen in terms glx can use
    Display *pDisplay = const_cast<Display *>(&rDisplay);
    int screen = DefaultScreen(pDisplay);

    // Load GLX extensions from GLAD
    if (!gladLoadGLX(pDisplay, screen))
    {
      throw std::runtime_error("Failed to load extensions for GLX.");
    }

    // Attributes for configuration
    const int frameBufferAttribs[] = {
        GLX_X_RENDERABLE, GL_TRUE,
        GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
        GLX_DOUBLEBUFFER, GL_TRUE,
        GLX_RENDER_TYPE, GLX_RGBA_BIT,
        GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
        GLX_BUFFER_SIZE, colorBits,
        GLX_DEPTH_SIZE, depthBits,
        GLX_STENCIL_SIZE, stencilBits,
        GLX_SAMPLE_BUFFERS, samples > 1 ? GL_TRUE : GL_FALSE,
        GLX_SAMPLES, samples > 1 ? (int)samples : 0,
        0};

    // Configure the frame buffer for the given display
    int count;
    GLXFBConfig *configs = glXChooseFBConfig(pDisplay, screen, frameBufferAttribs, &count);
    if (count == 0)
    {
      throw std::runtime_error("Failed to find any valid frame buffers for the provided settings.");
    }

    // Choose the first available configuration
    GLXFBConfig config = configs[0];
    XFree(configs);

    // Attributes for setting up the OpenGL 4.6 context
    const int contextAttribs[] = {
        GLX_CONTEXT_MAJOR_VERSION_ARB, MOGL_MAJOR_VERSION,
        GLX_CONTEXT_MINOR_VERSION_ARB, MOGL_MINOR_VERSION,
        GLX_CONTEXT_PROFILE_MASK_ARB, GLX_CONTEXT_CORE_PROFILE_BIT_ARB,
        0};

    // Create the OpenGL 4.6 context
    mContext = glXCreateContextAttribsARB(pDisplay, config, nullptr, GL_TRUE, contextAttribs);
    if (!mContext)
    {
      throw std::runtime_error("Failed to create an OpenGL context.");
    }

    // Make the context current for the window
    glXMakeCurrent(pDisplay, rWindow, mContext);

    // TODO: Get default viewport

    // Track this instance of MOGL
    spInstance = this;
  }

  ModernOpenGL::~ModernOpenGL() noexcept
  {
    // Free all MOGL resources here

    // Destroy the OpenGL context
    Display *pDisplay = const_cast<Display *>(&mrDisplay);
    glXMakeCurrent(pDisplay, 0, NULL);
    glXDestroyContext(pDisplay, mContext);

    // Indicate no more active instance
    spInstance = nullptr;
  }
#endif
} // namespace mogl