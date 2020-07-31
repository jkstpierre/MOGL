/**
 * @file glbuffer.hpp
 * @author jkstpierre (jkstpierre@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2020-07-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __MOGL_OBJECTS_GLBUFFER_HPP__
#define __MOGL_OBJECTS_GLBUFFER_HPP__

#include <mogl/base/gl_object.hpp>

namespace mogl::objects
{
  const GLuint GLBUFFER_ID_NONE = 0U;   // Null Buffer Id

  /**
   * @brief A GLbuffer is an OpenGL object that stores data such as vertices and elements among other things for use during draw calls.
   * For a GLbuffer to be used during a draw call, a GLvertexArray's BindingPoint must be set to read from the buffer and 1 or more 
   * GLattributes from the same GLvertexArray object must be configured to read from the BindingPoint associated to the GLbuffer.
   * 
   * @tparam T The type of data to store within the GLbuffer object
   */
  template <class T>
  class GLbuffer : public base::GLobject
  {
  public:
  protected:
  };
} // namespace mogl::base

#endif