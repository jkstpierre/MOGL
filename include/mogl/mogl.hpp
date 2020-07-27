/**
 * @file mogl.hpp
 * @author jkstpierre (jkstpierre@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2020-07-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __MOGL_MOGL_HPP__
#define __MOGL_MOGL_HPP__

#include <mogl/platform.hpp>

namespace mogl
{
  /**
   * @brief The OpenGL context's major version number
   * 
   */
  const unsigned int MOGL_MAJOR_VERSION = 4U;

  /**
   * @brief The OpenGL context's minor version number
   * 
   */
  const unsigned int MOGL_MINOR_VERSION = 6U;

  /**
   * @brief A ModernOpenGL instance represents an OpenGL 4.6 context and upon successful construction 
   * grants access to the OpenGL API in a C++ friendly OOP manner
   * 
   */
  class ModernOpenGL
  {
  public:
#if defined(MOGL_OS_WINDOWS)
    /**
     * @brief Construct a new Modern Open G L object
     * 
     * @param colorBits 
     * @param depthBits 
     * @param stencilBits 
     * @param samples 
     * @param window 
     */
    ModernOpenGL(uint8_t colorBits, uint8_t depthBits, uint8_t stencilBits, uint16_t samples, const HWND window);
#elif defined(MOGL_OS_LINUX)
    /**
     * @brief Construct a new Modern Open G L object
     * 
     * @param colorBits The number of bits for the color buffer
     * @param depthBits The number of bits for the depth buffer
     * @param stencilBits The number of bits for the stencil buffer
     * @param samples The number of samples for antialiasing
     * @param rDisplay The X11 display server reference
     * @param rWindow The X11 window reference
     */
    ModernOpenGL(uint8_t colorBits, uint8_t depthBits, uint8_t stencilBits, uint16_t samples, const Display &rDisplay, const Window &rWindow);
#endif
    /**
     * @brief Destroy the Modern OpenGL object
     * 
     */
    virtual ~ModernOpenGL() noexcept;

    ModernOpenGL(const ModernOpenGL&) = delete;

    ModernOpenGL(ModernOpenGL&&) noexcept = delete;

    ModernOpenGL& operator=(const ModernOpenGL&) = delete;

    ModernOpenGL& operator=(ModernOpenGL&&) noexcept = delete;

  private:
    /**
     * @brief ModernOpenGL only supports one active context at a time, for this reason
     * we introduce a static field that tracks whether there is an active context or not
     * 
     */
    static ModernOpenGL *spInstance;

  private:
#if defined(MOGL_OS_WINDOWS)
    HGLRC mContext;
#elif defined(MOGL_OS_LINUX)
    GLXContext mContext;
    const Display &mrDisplay;
#endif
  };
} // namespace mogl

#endif