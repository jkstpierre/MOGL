/**
 * @file  mogl/context.hpp.
 *
 * Declares the context class
 */

#ifndef __MOGL_GL_CONTEXT_HPP__
#define __MOGL_GL_CONTEXT_HPP__

#include "mogl/platform.hpp"
#include "mogl/draw_mode.hpp"
#include "mogl/vertex_array/vertex_array.hpp"
#include "mogl/shader_program/binary.hpp"
#include "mogl/texture/texture_unit.hpp"
#include <memory>
#include <array>

namespace mogl
{
/** The context major version */
const unsigned GL_CONTEXT_MAJOR_VERSION = 4U;

/** The context minor version */
const unsigned GL_CONTEXT_MINOR_VERSION = 6U;

/**
 * An OS independent OOP compliant OpenGL 4.6 context.
 *
 * @author  jkstpierre
 * @date  8/28/2020
 */
class GLcontext final
{
public:
#if defined(MOGL_OS_WINDOWS)
  /**
   * Constructor
   *
   * @author  jkstpierre
   * @date  8/28/2020
   *
   * @param   color     The color bits.
   * @param   depth     The depth bits.
   * @param   stencil   The stencil bits.
   * @param   antialias The antialias samples.
   * @param   dc        The Windows device-context.
   */
  GLcontext(GLubyte color, GLubyte depth, GLubyte stencil, GLubyte antialias, HDC dc);

#elif defined(MOGL_OS_LINUX)
  /**
   * Constructor
   *
   * @author  jkstpierre
   * @date  8/28/2020
   *
   * @param   color     The color bits.
   * @param   depth     The depth bits.
   * @param   stencil   The stencil bits.
   * @param   antialias The antialias samples.
   * @param   window    The X11 window.
   */
  GLcontext(GLubyte color, GLubyte depth, GLubyte stencil, GLubyte antialias, Window window);

#endif
  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  8/28/2020
   */
  ~GLcontext() noexcept;

  // Delete copy constructor and copy assignment
  GLcontext(const GLcontext&) = delete;
  GLcontext& operator=(const GLcontext&) = delete;

  // TODO: Implement move constructor and assignment, but for now, lets just delete them
  GLcontext(GLcontext&&) noexcept = delete;
  GLcontext& operator=(GLcontext&&) noexcept = delete;

public:
  /**
   * Creates a new OpenGL object on the stack and returns it
   *
   * @tparam  T     Generic type parameter.
   * @tparam  Args  Type of the arguments.
   * @param   args  Variable arguments providing [in,out] The arguments.
   *
   * @returns A T.
   */
  template <class T, class... Args>
  T sAlloc(Args&&... args) const
  {
    static_assert(std::is_base_of<GLobject<T>, T>::value);

    return T(std::forward<Args>(args)...);
  }

  /**
   * Creates a new OpenGL object on the heap and returns a unique_ptr to the created object
   *
   * @tparam  T     Generic type parameter.
   * @tparam  Args  Type of the arguments.
   * @param   args  Variable arguments providing [in,out] The arguments.
   *
   * @returns A std::unique_ptr&lt;T&gt;
   */
  template <class T, class... Args>
  std::unique_ptr<T, typename T::Deleter> hAlloc(Args&&... args) const
  {
    static_assert(std::is_base_of<GLobject<T>, T>::value);

    return std::unique_ptr<T, T::Deleter>(new T(std::forward<Args>(args)...), T::Deleter());
  }

  /**
   * Sets a viewport
   *
   * @author  jkstpierre
   * @date  9/4/2020
   *
   * @param   viewport  The viewport.
   */
  void setViewport(const std::array<GLint, 4>& viewport) noexcept;

  /**
   * Gets the viewport
   *
   * @author  jkstpierre
   * @date  9/4/2020
   *
   * @returns The viewport.
   */
  const std::array<GLint, 4>& getViewport() const noexcept;

  /**
   * Sets active binary for subsequent draw calls
   *
   * @author  jkstpierre
   * @date  9/5/2020
   *
   * @param   binary  The binary.
   */
  void setActiveBinary(const GLbinary& binary) noexcept;

  /**
   * Access the GLtextureUnit at index
   *
   * @author  jkstpierre
   * @date  9/5/2020
   *
   * @param   index Zero-based index of the.
   *
   * @returns A reference to a GLtextureUnit.
   */
  GLtextureUnit& textureUnit(GLuint index);

  /**
   * Gets texture unit count
   *
   * @author  jkstpierre
   * @date  9/5/2020
   *
   * @returns The texture unit count.
   */
  GLuint getTextureUnitCount() const noexcept;

  // DRAW COMMANDS 

  /**
   * Draw arrays
   *
   * @author  jkstpierre
   * @date  9/4/2020
   *
   * @param   vao   The vao.
   * @param   mode  The mode.
   * @param   first The first.
   * @param   count Number of.
   */
  void drawArrays(const GLvertexArray& vao, GLdrawMode mode, GLint first, GLsizei count) const noexcept;

  /**
   * Draw elements from vao. NOTE: Vao must have an attached element buffer for this method to work.
   *
   * @author  jkstpierre
   * @date  9/4/2020
   *
   * @param   vao   The vao.
   * @param   mode  The mode.
   * @param   count Number of.
   */
  void drawElements(const GLvertexArray& vao, GLdrawMode mode, GLsizei count) const noexcept;

private:
  /** True if an OpenGL Context is active (prevents multiple contexts from coexisting) */
  static bool sActive;

#if defined(MOGL_OS_WINDOWS)
  /** The device context this OpenGL context is tied to */
  HDC mDeviceContext;

  /** Handle to the active OpenGL context */
  HGLRC mContext;

#elif defined(MOGL_OS_LINUX)

#endif

  /** The viewport */
  std::array<GLint, 4> mViewport;

  /** The texture units */
  std::vector<std::unique_ptr<GLtextureUnit, GLtextureUnit::Deleter>> mTextureUnits;
};
}

#endif

