/**
 * @file  texture/texture_1d.cpp.
 *
 * Implements the texture 1d class
 */

#include "mogl/texture/texture_1d.hpp"

namespace mogl
{
GLtexture1d::GLtexture1d(GLsizei levels, GLtextureFormat format, GLsizei width) : GLtexture1dImpl(GLtextureTarget::_TEXTURE_1D, levels, format, width)
{}
}