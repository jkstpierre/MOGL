/**
 * @file  texture/texture_2d.hpp.
 *
 * Declares the texture 2D class
 */

#ifndef __MOGL_TEXTURE_GL_TEXTURE_2D_HPP__
#define __MOGL_TEXTURE_GL_TEXTURE_2D_HPP__

#include "mogl/texture/base/texture_2d_impl.hpp"

namespace mogl 
{
/**
 * A ltexture 2d. This class cannot be inherited..
 *
 * @author  jkstpierre
 * @date  9/6/2020
 */
class GLtexture2d final : public GLtexture2dImpl<GLtexture2d>
{
  friend class GLcontext;
public:
  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  9/6/2020
   */
  ~GLtexture2d() noexcept = default;

private:
  /**
   * Constructor
   *
   * @author  jkstpierre
   * @date  9/6/2020
   *
   * @param   levels  The levels.
   * @param   format  Describes the format to use.
   * @param   width   The width.
   * @param   height  The height.
   */
  GLtexture2d(GLsizei levels, GLtextureFormat format, GLsizei width, GLsizei height);
};
}

#endif