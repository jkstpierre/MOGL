/**
 * @file  texture/texture_2d_array.cpp.
 *
 * Implements the texture 2D array class
 */

#include "mogl/texture/texture_2d_array.hpp"

namespace mogl
{
GLtexture2dArray::GLtexture2dArray(GLsizei levels, GLtextureFormat format, GLsizei width, GLsizei height, GLsizei depth)
  : GLtexture3dImpl(GLtextureTarget::_TEXTURE_2D_ARRAY, levels, format, width, height, depth)
{}
}