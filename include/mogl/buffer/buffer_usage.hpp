/**
 * @file  buffer/buffer_usage.hpp.
 *
 * Declares the buffer usage class
 */

#ifndef __MOGL_BUFFER_BUFFER_GL_USAGE_HPP__
#define __MOGL_BUFFER_BUFFER_GL_USAGE_HPP__

#include "mogl/platform.hpp"

namespace mogl
{
/** Values that represent buffer usages */
enum class GLbufferUsage : GLenum
{
  _STREAM_DRAW = GL_STREAM_DRAW,
  _STREAM_READ = GL_STREAM_READ,
  _STREAM_COPY = GL_STREAM_COPY,
  _STATIC_DRAW = GL_STATIC_DRAW,
  _STATIC_READ = GL_STATIC_READ,
  _STATIC_COPY = GL_STATIC_COPY,
  _DYNAMIC_DRAW = GL_DYNAMIC_DRAW,
  _DYNAMIC_READ = GL_DYNAMIC_READ,
  _DYNAMIC_COPY = GL_DYNAMIC_COPY
};
}

#endif