/**
 * @file window.hpp
 * @author jkstpierre (jkstpierre@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2020-07-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __MOGL_WINDOWS_WINDOW_HPP__
#define __MOGL_WINDOWS_WINDOW_HPP__

#include <string>

namespace mogl::windows
{
  /**
   * @brief The Window contains the rendering space for the OpenGL in addition to basic event handling
   * 
   */
  class Window
  {
  public:
    /**
     * @brief Construct a new Window object
     * 
     * @param name 
     * @param x 
     * @param y 
     * @param width 
     * @param height 
     */
    Window(const std::string &name, const int &x, const int &y, const int &width, const int &height);

  private:
  };
} // namespace mogl::windows

#endif