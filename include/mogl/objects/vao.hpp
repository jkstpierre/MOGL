/**
 * @file vao.hpp
 * @author jkstpierre (jkstpierre@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2020-07-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __MOGL_OBJECTS_VAO_HPP__
#define __MOGL_OBJECTS_VAO_HPP__

#include <mogl/base/object.hpp>

namespace mogl
{
  class ModernOpenGL;
}

namespace mogl::objects
{
  /**
   * @brief A VertexArrayObject stores the state of OpenGL BufferObjects in addition to their formats
   * 
   */
  class VertexArrayObject : public base::Object
  {
  public:
    /**
     * @brief A BindingPoint is a location for BufferObjects to attach to
     * 
     */
    class BindingPoint
    {

    private:
      const VertexArrayObject &mrVao;
    };

    /**
     * @brief An Attribute specifies the formatting of buffer data
     * 
     */
    class Attribute
    {
    public:
    private:
      const VertexArrayObject &mrVao; // The reference to the host vao
    };

  private:
    friend class mogl::ModernOpenGL; // Grant MOGL allocation rights

    VertexArrayObject();
    ~VertexArrayObject();

    /**
     * @brief Bind the VertexArrayObject for drawing
     * 
     */
    void bind() noexcept;

  private:
  };
} // namespace mogl::objects

#endif