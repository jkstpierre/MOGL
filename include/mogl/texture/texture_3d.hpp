/**
 * @file  texture/texture_3d.hpp.
 *
 * Declares the texture 3D class
 */

#ifndef __MOGL_TEXTURE_GL_TEXTURE_3D_HPP__
#define __MOGL_TEXTURE_GL_TEXTURE_3D_HPP__

#include "mogl/texture/base/texture_3d_impl.hpp"

namespace mogl 
{
/**
 * A ltexture 3d. This class cannot be inherited..
 *
 * @author  jkstpierre
 * @date  9/6/2020
 */
class GLtexture3d final : public GLtexture3dImpl<GLtexture3d>
{

};
}

#endif