/**
 * @file  gl/type.hpp.
 *
 * Declares the type class
 * 
 */

#ifndef __MOGL_GL_TYPE_HPP__
#define __MOGL_GL_TYPE_HPP__

#include "mogl/platform.hpp"

namespace mogl
{
/** Values that represent types */
enum class GLtype : GLenum
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
}

#endif