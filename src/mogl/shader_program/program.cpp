/**
 * @file  shader_program/program.cpp.
 *
 * Implements the program class
 */

#include "mogl/shader_program/program.hpp"

namespace mogl
{
GLprogram::GLprogram()
{
  mID = glCreateProgram();
  if ( mID )
  {
    glProgramParameteri(mID, GL_PROGRAM_SEPARABLE, GL_TRUE);
  }
  else
  {
    throw std::runtime_error("Failed to create GLprogram.");
  }
}

GLprogram::~GLprogram() noexcept
{
  glDeleteProgram(mID);
}

void GLprogram::linkShader(const GLshader& shader)
{
  // Make sure we do not have duplicate shaders
  if ( mShaderComponents.find(shader.getType()) == mShaderComponents.end() )
  {
    // Attach the shader and iteratively link it to the program
    glAttachShader(mID, shader.getID());
    glLinkProgram(mID);

    // Check linkage status
    static const GLuint ERROR_LOG_SIZE = 512U;
    static GLchar errorLog[ERROR_LOG_SIZE];
    static GLint success;
    glGetProgramiv(mID, GL_LINK_STATUS, &success);
    if ( !success )
    {
      glGetProgramInfoLog(mID, ERROR_LOG_SIZE, nullptr, errorLog);
      glDeleteProgram(mID);
      throw std::runtime_error("GLprogram failed to link. GLSL Error: " + std::string(errorLog));
    }

    // Validate the program
    glValidateProgram(mID);
    glGetProgramiv(mID, GL_VALIDATE_STATUS, &success);
    if ( !success )
    {
      glGetProgramInfoLog(mID, ERROR_LOG_SIZE, nullptr, errorLog);
      glDeleteProgram(mID);
      throw std::runtime_error("GLprogram failed to validate. OpenGL Error: " + std::string(errorLog));
    }

    mShaderComponents.insert(shader.getType()); // Remember the shader type
  }
  else
  {
    throw std::runtime_error("GLprogram cannot link two shaders of the same type.");
  }
}

void GLprogram::use() const noexcept
{
  if ( !isActive() )
  {
    glUseProgram(mID);
    scpActiveBinary = this; // Track this binary as active
  }
}

void GLprogram::setUniformBoolean(const std::string& name, GLboolean value) noexcept
{
  glProgramUniform1ui(mID, uniformIndex(name), value);
}

void GLprogram::setUniformInt(const std::string& name, GLint value) noexcept
{
  glProgramUniform1i(mID, uniformIndex(name), value);
}

void GLprogram::setUniformFloat(const std::string& name, GLfloat value) noexcept
{
  glProgramUniform1f(mID, uniformIndex(name), value);
}

void GLprogram::setUniformDouble(const std::string& name, GLdouble value) noexcept
{
  glProgramUniform1d(mID, uniformIndex(name), value);
}

void GLprogram::setUniformIntArray(const std::string& name, GLsizei size, const GLint* pValues) noexcept
{
  glProgramUniform1iv(mID, uniformIndex(name), size, pValues);
}

void GLprogram::setUniformFloatArray(const std::string& name, GLsizei size, const GLfloat* pValues) noexcept
{
  glProgramUniform1fv(mID, uniformIndex(name), size, pValues);
}

void GLprogram::setUniformDoubleArray(const std::string& name, GLsizei size, const GLdouble* pValues) noexcept
{
  glProgramUniform1dv(mID, uniformIndex(name), size, pValues);
}

void GLprogram::setUniformVector2d(const std::string& name, const GLfloat* vector) noexcept
{
  glProgramUniform2fv(mID, uniformIndex(name), 1, vector);
}

void GLprogram::setUniformVector3d(const std::string& name, const GLfloat* vector) noexcept
{
  glProgramUniform3fv(mID, uniformIndex(name), 1, vector);
}

void GLprogram::setUniformVector4d(const std::string& name, const GLfloat* vector) noexcept
{
  glProgramUniform4fv(mID, uniformIndex(name), 1, vector);
}

void GLprogram::setUniformMatrix2x2(const std::string& name, const GLfloat* matrix) noexcept
{
  glProgramUniformMatrix2fv(mID, uniformIndex(name), 1, GL_FALSE, matrix);
}

void GLprogram::setUniformMatrix3x3(const std::string& name, const GLfloat* matrix) noexcept
{
  glProgramUniformMatrix3fv(mID, uniformIndex(name), 1, GL_FALSE, matrix);
}

void GLprogram::setUniformMatrix4x4(const std::string& name, const GLfloat* matrix) noexcept
{
  glProgramUniformMatrix4fv(mID, uniformIndex(name), 1, GL_FALSE, matrix);
}

GLint GLprogram::attributeIndex(const std::string& name) const noexcept
{
  return glGetAttribLocation(mID, name.c_str());
}

GLint GLprogram::uniformIndex(const std::string& name) const noexcept
{
  return glGetUniformLocation(mID, name.c_str());
}

GLint GLprogram::numberOfActiveAttributes() const noexcept
{
  static GLint attributes = 0;
  glGetProgramInterfaceiv(mID, GL_PROGRAM_INPUT, GL_ACTIVE_RESOURCES, &attributes);
  return attributes;
}

GLint GLprogram::numberOfActiveUniforms() const noexcept
{
  static GLint uniforms = 0;
  glGetProgramInterfaceiv(mID, GL_UNIFORM, GL_ACTIVE_RESOURCES, &uniforms);
  return uniforms;
}

const std::unordered_set<GLshaderType>& GLprogram::getShaderComponents() const noexcept
{
  return mShaderComponents;
}
}