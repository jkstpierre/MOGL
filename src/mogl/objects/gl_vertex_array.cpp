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

namespace mogl::objects
{
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