/**
 * @file  mogl/draw_mode.hpp.
 *
 * Declares the draw mode class
 */

#ifndef __MOGL_GL_DRAW_MODE_HPP__
#define __MOGL_GL_DRAW_MODE_HPP__

#include "mogl/platform.hpp"

namespace mogl
{
/** Values that represent draw modes */
enum class GLdrawMode : GLenum
{
  _POINTS = GL_POINTS,
  _LINE_STRIP = GL_LINE_STRIP,
  _LINE_LOOP = GL_LINE_LOOP,
  _LINES = GL_LINES,
  _LINE_STRIP_ADJACENCY = GL_LINE_STRIP_ADJACENCY,
  _LINES_ADJACENCY = GL_LINES_ADJACENCY,
  _TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
  _TRIANGLE_FAN = GL_TRIANGLE_FAN,
  _TRIANGLES = GL_TRIANGLES,
  _TRIANGLE_STRIP_ADJACENCY = GL_TRIANGLE_STRIP_ADJACENCY,
  _TRIANGLES_ADJACENCY = GL_TRIANGLES_ADJACENCY,
  _PATCHES = GL_PATCHES
};
}

#endif