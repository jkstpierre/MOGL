/**
 * @file  shader_program/shader.cpp.
 *
 * Implements the shader class
 */

#include "mogl/shader_program/shader.hpp"
#include <stdexcept>

namespace mogl
{
GLshader::GLshader(GLshaderType type, const std::string& src) : mType(type)
{
  mID = glCreateShader(static_cast<GLenum>(type));
  if ( mID )
  {
    // If shader creation was successful, compile the shader
    auto pSrc = src.c_str();
    glShaderSource(mID, 1, &pSrc, nullptr);
    glCompileShader(mID);

    // Check for errors
    static const GLuint ERROR_LOG_SIZE = 512U;
    static GLchar errorLog[ERROR_LOG_SIZE];
    static GLint success;
    glGetShaderiv(mID, GL_COMPILE_STATUS, &success);

    if ( !success )
    {
      glGetShaderInfoLog(mID, ERROR_LOG_SIZE, nullptr, errorLog);
      glDeleteShader(mID);
      throw std::runtime_error("GLshader failed to compile. GLSL Error: " + std::string(errorLog));
    }
  }
  else
  {
    throw std::runtime_error("Failed to create GLshader.");
  }
}

GLshader::~GLshader() noexcept
{
  glDeleteShader(mID);
}

const GLshaderType& GLshader::getType() const noexcept
{
  return mType;
}
}