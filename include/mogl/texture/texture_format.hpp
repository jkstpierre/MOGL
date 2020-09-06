/**
 * @file  texture/texture_format.hpp.
 *
 * Declares the texture format class
 */

#ifndef __MOGL_TEXTURE_GL_TEXTURE_FORMAT_HPP__
#define __MOGL_TEXTURE_GL_TEXTURE_FORMAT_HPP__

#include "mogl/platform.hpp"

namespace mogl
{
/**
 * A ltexture format. This class cannot be inherited..
 *
 * @author  jkstpierre
 * @date  9/5/2020
 */
class GLtextureFormat final
{
public:
  // Enumerations
  static const GLtextureFormat _RED;
  static const GLtextureFormat _RG;
  static const GLtextureFormat _RGB;
  static const GLtextureFormat _RGBA;
  static const GLtextureFormat _DEPTH_COMPONENT;
  static const GLtextureFormat _STENCIL_INDEX;

public:
  /**
   * Gets the base format
   *
   * @author  jkstpierre
   * @date  9/5/2020
   *
   * @returns A GLenum.
   */
  GLenum asBase() const noexcept;

  /**
   * Gets the internal format
   *
   * @author  jkstpierre
   * @date  9/5/2020
   *
   * @returns A GLenum.
   */
  GLenum asInternal() const noexcept;

private:
  /**
   * Constructor
   *
   * @author  jkstpierre
   * @date  9/5/2020
   *
   * @param   format  Describes the format to use.
   */
  GLtextureFormat(GLenum value);

  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  9/5/2020
   */
  ~GLtextureFormat() noexcept = default;

private:
  /** The mc value */
  const GLenum mcValue;
};
}

#endif