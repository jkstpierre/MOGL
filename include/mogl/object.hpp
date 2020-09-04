/**
 * @file  mogl/object.hpp.
 *
 * Declares the object class
 */

#ifndef __MOGL_GL_OBJECT_HPP__
#define __MOGL_GL_OBJECT_HPP__

#include "mogl/platform.hpp"
#include "mogl/heap_protected.hpp"

namespace mogl
{
/**
 * An abstract base class for all OpenGL objects.
 *
 * @author  jkstpierre
 * @date  8/29/2020
 */
template <class T>
class GLobject : public HeapProtected<T>
{
public:
  /**
   * Gets the identifier
   *
   * @author  jkstpierre
   * @date  8/29/2020
   *
   * @returns The identifier.
   */
  const GLuint& getID() const noexcept
  {
    return mID;
  }

protected:
  /**
   * Constructor
   *
   * @author  jkstpierre
   * @date  8/29/2020
   *
   * @param [in,out]  parameter1  The first parameter.
   */
  GLobject() = default;

  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  8/29/2020
   */
  virtual ~GLobject() noexcept = default;

protected:
  /** The id number of this Object. GL_NONE if there's no id */
  GLuint mID = GL_NONE;
};
}

#endif