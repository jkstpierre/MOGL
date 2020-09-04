/**
 * @file  buffer/buffer_access.hpp.
 *
 * Declares the buffer access class
 */

#ifndef __MOGL_BUFFER_GL_BUFFER_ACCESS_HPP__
#define __MOGL_BUFFER_GL_BUFFER_ACCESS_HPP__

#include "mogl/platform.hpp"

namespace mogl
{
/** Values that represent buffer access */
enum class GLbufferAccess : GLenum
{
  _READ_ONLY = GL_READ_ONLY,
  _WRITE_ONLY = GL_WRITE_ONLY,
  _READ_WRITE = GL_READ_WRITE
};
}

#endif