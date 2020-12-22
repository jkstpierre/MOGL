/**
 * @file  texture/texture_1d_array.cpp.
 *
 * Implements the texture 1d array class
 */

#include "mogl/texture/texture_1d_array.hpp"

namespace mogl
{
GLtexture1dArray::GLtexture1dArray(GLsizei levels, GLtextureFormat format, GLsizei width, GLsizei height) 
  : GLtexture2dImpl(GLtextureTarget::_TEXTURE_1D_ARRAY, levels, format, width, height)
{}
}