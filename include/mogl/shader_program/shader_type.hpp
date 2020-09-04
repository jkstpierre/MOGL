/**
 * @file  shader_program/shader_type.hpp.
 *
 * Declares the shader type class
 */

#ifndef __MOGL_SHADER_PROGRAM_GL_SHADER_TYPE_HPP__
#define __MOGL_SHADER_PROGRAM_GL_SHADER_TYPE_HPP__

#include "mogl/platform.hpp"

namespace mogl
{
/** Values that represent GLshader types */
enum class GLshaderType : GLuint
{
  _VERTEX = GL_VERTEX_SHADER,
  _TESS_CONTROL = GL_TESS_CONTROL_SHADER,
  _TESS_EVALUATION = GL_TESS_EVALUATION_SHADER,
  _GEOMETRY = GL_GEOMETRY_SHADER,
  _FRAGMENT = GL_FRAGMENT_SHADER
};
}

#endif