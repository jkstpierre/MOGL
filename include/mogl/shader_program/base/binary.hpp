/**
 * @file  base/binary.hpp.
 *
 * Declares the binary class
 */

#ifndef __MOGL_SHADER_PROGRAM_BASE_GL_BINARY_HPP__
#define __MOGL_SHADER_PROGRAM_BASE_GL_BINARY_HPP__

namespace mogl
{
/**
 * A GLbinary is an abstract base class for binaries on the GPU during OpenGL draw calls
 *
 * @author  jkstpierre
 * @date  9/4/2020
 */
class GLbinary
{
  friend class GLcontext; // Allow GLcontext to use a binary during draw calls
public:
  /**
   * Query if this GLbinary is active
   *
   * @author  jkstpierre
   * @date  9/4/2020
   *
   * @returns True if active, false if not.
   */
  bool isActive() const noexcept;

protected:
  /**
   * Uses this GLbinary for subsequent draw calls
   *
   * @author  jkstpierre
   * @date  9/4/2020
   */
  virtual void use() const noexcept = 0;

protected:
  /**
   * Default constructor
   *
   * @author  jkstpierre
   * @date  9/4/2020
   */
  GLbinary() = default;

  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  9/4/2020
   */
  ~GLbinary() noexcept = default;

protected:
  /** Static pointer to the currently active binary */
  static const GLbinary* scpActiveBinary;
};
}

#endif