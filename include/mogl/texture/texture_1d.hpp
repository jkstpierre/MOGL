/**
 * @file  texture/texture_1d.hpp.
 *
 * Declares the texture 1d class
 */

#ifndef __MOGL_TEXTURE_GL_TEXTURE_1D_HPP__
#define __MOGL_TEXTURE_GL_TEXTURE_1D_HPP__

#include "mogl/texture/base/texture_1d_impl.hpp"

namespace mogl
{
/**
 * A ltexture 1d.
 *
 * @author  jkstpierre
 * @date  9/5/2020
 */
class GLtexture1d final : public GLtexture1dImpl<GLtexture1d>
{
  friend class GLcontext;
public:
  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  9/5/2020
   */
  ~GLtexture1d() noexcept = default;

private:
  /**
   * Constructor
   *
   * @author  jkstpierre
   * @date  9/5/2020
   *
   * @param   levels  The levels.
   * @param   format  Describes the format to use.
   * @param   width   The width.
   */
  GLtexture1d(GLsizei levels, GLtextureFormat format, GLsizei width);
};
}

#endif