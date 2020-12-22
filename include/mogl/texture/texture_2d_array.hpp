/**
 * @file  texture/texture_2d_array.hpp.
 *
 * Declares the texture 2D array class
 */

#ifndef __MOGL_TEXTURE_GL_TEXTURE_2D_ARRAY_HPP__
#define __MOGL_TEXTURE_GL_TEXTURE_2D_ARRAY_HPP__

#include "mogl/texture/base/texture_3d_impl.hpp"

namespace mogl
{
/**
 * List of g ltexture 2ds. This class cannot be inherited..
 *
 * @author  jkstpierre
 * @date  9/6/2020
 */
class GLtexture2dArray final : public GLtexture3dImpl<GLtexture2dArray>
{
  friend class GLcontext;
public:
  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  9/6/2020
   */
  ~GLtexture2dArray() noexcept = default;

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
   * @param   depth   The depth.
   */
  GLtexture2dArray(GLsizei levels, GLtextureFormat format, GLsizei width, GLsizei height, GLsizei depth);
};
}

#endif