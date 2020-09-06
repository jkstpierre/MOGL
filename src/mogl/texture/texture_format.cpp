/**
 * @file  texture/texture_format.cpp.
 *
 * Implements the texture format class
 */

#include "mogl/texture/texture_format.hpp"

namespace mogl
{
const GLtextureFormat GLtextureFormat::_RED = GLtextureFormat(GL_RED);
const GLtextureFormat GLtextureFormat::_RG = GLtextureFormat(GL_RG);
const GLtextureFormat GLtextureFormat::_RGB = GLtextureFormat(GL_RGB);
const GLtextureFormat GLtextureFormat::_RGBA = GLtextureFormat(GL_RGBA);
const GLtextureFormat GLtextureFormat::_DEPTH_COMPONENT = GLtextureFormat(GL_DEPTH_COMPONENT);
const GLtextureFormat GLtextureFormat::_STENCIL_INDEX = GLtextureFormat(GL_STENCIL_INDEX);


GLtextureFormat::GLtextureFormat(GLenum value) : mcValue(value)
{}

GLenum GLtextureFormat::asBase() const noexcept
{
  return mcValue;
}

GLenum GLtextureFormat::asInternal() const noexcept
{
  switch ( mcValue )
  {
  case GL_RED:
    return GL_R8;
  case GL_RG:
    return GL_RG8;
  case GL_RGB:
    return GL_RGB8;
  case GL_RGBA:
    return GL_RGBA8;
  case GL_DEPTH_COMPONENT:
    return GL_DEPTH_COMPONENT24;
  case GL_STENCIL_INDEX:
    return GL_STENCIL_INDEX8;
  default:
    return GL_NONE; // Will never happen
  }
}
}