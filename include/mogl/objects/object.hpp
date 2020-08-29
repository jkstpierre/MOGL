/**
 * @file  objects/object.hpp.
 *
 * Declares the object class
 */

#ifndef __MOGL_OBJECTS_OBJECT_HPP__
#define __MOGL_OBJECTS_OBJECT_HPP__

#include "mogl/loaders.hpp"

namespace mogl
{
/**
 * An abstract base class for all OpenGL objects.
 *
 * @author  jkstpierre
 * @date  8/29/2020
 */
class Object
{
  friend class Allocator; // Grant allocator allocation rights
public:
  /**
   * Gets the identifier
   *
   * @author  jkstpierre
   * @date  8/29/2020
   *
   * @returns The identifier.
   */
  const GLuint& getID() const noexcept;

protected:
  /**
   * Constructor
   *
   * @author  jkstpierre
   * @date  8/29/2020
   *
   * @param [in,out]  parameter1  The first parameter.
   */
  Object() = default;

  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  8/29/2020
   */
  virtual ~Object() noexcept = default;

private:
  /** The id number of this Object. GL_NONE if there's no id */
  GLuint mID = GL_NONE;
};
}

#endif