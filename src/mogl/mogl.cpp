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

namespace mogl
{
  ModernOpenGL *ModernOpenGL::spInstance = nullptr;
#if defined(MOGL_OS_WINDOWS)

#elif defined(MOGL_OS_LINUX)
  ModernOpenGL::ModernOpenGL(uint8_t colorBits, uint8_t depthBits, uint8_t stencilBits,
                             uint16_t samples, const Display *pDisplay, const Window &rWindow) : mpDisplay(pDisplay)
  {
    // Check if there is already an active instance of MOGL
    if (spInstance)
    {
      throw std::runtime_error("There can only be one active ModernOpenGL instance");
    }

    // Get the display and screen in terms glx can use
    Display *display = const_cast<Display *>(mpDisplay);
    if (!display)
    {
      throw std::runtime_error("Pointer to X server cannot be null.");
    }
    int screen = DefaultScreen(display);

    // Load GLX extensions from GLAD
    if (!gladLoaderLoadGLX(display, screen))
    {
      throw std::runtime_error("Failed to load extensions for GLX.");
    }

    // Attributes for configuration
    static const int frameBufferAttribs[] = {
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
    GLXFBConfig *configs = glXChooseFBConfig(display, screen, frameBufferAttribs, &count);
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
    mContext = glXCreateContextAttribsARB(display, config, nullptr, GL_TRUE, contextAttribs);
    if (!mContext)
    {
      throw std::runtime_error("Failed to create an OpenGL context.");
    }

    // Make the context current for the window
    glXMakeCurrent(display, rWindow, mContext);

    // Load GL extensions from GLAD
    if (!gladLoaderLoadGL())
    {
      throw std::runtime_error("Failed to load extensions for OpenGL 4.6.");
    }

    // Get the major and minor version of the new OpenGL context
    int major, minor;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);

    if (major != MOGL_MAJOR_VERSION || minor != MOGL_MINOR_VERSION)
    {
      // TODO: Use std::format for this when available
      throw std::runtime_error("Created OpenGL context version mismatch!");
    }

    // Track this instance of MOGL
    spInstance = this;
  }

  ModernOpenGL::~ModernOpenGL() noexcept
  {
    // Free all MOGL resources here

    freeAllObjects();

    // Destroy the OpenGL context
    Display *pDisplay = const_cast<Display *>(mpDisplay);
    glXMakeCurrent(pDisplay, 0, NULL);
    glXDestroyContext(pDisplay, mContext);

    // Indicate no more active instance
    spInstance = nullptr;
  }

  void ModernOpenGL::setVerticalSync(bool enabled) noexcept
  {
    glXSwapIntervalSGI(enabled ? 1 : 0);
  }
#endif

  void ModernOpenGL::freeAllObjects() noexcept
  {
    // Delete every object from the mogl object map
    for (auto it = mObjectMap.begin(); it != mObjectMap.end(); it++)
    {
      for (auto obj = it->second.begin(); obj != it->second.end(); obj++)
      {
        printf("Delete 2\n");
        delete obj->second;
        obj->second = nullptr;
      }
    }

    mObjectMap.clear();
  }
} // namespace mogl