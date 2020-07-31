/**
 * @file type.hpp
 * @author jkstpierre (jkstpierre@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2020-07-31
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __MOGL_GLTYPE_HPP__
#define __MOGL_GLTYPE_HPP__

#include <mogl/platform.hpp>

namespace mogl
{
  /**
   * @brief An OOP enumeration for the internal OpenGL types
   * 
   */
  enum class GLtype : GLuint
  {
    _BYTE = GL_BYTE,
    _UNSIGNED_BYTE = GL_UNSIGNED_BYTE,
    _SHORT = GL_SHORT,
    _UNSIGNED_SHORT = GL_UNSIGNED_SHORT,
    _INT = GL_INT,
    _UNSIGNED_INT = GL_UNSIGNED_INT,
    _FLOAT = GL_FLOAT,
    _DOUBLE = GL_DOUBLE
  };
} // namespace mogl

#endif