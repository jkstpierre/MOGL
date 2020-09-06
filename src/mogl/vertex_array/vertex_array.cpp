/**
 * @file  vertex_array/vertex_array.cpp.
 *
 * Implements the vertex array class
 */

#include "mogl/vertex_array/vertex_array.hpp"
#include <stdexcept>

namespace mogl
{
GLvertexArray::GLvertexArray()
{
  glCreateVertexArrays(1, &mID);
  if ( mID )
  {
    // Initialize binding points
    GLuint bindingPoints = getBindingPointCount();
    for ( GLuint i = 0; i < bindingPoints; i++ )
    {
      mBindingPoints.emplace_back(new GLbindingPoint(mID, i), GLbindingPoint::Deleter());
    }

    // Initialize attributes
    GLuint attributes = getAttributeCount();
    for ( GLuint i = 0; i < attributes; i++ )
    {
      mAttributes.emplace_back(new GLattribute(mID, i, *mBindingPoints.front()), GLattribute::Deleter());
    }
  }
  else
  {
    throw std::runtime_error("Failed to create GLvertexArray.");
  }
}

GLvertexArray::~GLvertexArray()
{
  // Delete attributes
  mAttributes.clear();

  // Delete binding points
  mBindingPoints.clear();

  glDeleteVertexArrays(1, &mID);
}

void GLvertexArray::bind() const noexcept
{
  glBindVertexArray(mID);
}

void GLvertexArray::setElementBuffer(const GLbuffer<GLuint>* ebo) noexcept
{
  glVertexArrayElementBuffer(mID, ebo ? ebo->getID() : GL_NONE);
}

GLattribute& GLvertexArray::attribute(GLuint index)
{
  if ( index >= mAttributes.size() )
  {
    throw std::runtime_error("Invalid attribute index.");
  }

  return *mAttributes.at(index);
}

GLbindingPoint& GLvertexArray::bindingPoint(GLuint index)
{
  if ( index >= mBindingPoints.size() )
  {
    throw std::runtime_error("Invalid binding point index.");
  }

  return *mBindingPoints.at(index);
}

GLuint GLvertexArray::getAttributeCount() const noexcept
{
  static GLint attributes;

  glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &attributes);

  return static_cast<GLuint>(attributes);
}

GLuint GLvertexArray::getBindingPointCount() const noexcept
{
  static GLint bindingPoints;

  glGetIntegerv(GL_MAX_VERTEX_ATTRIB_BINDINGS, &bindingPoints);

  return static_cast<GLuint>(bindingPoints);
}
}