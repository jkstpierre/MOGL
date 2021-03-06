/**
 * @file  texture/texture_target.hpp.
 *
 * Declares the texture target class
 */

#ifndef __MOGL_TEXTURE_GL_TEXTURE_TARGET_HPP__
#define __MOGL_TEXTURE_GL_TEXTURE_TARGET_HPP__

#include "mogl/platform.hpp"

namespace mogl
{
/** Values that represent Texture types types */
enum class GLtextureTarget : GLenum
{
  _TEXTURE_1D = GL_TEXTURE_1D,
  _TEXTURE_2D = GL_TEXTURE_2D,
  _TEXTURE_3D = GL_TEXTURE_3D,
  _TEXTURE_1D_ARRAY = GL_TEXTURE_1D_ARRAY,
  _TEXTURE_2D_ARRAY = GL_TEXTURE_2D_ARRAY,
  _TEXTURE_CUBE_MAP = GL_TEXTURE_CUBE_MAP,
  _TEXTURE_CUBE_MAP_ARRAY = GL_TEXTURE_CUBE_MAP_ARRAY,
  _TEXTURE_BUFFER = GL_TEXTURE_BUFFER//,  // TODO: This needs to be implemented

  // TODO: Work out the details of multisampling (should it be left solely to the context creation stage?)

  //_TEXTURE_2D_MULTISAMPLE = GL_TEXTURE_2D_MULTISAMPLE,        
  //_TEXTURE_2D_MULTISAMPLE_ARRAY = GL_TEXTURE_2D_MULTISAMPLE_ARRAY
};
}

#endif