/**
 * @file  texture/texture_cube_map.hpp.
 *
 * Declares the texture cube map class
 */

#ifndef __MOGL_TEXTURE_GL_TEXTURE_CUBE_MAP_HPP__
#define __MOGL_TEXTURE_GL_TEXTURE_CUBE_MAP_HPP__

#include "mogl/texture/base/texture_2d_impl.hpp"

namespace mogl
{
/**
 * Map of ltexture cubes. This class cannot be inherited..
 *
 * @author  jkstpierre
 * @date  9/6/2020
 */
class GLtextureCubeMap final : public GLtexture2dImpl<GLtextureCubeMap>
{

};
}

#endif