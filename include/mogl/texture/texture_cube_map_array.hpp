/**
 * @file  texture/texture_cube_map_array.hpp.
 *
 * Declares the texture cube map array class
 */

#ifndef __MOGL_TEXTURE_GL_TEXTURE_CUBE_MAP_ARRAY_HPP__
#define __MOGL_TEXTURE_GL_TEXTURE_CUBE_MAP_ARRAY_HPP__

#include "mogl/texture/base/texture_3d_impl.hpp"

namespace mogl
{
/**
 * List of g ltexture cube maps. This class cannot be inherited..
 *
 * @author  jkstpierre
 * @date  9/7/2020
 */
class GLtextureCubeMapArray final : public GLtexture3dImpl<GLtextureCubeMapArray>
{
  friend class GLcontext;
private:

public:

};
}

#endif