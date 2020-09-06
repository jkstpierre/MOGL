/**
 * @file  shader_program/program.hpp.
 *
 * Declares the program class
 */

#ifndef __MOGL_SHADER_PROGRAM_GL_PROGRAM_HPP__
#define __MOGL_SHADER_PROGRAM_GL_PROGRAM_HPP__

#include "mogl/object.hpp"
#include "mogl/shader_program/shader.hpp"
#include "mogl/shader_program/binary.hpp"
#include <vector>
#include <memory>
#include <unordered_set>
#include <stdexcept>

namespace mogl
{
/**
 * A fully linked GLSL program consisting of 1 or more compiled GLshaders. This class cannot be inherited..
 *
 * @author  jkstpierre
 * @date  9/2/2020
 */
class GLprogram final : public GLobject<GLprogram>, public GLbinary
{
  friend class GLcontext;
  friend class GLpipeline;
public:
  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  9/2/2020
   */
  ~GLprogram() noexcept;

public:
  /**
   * Sets uniform boolean
   *
   * @author  jkstpierre
   * @date  9/2/2020
   *
   * @param   name  The name.
   * @param   value The value.
   */
  void setUniformBoolean(const std::string& name, GLboolean value) noexcept;

  /**
   * Sets uniform int
   *
   * @author  jkstpierre
   * @date  9/2/2020
   *
   * @param   name  The name.
   * @param   value The value.
   */
  void setUniformInt(const std::string& name, GLint value) noexcept;

  /**
   * Sets uniform float
   *
   * @author  jkstpierre
   * @date  9/2/2020
   *
   * @param   name  The name.
   * @param   value The value.
   */
  void setUniformFloat(const std::string& name, GLfloat value) noexcept;

  /**
   * Sets uniform double
   *
   * @author  jkstpierre
   * @date  9/3/2020
   *
   * @param   name  The name.
   * @param   value The value.
   */
  void setUniformDouble(const std::string& name, GLdouble value) noexcept;

  /**
   * Sets uniform int array
   *
   * @author  jkstpierre
   * @date  9/2/2020
   *
   * @param   name    The name.
   * @param   size    The size.
   * @param   pValues The values.
   */
  void setUniformIntArray(const std::string& name, GLsizei size, const GLint* pValues) noexcept;

  /**
   * Sets uniform float array
   *
   * @author  jkstpierre
   * @date  9/2/2020
   *
   * @param   name    The name.
   * @param   size    The size.
   * @param   pValues The values.
   */
  void setUniformFloatArray(const std::string& name, GLsizei size, const GLfloat* pValues) noexcept;

  /**
   * Sets uniform double array
   *
   * @author  jkstpierre
   * @date  9/3/2020
   *
   * @param   name    The name.
   * @param   size    The size.
   * @param   pValues The values.
   */
  void setUniformDoubleArray(const std::string& name, GLsizei size, const GLdouble* pValues) noexcept;

  /**
   * Sets uniform vector 2
   *
   * @author  jkstpierre
   * @date  9/2/2020
   *
   * @param   name    The name.
   * @param   vector  The vector.
   */
  void setUniformVector2d(const std::string& name, const GLfloat* vector) noexcept;

  /**
   * Sets uniform vector 3
   *
   * @author  jkstpierre
   * @date  9/2/2020
   *
   * @param   name    The name.
   * @param   vector  The vector.
   */
  void setUniformVector3d(const std::string& name, const GLfloat* vector) noexcept;

  /**
   * Sets uniform vector 4
   *
   * @author  jkstpierre
   * @date  9/2/2020
   *
   * @param   name    The name.
   * @param   vector  The vector.
   */
  void setUniformVector4d(const std::string& name, const GLfloat* vector) noexcept;

  /**
   * Sets uniform matrix 2x 2
   *
   * @author  jkstpierre
   * @date  9/2/2020
   *
   * @param   name    The name.
   * @param   matrix  The matrix.
   */
  void setUniformMatrix2x2(const std::string& name, const GLfloat* matrix) noexcept;

  /**
   * Sets uniform matrix 3x 3
   *
   * @author  jkstpierre
   * @date  9/2/2020
   *
   * @param   name    The name.
   * @param   matrix  The matrix.
   */
  void setUniformMatrix3x3(const std::string& name, const GLfloat* matrix) noexcept;

  /**
   * Sets uniform matrix 4x 4
   *
   * @author  jkstpierre
   * @date  9/2/2020
   *
   * @param   name    The name.
   * @param   matrix  The matrix.
   */
  void setUniformMatrix4x4(const std::string& name, const GLfloat* matrix) noexcept;

  /**
   * Attribute index
   *
   * @author  jkstpierre
   * @date  9/2/2020
   *
   * @param   name  The name.
   *
   * @returns A GLint.
   */
  GLint getAttributeIndex(const std::string& name) const noexcept;

  /**
   * Uniform index
   *
   * @author  jkstpierre
   * @date  9/2/2020
   *
   * @param   name  The name.
   *
   * @returns A GLint.
   */
  GLint getUniformIndex(const std::string& name) const noexcept;

  /**
   * Number of active attributes
   *
   * @author  jkstpierre
   * @date  9/2/2020
   *
   * @returns The total number of active attributes.
   */
  GLint getActiveAttributeCount() const noexcept;

  /**
   * Number of active uniforms
   *
   * @author  jkstpierre
   * @date  9/2/2020
   *
   * @returns The total number of active uniforms.
   */
  GLint getActiveUniformCount() const noexcept;

  /**
   * Gets shader components
   *
   * @author  jkstpierre
   * @date  9/3/2020
   *
   * @returns The shader components.
   */
  const std::unordered_set<GLshaderType>& getShaderComponents() const noexcept;

  /**
   * Is separable
   *
   * @author  jkstpierre
   * @date  9/4/2020
   *
   * @returns A reference to a const GLboolean.
   */
  const GLboolean& isSeparable() const noexcept;

private:
  /**
   * Creates an empty GLprogram
   *
   * @author  jkstpierre
   * @date  9/3/2020
   *
   * @param   separable The separable.
   */
  GLprogram(GLboolean separable);

  /**
   * Construct a new GLprogram object from a list of shaders
   *
   * @author  jkstpierre
   * @date  9/3/2020
   *
   * @tparam  sArgs Type of the arguments.
   * @param   shader_0  The shader 0.
   * @param   shaders   Variable arguments providing [in,out] The shaders.
   */
  template <class... sArgs>
  GLprogram(GLboolean separable, const GLshader& shader_0, sArgs&&... shaders) : GLprogram(separable, shaders...)
  {
    linkShader(shader_0);
  }

private:
  /**
   * Links a shader
   *
   * @author  jkstpierre
   * @date  9/3/2020
   *
   * @param   shader  The shader.
   */
  void linkShader(const GLshader& shader);

  /**
   * Uses this GLprogram for the next draw calls
   *
   * @author  jkstpierre
   * @date  9/2/2020
   */
  void use() const noexcept override;

private:
  /** The set of shaders linked in this GLprogram */
  std::unordered_set<GLshaderType> mShaderComponents;

  /** Track if the program object can be used in a GLpipeline */
  GLboolean mSeparable;
};
}

#endif