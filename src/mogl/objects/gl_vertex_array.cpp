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
#include <stdexcept>

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

  const unsigned int &GLvertexArray::BindingPoint::getIndex() const noexcept
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

  GLvertexArray::BindingPoint::BindingPoint(const GLvertexArray &rVao, unsigned int index) noexcept
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

  void GLvertexArray::Attribute::enable() noexcept
  {
    glEnableVertexArrayAttrib(mVaoID, mIndex);
  }

  void GLvertexArray::Attribute::disable() noexcept
  {
    glDisableVertexArrayAttrib(mVaoID, mIndex);
  }

  void GLvertexArray::Attribute::setBindingPoint(const GLvertexArray::BindingPoint &rBindingPoint)
  {
    if (rBindingPoint.getVaoID() != mVaoID)
    {
      throw std::runtime_error("Cannot associate attributes and binding points for separate vertex arrays.");
    }

    mBindingPointIndex = rBindingPoint.getIndex();
    glVertexArrayAttribBinding(mVaoID, mIndex, mBindingPointIndex);
  }

  const GLuint &GLvertexArray::Attribute::getVaoID() const noexcept
  {
    return mVaoID;
  }

  const unsigned int &GLvertexArray::Attribute::getIndex() const noexcept
  {
    return mIndex;
  }

  const unsigned int &GLvertexArray::Attribute::getBindingPointIndex() const noexcept
  {
    return mBindingPointIndex;
  }

  GLuint GLvertexArray::Attribute::getSize() const noexcept
  {
    static GLint sSize;

    glGetVertexArrayIndexediv(mVaoID, mIndex, GL_VERTEX_ATTRIB_ARRAY_SIZE, &sSize);

    return static_cast<GLuint>(sSize);
  }

  GLtype GLvertexArray::Attribute::getType() const noexcept
  {
    static GLint sType;

    glGetVertexArrayIndexediv(mVaoID, mIndex, GL_VERTEX_ATTRIB_ARRAY_TYPE, &sType);

    return static_cast<GLtype>(sType);
  }

  GLuint GLvertexArray::Attribute::getRelativeOffset() const noexcept
  {
    static GLint sRelativeOffset;

    glGetVertexArrayIndexediv(mVaoID, mIndex, GL_VERTEX_ATTRIB_RELATIVE_OFFSET, &sRelativeOffset);

    return static_cast<GLuint>(sRelativeOffset);
  }

  GLboolean GLvertexArray::Attribute::isEnabled() const noexcept
  {
    static GLint sEnabled;

    glGetVertexArrayIndexediv(mVaoID, mIndex, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &sEnabled);

    return static_cast<GLboolean>(sEnabled);
  }

  GLvertexArray::Attribute::Attribute(GLvertexArray &rVao, unsigned int index) noexcept
      : mVaoID(rVao.getID()), mIndex(index), mBindingPointIndex(GLVERTEXARRAY_BINDINGPOINT_DEFAULT_INDEX)
  {
    setBindingPoint(rVao.getBindingPoint(mBindingPointIndex));
  }

  // GLvertexArray

  GLvertexArray::BindingPoint &GLvertexArray::getBindingPoint(unsigned int index)
  {
    if (index >= mBindingPoints.size())
    {
      throw std::runtime_error("Binding point index out of bounds.");
    }

    return *mBindingPoints.at(index);
  }

  size_t GLvertexArray::getBindingPointsSize() const noexcept
  {
    return mBindingPoints.size();
  }

  GLvertexArray::Attribute &GLvertexArray::getAttribute(unsigned int index)
  {
    if (index >= mAttributes.size())
    {
      throw std::runtime_error("Attribute index out of bounds.");
    }

    return *mAttributes.at(index);
  }

  size_t GLvertexArray::getAttributesSize() const noexcept
  {
    return mAttributes.size();
  }

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