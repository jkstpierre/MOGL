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
#include <vector>

namespace mogl
{
  class ModernOpenGL;
}

namespace mogl::objects
{
  const GLuint GLVERTEXARRAY_ID_NONE = 0U;                          // GLvertexArray Null Id
  const unsigned int GLVERTEXARRAY_BINDINGPOINT_DEFAULT_INDEX = 0U; // Default binding point index for attributes

  /**
   * @brief A GLvertexArray stores the state of OpenGL BufferObjects in addition to their formats
   * 
   */
  class GLvertexArray : public base::GLobject
  {
  public:
    /**
     * @brief A BindingPoint is a location for BufferObjects to attach to
     * 
     */
    class BindingPoint
    {
    public:
      /**
       * @brief Attach a GLbuffer to this BindingPoint
       * 
       * @tparam T The type of data being stored in the buffer
       * @param pBuffer Pointer to the buffer to attach, if nullptr, this binding point will read from no buffer
       */
      template <class T>
      void attachBuffer(const GLbuffer<T> *pBuffer) noexcept
      {
        glVertexArrayVertexBuffer(mVaoID, mIndex, pBuffer ? pBuffer->getID() : GLBUFFER_ID_NONE,
                                  GL_NONE, pBuffer ? sizeof(T) : GL_NONE);
      }

      /**
       * @brief Wrapper for attachBuffer to allow for nullptr case as parameter
       * 
       */
      void attachBuffer(nullptr_t) noexcept;

      /**
       * @brief Set the Divisor object
       * 
       * @param divisor 
       */
      void setDivisor(GLuint divisor) noexcept;

      /**
       * @brief Get the Vao I D object
       * 
       * @return const GLuint& 
       */
      const GLuint &getVaoID() const noexcept;

      /**
       * @brief Get the Index object
       * 
       * @return const unsigned int& 
       */
      const unsigned int &getIndex() const noexcept;

      /**
       * @brief Get the Buffer I D object
       * 
       * @return GLuint 
       */
      GLuint getBufferID() const noexcept;

      /**
       * @brief Get the Stride object
       * 
       * @return GLuint 
       */
      GLuint getStride() const noexcept;

      /**
       * @brief Get the Divisor object
       * 
       * @return GLuint 
       */
      GLuint getDivisor() const noexcept;

    private:
      friend class GLvertexArray; // Grant GLvertexArray exclusive instantiation rights

      /**
       * @brief Construct a new Binding Point object
       * 
       * @param rVao 
       * @param index 
       */
      BindingPoint(const GLvertexArray &rVao, unsigned int index) noexcept;

      /**
       * @brief Destroy the Binding Point object
       * 
       */
      ~BindingPoint() noexcept;

    private:
      const GLuint mVaoID;       // The id of the vao for this binding point
      const unsigned int mIndex; // The index of the binding point
    };

    /**
     * @brief An Attribute specifies the formatting of buffer data inside a BindingPoint
     * 
     */
    class Attribute
    {
    public:
      /**
       * @brief Format this Attribute
       * 
       * @param size The number of elements in the attribute (between 1-4)
       * @param type The type of data each element in the attribute is
       * @param normalized Should OpenGL normalize the data (Note: Ignored if type is not _FLOAT)
       * @param relativeOffset The difference between successive elements in the buffer
       */
      void format(GLuint size, GLtype type, GLboolean normalized, GLuint relativeOffset) noexcept;

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
       * @brief Set the Binding Point object. If the BindingPoint comes from a different vao than this attribute, 
       * an exception will be thrown
       * 
       * @param rBindingPoint Const reference to the binding point
       */
      void setBindingPoint(const BindingPoint &rBindingPoint);

      /**
       * @brief Get the Vao object
       * 
       * @return const GLuint& 
       */
      const GLuint &getVaoID() const noexcept;

      /**
       * @brief Get the Index object
       * 
       * @return const GLuint& 
       */
      const unsigned int &getIndex() const noexcept;

      /**
       * @brief Get the Binding Point Index object
       * 
       * @return const GLuint& 
       */
      const unsigned int &getBindingPointIndex() const noexcept;

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
       * @brief Construct a new Attribute object
       * 
       * @param rVao Reference to the host vao
       * @param index The index for the attribute
       */
      Attribute(GLvertexArray &rVao, unsigned int index) noexcept;

      /**
       * @brief Destroy the Attribute object
       * 
       */
      ~Attribute() noexcept = default;

    private:
      const GLuint mVaoID;       // The id of the parent vao
      const unsigned int mIndex; // The index of the attribute
      unsigned int mBindingPointIndex =
          GLVERTEXARRAY_BINDINGPOINT_DEFAULT_INDEX; // The index of the associated binding point
    };

  public:
    /**
     * @brief Get the Binding Point object
     * 
     * @return BindingPoint& 
     */
    BindingPoint &getBindingPoint(unsigned int index);

    /**
     * @brief Get the Binding Points Size object
     * 
     * @return size_t 
     */
    size_t getBindingPointsSize() const noexcept;

    /**
     * @brief Get the Attribute object
     * 
     * @return Attribute& 
     */
    Attribute &getAttribute(unsigned int index);

    /**
     * @brief Get the Attributes Size object
     * 
     * @return size_t 
     */
    size_t getAttributesSize() const noexcept;

  private:
    friend class mogl::ModernOpenGL; // Grant MOGL allocation rights

    /**
     * @brief Construct a new Vertex Array GLobject object
     * 
     */
    GLvertexArray();

    /**
     * @brief Destroy the GLvertexArray object
     * 
     */
    ~GLvertexArray();

    /**
     * @brief Bind the GLvertexArray for drawing
     * 
     */
    void bind() noexcept;

  private:
    std::vector<BindingPoint *> mBindingPoints; // The buffer BindingPoints for the GLvertexArray
    std::vector<Attribute *> mAttributes;       // The attributes for the GLvertexArray
  };
} // namespace mogl::objects

#endif