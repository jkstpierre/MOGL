/**
 * @file  mogl/context.cpp.
 *
 * Implements the context class
 */

#include "mogl/context.hpp"
#include <string>

namespace mogl
{
/** There is no active context by default */
bool GLcontext::sActive = false;

void GLcontext::setViewport(const std::array<GLint, 4>& viewport) noexcept
{
  mViewport = viewport;
}

const std::array<GLint, 4>& GLcontext::getViewport() const noexcept
{
  return mViewport;
}

void GLcontext::setActiveBinary(const GLbinary& binary) noexcept
{
  binary.use();
}

GLtextureUnit& GLcontext::textureUnit(GLuint index)
{
  if ( index >= mTextureUnits.size() )
  {
    throw std::runtime_error("No GLtextureUnit at index " + std::to_string(index) + ".");
  }

  return *mTextureUnits.at(index);
}

void GLcontext::clearTextureUnits() noexcept
{
  for ( auto&& texUnit : mTextureUnits )
  {
    texUnit->bindSampler(nullptr);
    texUnit->bindTexture(nullptr);
  }
}

GLuint GLcontext::getTextureUnitCount() const noexcept
{
  static GLint textureUnits;
  glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &textureUnits);
  return static_cast<GLuint>(textureUnits);
}

void GLcontext::clear(GLfloat r, GLfloat g, GLfloat b, GLfloat a) const noexcept
{
  glClearColor(r, g, b, a);
  glClear(GL_COLOR_BUFFER_BIT);
}

void GLcontext::drawArrays(const GLvertexArray& vao, GLdrawMode mode, GLint first, GLsizei count) const noexcept
{
  vao.bind();

  // Draw the arrays from the vao
  glDrawArrays(static_cast<GLenum>(mode), first, count);
}

void GLcontext::drawElements(const GLvertexArray& vao, GLdrawMode mode, GLsizei count) const noexcept
{
  vao.bind();

  // Draw the elements from the vao
  glDrawElements(static_cast<GLenum>(mode), count, GL_UNSIGNED_INT, nullptr);
}
}