/**
 * @file gl_vertex_array.cpp
 * @author jkstpierre (jkstpierre@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2020-07-31
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <mogl/objects/gl_vertex_array.hpp>

namespace mogl::objects
{
  // GLvertexArray::BindingPoint

  void GLvertexArray::BindingPoint::attachBuffer(nullptr_t) noexcept
  {
    attachBuffer<nullptr_t>(nullptr);
  }

  void GLvertexArray::BindingPoint::setDivisor(GLuint divisor) noexcept
  {
    glVertexArrayBindingDivisor(mVaoID, mIndex, divisor);
  }

  const GLuint &GLvertexArray::BindingPoint::getVaoID() const noexcept
  {
    return mVaoID;
  }

  const GLuint &GLvertexArray::BindingPoint::getIndex() const noexcept
  {
    return mIndex;
  }

  GLuint GLvertexArray::BindingPoint::getBufferID() const noexcept
  {
    static GLint sBuffer;

    glGetVertexArrayIndexediv(mVaoID, mIndex, GL_VERTEX_BINDING_BUFFER, &sBuffer);

    return static_cast<GLuint>(sBuffer);
  }

  GLuint GLvertexArray::BindingPoint::getStride() const noexcept
  {
    static GLint sStride;

    glGetVertexArrayIndexediv(mVaoID, mIndex, GL_VERTEX_BINDING_STRIDE, &sStride);

    return static_cast<GLuint>(sStride);
  }

  GLuint GLvertexArray::BindingPoint::getDivisor() const noexcept
  {
    static GLint sDivisor;

    glGetVertexArrayIndexediv(mVaoID, mIndex, GL_VERTEX_BINDING_DIVISOR, &sDivisor);

    return static_cast<GLuint>(sDivisor);
  }

  GLvertexArray::BindingPoint::BindingPoint(const GLvertexArray &rVao, GLuint index) noexcept
      : mVaoID(rVao.getID()), mIndex(index)
  {
    setDivisor(0);
    attachBuffer(nullptr);
  }

  GLvertexArray::BindingPoint::~BindingPoint() noexcept
  {
    setDivisor(0);
    attachBuffer(nullptr);
  }

  // GLvertexArray::Attribute

  void GLvertexArray::Attribute::format(GLuint size, GLtype type, GLboolean normalized, GLuint relativeOffset) noexcept
  {
    if (type == GLtype::_FLOAT)
    {
      // Format floating point attributes
      glVertexArrayAttribFormat(mVaoID, mIndex, size, static_cast<GLenum>(type), normalized, relativeOffset);
    }
    else if (type == GLtype::_DOUBLE)
    {
      // Format double precision floating point attributes
      glVertexArrayAttribLFormat(mVaoID, mIndex, size, static_cast<GLenum>(type), relativeOffset);
    }
    else
    {
      // Format integer attributes
      glVertexArrayAttribIFormat(mVaoID, mIndex, size, static_cast<GLenum>(type), relativeOffset);
    }
  }

  // GLvertexArray

  GLvertexArray::GLvertexArray()
  {
    glCreateVertexArrays(1, &mID);
  }

  GLvertexArray::~GLvertexArray()
  {
    glDeleteVertexArrays(1, &mID);
  }

  void GLvertexArray::bind() noexcept
  {
    glBindVertexArray(mID);
  }
} // namespace mogl::objects