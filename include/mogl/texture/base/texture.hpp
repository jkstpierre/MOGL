/**
 * @file  base/texture.hpp.
 *
 * Declares the texture class
 */

#ifndef __MOGL_TEXTURE_BASE_GL_TEXTURE_HPP__
#define __MOGL_TEXTURE_BASE_GL_TEXTURE_HPP__

#include "mogl/base/object.hpp"
#include "mogl/texture/texture_target.hpp"
#include "mogl/texture/texture_format.hpp"
#include <array>

namespace mogl
{
/**
 * A ltexture.
 *
 * @author  jkstpierre
 * @date  9/5/2020
 *
 * @tparam  T Generic type parameter.
 * @tparam  N Type of the n.
 */
template <class T, int N>
class GLtexture : public GLobject<T>
{
  friend class GLcontext;
public:
  /**
   * Gets the target
   *
   * @author  jkstpierre
   * @date  9/5/2020
   *
   * @returns The target.
   */
  const GLtextureTarget& getTarget() const noexcept
  {
    return mcTarget;
  }

  /**
   * Gets the levels
   *
   * @author  jkstpierre
   * @date  9/5/2020
   *
   * @returns The levels.
   */
  const GLsizei& getLevels() const noexcept
  {
    return mcLevels;
  }

  /**
   * Gets the format
   *
   * @author  jkstpierre
   * @date  9/5/2020
   *
   * @returns The format.
   */
  const GLtextureFormat& getFormat() const noexcept
  {
    return mcFormat;
  }

  /**
   * Gets dimensions allocated at storage
   *
   * @author  jkstpierre
   * @date  9/5/2020
   *
   * @returns The storage dimensions.
   */
  const std::array<GLsizei, N>& getDimensions() const noexcept
  {
    return mcDimensions;
  }

  /**
   * Generates the mipmaps for a texture
   *
   * @author  jkstpierre
   * @date  9/6/2020
   */
  void generateMipmaps() noexcept
  {
    glGenerateTextureMipmap(mID);
  }

protected:
  /**
   * Constructor
   *
   * @author  jkstpierre
   * @date  9/5/2020
   *
   * @param   target      Target for the.
   * @param   format      Describes the format to use.
   * @param   levels      The levels.
   * @param   dimensions  The dimensions.
   */
  GLtexture(GLtextureTarget target, GLsizei levels, GLtextureFormat format, const std::array<GLsizei, N>& dimensions) : mcTarget(target), mcLevels(levels), mcFormat(format), mcDimensions{ dimensions }
  {
    glCreateTextures(static_cast<GLenum>(target), 1, &mID);
  }

  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  9/5/2020
   */
  virtual ~GLtexture() noexcept
  {
    glDeleteTextures(1, &mID);
  }

protected:
  /** Target for this OpenGL texture object */
  const GLtextureTarget mcTarget;

  /** The mc levels */
  const GLsizei mcLevels;

  /** The mc format */
  const GLtextureFormat mcFormat;

  /** The dimensions */
  const std::array<GLsizei, N> mcDimensions;
};
}

#endif