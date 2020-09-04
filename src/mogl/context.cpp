/**
 * @file  mogl/context.cpp.
 *
 * Implements the context class
 */

#include "mogl/context.hpp"

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

void GLcontext::drawArrays(const GLvertexArray& vao, const GLbinary& binary, GLdrawMode mode, GLint first, GLsizei count) const noexcept
{
  // Use the program binary
  binary.use();

  // Bind the vao to draw
  vao.bind();

  glDrawArrays(static_cast<GLenum>(mode), first, count);
}

void GLcontext::drawElements(const GLvertexArray& vao, const GLbinary& binary, GLdrawMode mode, GLsizei count) const noexcept
{
  binary.use();
  vao.bind();

  // Draw the elements from the vao
  glDrawElements(static_cast<GLenum>(mode), count, GL_UNSIGNED_INT, nullptr);
}


}