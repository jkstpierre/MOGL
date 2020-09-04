/**
 * @file  vertex_array/attribute.cpp.
 *
 * Implements the attribute class
 */

#include "mogl/vertex_array/attribute.hpp"
#include <stdexcept>

namespace mogl
{
GLattribute::GLattribute(GLuint vaoID, GLuint index, const GLbindingPoint& bindingPoint)
  : mcVaoID(vaoID), mcIndex(index), mBindingPointIndex(bindingPoint.getIndex())
{
  setBindingPoint(bindingPoint);  // Set initial binding point
}

GLattribute::~GLattribute() noexcept
{}

void GLattribute::format(GLint size, GLtype type, GLboolean normalize, GLuint relativeOffset) noexcept
{
  if ( type == GLtype::_FLOAT )
  {
    // Format single precision float attributes
    glVertexArrayAttribFormat(mcVaoID, mcIndex, size, static_cast<GLenum>(type), normalize, relativeOffset);
  }
  else if ( type == GLtype::_DOUBLE )
  {
    // Format double precision float attributes
    glVertexArrayAttribLFormat(mcVaoID, mcIndex, size, static_cast<GLenum>(type), relativeOffset);
  }
  else
  {
    // Format integer attributes
    glVertexArrayAttribIFormat(mcVaoID, mcIndex, size, static_cast<GLenum>(type), relativeOffset);
  }
}

void GLattribute::enable() noexcept
{
  glEnableVertexArrayAttrib(mcVaoID, mcIndex);
}

void GLattribute::disable() noexcept
{
  glDisableVertexArrayAttrib(mcVaoID, mcIndex);
}

void GLattribute::setBindingPoint(const GLbindingPoint& bindingPoint)
{
  if ( mcVaoID != bindingPoint.getVaoID() )
  {
    throw std::runtime_error("Cannot bind attribute to another vertex array's binding point.");
  }

  mBindingPointIndex = bindingPoint.getIndex();
  glVertexArrayAttribBinding(mcVaoID, mcIndex, mBindingPointIndex);
}

const GLuint& GLattribute::getVaoID() const noexcept
{
  return mcVaoID;
}

const GLuint& GLattribute::getIndex() const noexcept
{
  return mcIndex;
}

const GLuint& GLattribute::getBindingPointIndex() const noexcept
{
  return mBindingPointIndex;
}

GLuint GLattribute::size() const noexcept
{
  static GLint size;

  glGetVertexArrayIndexediv(mcVaoID, mcIndex, GL_VERTEX_ATTRIB_ARRAY_SIZE, &size);

  return static_cast<GLuint>(size);
}

GLtype GLattribute::type() const noexcept
{
  static GLint type;

  glGetVertexArrayIndexediv(mcVaoID, mcIndex, GL_VERTEX_ATTRIB_ARRAY_TYPE, &type);

  return static_cast<GLtype>(type);
}

GLuint GLattribute::relativeOffset() const noexcept
{
  static GLint relativeOffset;

  glGetVertexArrayIndexediv(mcVaoID, mcIndex, GL_VERTEX_ATTRIB_RELATIVE_OFFSET, &relativeOffset);

  return static_cast<GLuint>(relativeOffset);
}

GLboolean GLattribute::isEnabled() const noexcept
{
  static GLint enabled;

  glGetVertexArrayIndexediv(mcVaoID, mcIndex, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &enabled);

  return static_cast<GLboolean>(enabled);
}
}