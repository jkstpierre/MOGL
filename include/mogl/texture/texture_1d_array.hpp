/**
 * @file  texture/texture_1d_array.hpp.
 *
 * Declares the texture 1d array class
 */

#ifndef __MOGL_TEXTURE_GL_TEXTURE_1D_ARRAY_HPP__
#define __MOGL_TEXTURE_GL_TEXTURE_1D_ARRAY_HPP__

#include "mogl/texture/base/texture_2d_impl.hpp"

namespace mogl
{
/**
 * List of g ltexture 1ds. This class cannot be inherited..
 *
 * @author  jkstpierre
 * @date  9/6/2020
 */
class GLtexture1dArray final : public GLtexture2dImpl<GLtexture1dArray>
{
  friend class GLcontext;
public:
  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  9/6/2020
   */
  ~GLtexture1dArray() noexcept = default;

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
  GLtexture1dArray(GLsizei levels, GLtextureFormat format, GLsizei width, GLsizei height);
};
}

#endif