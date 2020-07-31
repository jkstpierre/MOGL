/**
 * @file gl_object.cpp
 * @author jkstpierre (jkstpierre@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2020-07-31
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <mogl/base/gl_object.hpp>

namespace mogl::base
{
  const GLuint &GLobject::getID() const noexcept
  {
    return mID;
  }
} // namespace mogl::base