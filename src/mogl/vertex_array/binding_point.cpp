/**
 * @file  vertex_array/binding_point.cpp.
 *
 * Implements the binding point class
 */

#include "mogl/vertex_array/binding_point.hpp"

namespace mogl
{
GLbindingPoint::GLbindingPoint(GLuint vaoID, GLuint index) : mcVaoID(vaoID), mcIndex(index)
{
  setDivisor(0);
  setBuffer(nullptr);
}

GLbindingPoint::~GLbindingPoint() noexcept
{}

const GLuint& GLbindingPoint::getVaoID() const noexcept
{
  return mcVaoID;
}

const GLuint& GLbindingPoint::getIndex() const noexcept
{
  return mcIndex;
}

void GLbindingPoint::setDivisor(GLuint divisor) noexcept
{
  glVertexArrayBindingDivisor(mcVaoID, mcIndex, divisor);
}

void GLbindingPoint::setBuffer(nullptr_t)
{
  setBuffer<nullptr_t>(nullptr);
}

GLuint GLbindingPoint::getBufferID() const noexcept
{
  static GLint buffer;

  glGetVertexArrayIndexediv(mcVaoID, mcIndex, GL_VERTEX_BINDING_BUFFER, &buffer);

  return static_cast<GLuint>(buffer);
}

GLuint GLbindingPoint::getStride() const noexcept
{
  static GLint stride;

  glGetVertexArrayIndexediv(mcVaoID, mcIndex, GL_VERTEX_BINDING_STRIDE, &stride);

  return static_cast<GLuint>(stride);
}

GLuint GLbindingPoint::getDivisor() const noexcept
{
  static GLint divisor;

  glGetVertexArrayIndexediv(mcVaoID, mcIndex, GL_VERTEX_BINDING_DIVISOR, &divisor);

  return static_cast<GLuint>(divisor);
}
}