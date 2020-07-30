/**
 * @file object.cpp
 * @author jkstpierre (jkstpierre@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2020-07-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <mogl/base/object.hpp>

namespace mogl::base
{
  const GLuint &Object::getID() const noexcept
  {
    return mID;
  }
} // namespace mogl::base