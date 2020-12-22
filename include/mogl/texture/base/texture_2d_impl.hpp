/**
 * @file  base/texture_2d_impl.hpp.
 *
 * Declares the texture 2D implementation class
 */

#ifndef __MOGL_TEXTURE_BASE_GL_TEXTURE_2D_IMPL_HPP__
#define __MOGL_TEXTURE_BASE_GL_TEXTURE_2D_IMPL_HPP__

#include "mogl/texture/base/texture.hpp"

namespace mogl
{
template <class T>
class GLtexture2dImpl : public GLtexture<T, 2>
{
public:
  /**
   * Fill data
   *
   * @author  jkstpierre
   * @date  9/6/2020
   *
   * @param   level   The level.
   * @param   xoffset The xoffset.
   * @param   yoffset The yoffset.
   * @param   width   The width.
   * @param   height  The height.
   * @param   pData   The data.
   */
  void fillData(GLuint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, const void* pData)
  {
    glTextureSubImage2D(mID, level, xoffset, yoffset, width, height, this->mcFormat.asBase(), GL_UNSIGNED_BYTE, pData);
  }

protected:
  /**
   * Constructor
   *
   * @author  jkstpierre
   * @date  9/6/2020
   *
   * @param   target  Target for the.
   * @param   levels  The levels.
   * @param   format  Describes the format to use.
   * @param   width   The width.
   * @param   height  The height.
   */
  GLtexture2dImpl(GLtextureTarget target, GLsizei levels, GLtextureFormat format, GLsizei width, GLsizei height) 
    : GLtexture<T, 2>(target, levels, format, { width, height })
  {
    glTextureStorage2D(mID, levels, format.asInternal(), width, height);
  }

  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  9/6/2020
   */
  virtual ~GLtexture2dImpl() noexcept = default;
};
}

#endif