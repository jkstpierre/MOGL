/**
 * @file  shader_program/shader.hpp.
 *
 * Declares the shader class
 */

#ifndef __MOGL_SHADER_PROGRAM_GL_SHADER_HPP__
#define __MOGL_SHADER_PROGRAM_GL_SHADER_HPP__

#include "mogl/base/object.hpp"
#include "mogl/shader_program/shader_type.hpp"
#include <string>

namespace mogl
{
/**
 * A GLshader is a compiled glsl script. This class cannot be inherited..
 *
 * @author  jkstpierre
 * @date  9/2/2020
 */
class GLshader final : public GLobject<GLshader>
{
  friend class GLcontext;
public:
  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  9/2/2020
   */
  ~GLshader() noexcept;

public:
  /**
   * Gets the type
   *
   * @author  jkstpierre
   * @date  9/2/2020
   *
   * @returns The type.
   */
  const GLshaderType& getType() const noexcept;

private:
  /**
   * Constructor
   *
   * @author  jkstpierre
   * @date  9/2/2020
   *
   * @param   type  The type.
   * @param   src   Source for the.
   */
  GLshader(GLshaderType type, const std::string& src);

private:
  /** The type of GLshader */
  GLshaderType mType;
};
}

#endif