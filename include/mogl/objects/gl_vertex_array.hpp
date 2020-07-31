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

#ifndef __MOGL_OBJECTS_GLVERTEXARRAY_HPP__
#define __MOGL_OBJECTS_GLVERTEXARRAY_HPP__

#include <mogl/objects/gl_buffer.hpp>
#include <mogl/gl_type.hpp>

namespace mogl
{
  class ModernOpenGL;
}

namespace mogl::objects
{
  /**
   * @brief A GLvertexArray stores the state of OpenGL BufferObjects in addition to their formats
   * 
   */
  class GLvertexArray : public base::GLobject
  {
  public:
    /**
     * @brief A GLbindingPoint is a location for BufferObjects to attach to
     * 
     */
    class GLbindingPoint
    {
    public:
      /**
       * @brief Set the Divisor object
       * 
       * @param divisor 
       */
      void setDivisor(const GLuint &divisor) noexcept;

      /**
       * @brief Attach a GLbuffer to this GLbindingPoint
       * 
       * @tparam T The type of data being stored in the buffer
       * @param pBuffer Pointer to the buffer to attach, if nullptr, this binding point will read from no buffer
       */
      template <class T>
      void attachBuffer(const GLbuffer<T> *pBuffer) noexcept
      {
        glVertexArrayVertexBuffer(mrVao.getID(), mIndex, pBuffer ? pBuffer->getID() : GL_NONE,
                                  GL_NONE, pBuffer ? sizeof(T) : GL_NONE);
      }

      /**
       * @brief Wrapper for attachBuffer to allow for nullptr case as parameter
       * 
       */
      void attachBuffer(nullptr_t) noexcept;



    private:
      friend class GLvertexArray; // Grant GLvertexArray exclusive instantiation rights

      /**
       * @brief Construct a new Binding Point object
       * 
       * @param rVao 
       * @param index 
       */
      GLbindingPoint(const GLvertexArray &rVao, GLuint index) noexcept;

      /**
       * @brief Destroy the Binding Point object
       * 
       */
      ~GLbindingPoint() noexcept;

    private:
      const GLvertexArray &mrVao; // The reference to the host vao
      const GLuint mIndex;        // The index of the binding point
    };

    /**
     * @brief An GLattribute specifies the formatting of buffer data inside a GLbindingPoint
     * 
     */
    class GLattribute
    {
    public:
      /**
       * @brief Format this GLattribute
       * 
       * @param size The number of elements in the attribute (between 1-4)
       * @param type The type of data each element in the attribute is
       * @param relativeOffset The difference between successive elements in the buffer
       */
      void format(GLuint size, GLtype type, GLuint relativeOffset) noexcept;

      /**
       * @brief Enable this attribute during draw calls
       * 
       */
      void enable() noexcept;

      /**
       * @brief Disable this attribute during draw calls
       * 
       */
      void disable() noexcept;

      /**
       * @brief Set the Binding Point object. If the GLbindingPoint comes from a different vao than this attribute, 
       * an exception will be thrown
       * 
       * @param rBindingPoint 
       */
      void setBindingPoint(const GLbindingPoint &rBindingPoint);

      /**
       * @brief Get the Vao object
       * 
       * @return const GLuint& 
       */
      const GLuint &getVao() const noexcept;

      /**
       * @brief Get the Index object
       * 
       * @return const GLuint& 
       */
      const GLuint &getIndex() const noexcept;

      /**
       * @brief Get the Binding Point object
       * 
       * @return const GLbindingPoint& 
       */
      const GLbindingPoint &getBindingPoint() const noexcept;

      /**
       * @brief Get the Size object
       * 
       * @return GLuint 
       */
      GLuint getSize() const noexcept;

      /**
       * @brief Get the Type object
       * 
       * @return GLtype 
       */
      GLtype getType() const noexcept;

      /**
       * @brief Get the Relative Offset object
       * 
       * @return GLuint 
       */
      GLuint getRelativeOffset() const noexcept;

      /**
       * @brief Check if the attribute is enabled
       * 
       * @return GLboolean 
       */
      GLboolean isEnabled() const noexcept;

    private:
      friend class GLvertexArray; // Grant GLvertexArray exclusive instantiation rights

      /**
       * @brief Construct a new GLattribute object
       * 
       * @param rVao Reference to the host vao
       * @param index The index for the attribute
       */
      GLattribute(const GLvertexArray &rVao, GLuint index) noexcept;

      /**
       * @brief Destroy the GLattribute object
       * 
       */
      ~GLattribute() noexcept;

    private:
      const GLvertexArray &mrVao;           // The reference to the host vao
      const GLuint mIndex;                  // The index of the attribute
      const GLbindingPoint *mpBindingPoint; // The binding point this attribute is reading from
    };

  private:
    friend class mogl::ModernOpenGL; // Grant MOGL allocation rights

    /**
     * @brief Construct a new Vertex Array GLobject object
     * 
     */
    GLvertexArray();
    ~GLvertexArray();

    /**
     * @brief Bind the GLvertexArray for drawing
     * 
     */
    void bind() noexcept;

  private:
  };
} // namespace mogl::objects

#endif