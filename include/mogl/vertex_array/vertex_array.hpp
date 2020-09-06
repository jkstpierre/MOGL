/**
 * @file  vertex_array/vertex_array.hpp.
 *
 * Declares the vertex array class
 */

#ifndef __MOGL_VERTEX_ARRAY_GL_VERTEX_ARRAY_HPP__
#define __MOGL_VERTEX_ARRAY_GL_VERTEX_ARRAY_HPP__

#include "mogl//object.hpp"
#include "mogl/buffer/buffer.hpp"
#include "mogl/vertex_array/attribute.hpp"
#include "mogl/vertex_array/binding_point.hpp"
#include <vector>
#include <memory>

namespace mogl
{
/**
 * A VertexArray is used for saving the state of associated VertexBuffers for use during draw calls.
 *
 * @author  jkstpierre
 * @date  8/29/2020
 */
class GLvertexArray final : public GLobject<GLvertexArray>
{
  friend class GLcontext; // Allow GLcontext to instantiate
public:
  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  8/30/2020
   */
  ~GLvertexArray() noexcept;

public:
  /**
   * Binds this VertexArray object for the next draw call
   *
   * @author  jkstpierre
   * @date  8/30/2020
   */
  void bind() const noexcept;

  /**
   * Sets element buffer
   *
   * @author  jkstpierre
   * @date  8/30/2020
   *
   * @param   ebo The ebo.
   */
  void setElementBuffer(const GLbuffer<GLuint>* ebo) noexcept;

  /**
   * Gets an attribute
   *
   * @author  jkstpierre
   * @date  8/31/2020
   *
   * @param   index Zero-based index of the.
   *
   * @returns Null if it fails, else the attribute.
   */
  GLattribute& attribute(GLuint index);

  /**
   * Gets binding point
   *
   * @author  jkstpierre
   * @date  8/31/2020
   *
   * @param   index Zero-based index of the.
   *
   * @returns Null if it fails, else the binding point.
   */
  GLbindingPoint& bindingPoint(GLuint index);

  /**
   * Number of attributes
   *
   * @author  jkstpierre
   * @date  9/1/2020
   *
   * @returns The total number of attributes.
   */
  GLuint getAttributeCount() const noexcept;

  /**
   * Number of binding points
   *
   * @author  jkstpierre
   * @date  9/1/2020
   *
   * @returns The total number of binding points.
   */
  GLuint getBindingPointCount() const noexcept;

private:
  /**
   * Default constructor
   *
   * @author  jkstpierre
   * @date  8/30/2020
   */
  GLvertexArray();

private:
  /** The attributes */
  std::vector<std::unique_ptr<GLattribute, GLattribute::Deleter>> mAttributes;
  /** The binding points */
  std::vector<std::unique_ptr<GLbindingPoint, GLbindingPoint::Deleter>> mBindingPoints;
};
}

#endif