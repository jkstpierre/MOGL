/**
 * @file  objects/object.cpp.
 *
 * Implements the object class
 */

#include "mogl/objects/object.hpp"

namespace mogl
{
const GLuint& Object::getID() const noexcept
{
  return mID;
}
}