/**
 * @file  texture/texture_1d_impl.hpp.
 *
 * Declares the texture 1d implementation class
 */

#ifndef __MOGL_TEXTURE_GL_TEXTURE_1D_IMPL_HPP__
#define __MOGL_TEXTURE_GL_TEXTURE_1D_IMPL_HPP__

#include "mogl/texture/texture.hpp"
#include "mogl/texture/texture_format.hpp"

namespace mogl
{
/**
 * A ltexture 1d implementation.
 *
 * @author  jkstpierre
 * @date  9/5/2020
 *
 * @tparam  T Generic type parameter.
 */
template <class T>
class GLtexture1dImpl : public GLtexture<T, 1>
{
public:
  /**
   * Sets sub image
   *
   * @author  jkstpierre
   * @date  9/5/2020
   *
   * @param   level   The level.
   * @param   xoffset The xoffset.
   * @param   width   The width.
   * @param   pData   The data.
   */
  void setSubImage(GLint level, GLint xoffset, GLsizei width, const void* pData)
  {
    if ( xoffset + width > this->mDimensions[0] )
    {
      throw std::runtime_error("Cannot set image array indices outside the bounds of the allocated storage.");
    }

    if ( level >= this->mcLevels )
    {
      throw std::runtime_error("Cannot set level outside the bounds of the allocated storage.");
    }

    // TODO: Do more error checking? Apparently with each subsequent mipmap level, the dimensions should diminish by powers of 2 according to the OpenGL 4.6 spec

    glTextureSubImage1D(mID, level, xoffset, width, this->mcFormat.asBase(), GL_UNSIGNED_BYTE, pData);
  }

protected:
  /**
   * Constructor
   *
   * @author  jkstpierre
   * @date  9/5/2020
   *
   * @param   target  Target for the.
   * @param   levels  The levels.
   * @param   format  The internal format.
   * @param   width   The width.
   */
  GLtexture1dImpl(GLtextureTarget target, GLsizei levels, GLtextureFormat format, GLsizei width) : GLtexture<T, 1>(target, levels, format, { width })
  {
    glTextureStorage1D(mID, levels, format.asInternal(), width);
  }

  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  9/5/2020
   */
  virtual ~GLtexture1dImpl() noexcept = default;
};
}

#endif