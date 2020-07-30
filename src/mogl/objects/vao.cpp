/**
 * @file vao.cpp
 * @author jkstpierre (jkstpierre@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2020-07-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <mogl/objects/vao.hpp>

namespace mogl::objects
{
  VertexArrayObject::VertexArrayObject()
  {
    glCreateVertexArrays(1, &mID);
  }

  VertexArrayObject::~VertexArrayObject()
  {
    glDeleteVertexArrays(1, &mID);
  }

  void VertexArrayObject::bind() noexcept
  {
    glBindVertexArray(mID);
  }
} // namespace mogl::objects