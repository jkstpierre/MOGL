/**
 * @file  vertex_array/attribute.hpp.
 *
 * Declares the attribute class
 */

#ifndef __MOGL_VERTEX_ARRAY_GL_ATTRIBUTE_HPP__
#define __MOGL_VERTEX_ARRAY_GL_ATTRIBUTE_HPP__

#include "mogl/heap_protected.hpp"
#include "mogl/platform.hpp"
#include "mogl/vertex_array/binding_point.hpp"
#include "mogl/type.hpp"


namespace mogl
{
/**
 * An attribute. This class cannot be inherited..
 *
 * @author  jkstpierre
 * @date  8/29/2020
 */
class GLattribute final : public HeapProtected<GLattribute>
{
  friend class GLvertexArray;
public:
  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  8/31/2020
   */
  ~GLattribute() noexcept;

public:
  /**
   * Formats the attribute
   *
   * @author  jkstpierre
   * @date  8/31/2020
   *
   * @param   size            The size.
   * @param   type            The type.
   * @param   normalize       Have OpenGL normalize the data for this attribute. (Note: Only applicable for GLtype::_FLOAT)
   * @param   relativeOffset  The relative offset.
   */
  void format(GLint size, GLtype type, GLboolean normalize, GLuint relativeOffset) noexcept;

  /**
   * Enables this 
   *
   * @author  jkstpierre
   * @date  8/31/2020
   */
  void enable() noexcept;

  /**
   * Disables this 
   *
   * @author  jkstpierre
   * @date  8/31/2020
   */
  void disable() noexcept;

  /**
   * Sets binding point
   *
   * @author  jkstpierre
   * @date  8/31/2020
   *
   * @param   bindingPoint  The binding point.
   */
  void setBindingPoint(const GLbindingPoint& bindingPoint);

  /**
   * Gets vao identifier
   *
   * @author  jkstpierre
   * @date  8/31/2020
   *
   * @returns The vao identifier.
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
   * Gets binding point index
   *
   * @author  jkstpierre
   * @date  8/31/2020
   *
   * @returns The binding point index.
   */
  const GLuint& getBindingPointIndex() const noexcept;

  /**
   * Gets the size
   *
   * @author  jkstpierre
   * @date  8/31/2020
   *
   * @returns A GLuint.
   */
  GLuint getSize() const noexcept;

  /**
   * Gets the type
   *
   * @author  jkstpierre
   * @date  8/31/2020
   *
   * @returns A Type.
   */
  GLtype getType() const noexcept;

  /**
   * Relative offset
   *
   * @author  jkstpierre
   * @date  8/31/2020
   *
   * @returns A GLuint.
   */
  GLuint getRelativeOffset() const noexcept;

  /**
   * Is enabled
   *
   * @author  jkstpierre
   * @date  8/31/2020
   *
   * @returns A GLboolean.
   */
  GLboolean isEnabled() const noexcept;

private:
  /**
   * Constructor
   *
   * @author  jkstpierre
   * @date  8/31/2020
   *
   * @param   vaoID         Identifier for the vao.
   * @param   index         Zero-based index of the.
   * @param   bindingPoint  The default binding point for this Attribute
   */
  GLattribute(GLuint vaoID, GLuint index, const GLbindingPoint& bindingPoint);

private:
  /** Identifier for the mc vertex array */
  const GLuint mcVaoID;
  /** Zero-based index of the mc */
  const GLuint mcIndex;
  /** Zero-based index of the mc binding point */
  GLuint mBindingPointIndex;
};
}

#endif