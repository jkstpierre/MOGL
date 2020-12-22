/**
 * @file  texture/texture_2d.cpp.
 *
 * Implements the texture 2D class
 */

#include "mogl/texture/texture_2d.hpp"

namespace mogl
{
GLtexture2d::GLtexture2d(GLsizei levels, GLtextureFormat format, GLsizei width, GLsizei height) 
  : GLtexture2dImpl(GLtextureTarget::_TEXTURE_2D, levels, format, width, height)
{}
}