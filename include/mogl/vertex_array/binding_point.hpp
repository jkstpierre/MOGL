/**
 * @file  vertex_array/binding_point.hpp.
 *
 * Declares the binding point class
 */

#ifndef __MOGL_VERTEX_ARRAY_GL_BINDING_POINT_HPP__
#define __MOGL_VERTEX_ARRAY_GL_BINDING_POINT_HPP__

#include "mogl/base/heap_protected.hpp"
#include "mogl/buffer/buffer.hpp"

namespace mogl
{
/**
 * A binding point. This class cannot be inherited..
 *
 * @author  jkstpierre
 * @date  8/29/2020
 */
class GLbindingPoint final : public HeapProtected<GLbindingPoint>
{
  friend class GLvertexArray;
public:
  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  8/31/2020
   */
  ~GLbindingPoint() noexcept;

public:
  /**
   * Gets vertex array identifier
   *
   * @author  jkstpierre
   * @date  8/31/2020
   *
   * @returns The vertex array identifier.
   */
  const GLuint& getVaoID() const noexcept;

  /**
   * Gets the index
   *
   * @author  jkstpierre
   * @date  8/31/2020
   *
   * @returns The index.
   */
  const GLuint& getIndex() const noexcept;

  /**
   * Sets a divisor
   *
   * @author  jkstpierre
   * @date  9/1/2020
   *
   * @param   divisor The divisor.
   */
  void setDivisor(GLuint divisor) noexcept;
  
  /**
   * Sets a buffer
   *
   * @tparam  T Generic type parameter.
   * @param   pBuffer The buffer.
   */
  template <class T>
  void setBuffer(const GLbuffer<T>* pBuffer) noexcept
  {
    glVertexArrayVertexBuffer(mcVaoID, mcIndex, pBuffer ? pBuffer->getID() : GL_NONE, 0, pBuffer ? sizeof(T) : 0);
  };

  /**
   * Wrapper for null buffer entries to setBuffer
   *
   * @author  jkstpierre
   * @date  9/1/2020
   *
   * @param   parameter1  The first parameter.
   */
  void setBuffer(nullptr_t);

  /**
   * Get the id number of the buffer currently bound to the binding point
   *
   * @author  jkstpierre
   * @date  9/1/2020
   *
   * @returns A GLuint.
   */
  GLuint getBufferID() const noexcept;

  /**
   * Gets the stride
   *
   * @author  jkstpierre
   * @date  9/1/2020
   *
   * @returns A GLuint.
   */
  GLuint getStride() const noexcept;

  /**
   * Gets the divisor
   *
   * @author  jkstpierre
   * @date  9/1/2020
   *
   * @returns A GLuint.
   */
  GLuint getDivisor() const noexcept;

private:
  /**
   * Constructor
   *
   * @author  jkstpierre
   * @date  8/31/2020
   *
   * @param   vaoID Identifier for the vao.
   * @param   index Zero-based index of the.
   */
  GLbindingPoint(GLuint vaoID, GLuint index);

private:
  /** Identifier for the vertex array */
  const GLuint mcVaoID;
  /** Zero-based index of the BindingPoint*/
  const GLuint mcIndex;
};
}

#endif