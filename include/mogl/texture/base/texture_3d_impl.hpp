/**
 * @file  base/texture_3d_impl.hpp.
 *
 * Declares the texture 3D implementation class
 */

#ifndef __MOGL_TEXTURE_BASE_GL_TEXTURE_3D_IMPL_HPP__
#define __MOGL_TEXTURE_BASE_GL_TEXTURE_3D_IMPL_HPP__

#include "mogl/texture/base/texture.hpp"

namespace mogl
{
/**
 * A ltexture 3D implementation.
 *
 * @author  jkstpierre
 * @date  9/5/2020
 *
 * @tparam  T Generic type parameter.
 */
template <class T>
class GLtexture3dImpl : public GLtexture<T, 3>
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
   * @param   zoffset The zoffset.
   * @param   width   The width.
   * @param   height  The height.
   * @param   depth   The depth.
   * @param   pData   The data.
   */
  void fillData(GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, const void* pData)
  {
    glTextureSubImage3D(mID, level, xoffset, yoffset, zoffset, width, height, depth, this->mcFormat.asBase(), GL_UNSIGNED_BYTE, pData);
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
   * @param   depth   The depth.
   */
  GLtexture3dImpl(GLtextureTarget target, GLsizei levels, GLtextureFormat format, GLsizei width, GLsizei height, GLsizei depth)
    : GLtexture<T, 3>(target, levels, format, { width, height, depth })
  {
    glTextureStorage3D(mID, levels, format.asInternal(), width, height, depth);
  }
};
}

#endif