/**
 * @file  texture/texture_unit.cpp.
 *
 * Implements the texture unit class
 */

#include "mogl/texture/texture_unit.hpp"

namespace mogl
{
GLtextureUnit::GLtextureUnit(GLuint index) : mcIndex(index)
{}

GLtextureUnit::~GLtextureUnit() noexcept
{}

void GLtextureUnit::bindSampler(const GLsampler* pSampler) noexcept
{
  mSamplerID = pSampler ? pSampler->getID() : GL_NONE;
  glBindSampler(mcIndex, mSamplerID);
}

const GLuint& GLtextureUnit::getIndex() const noexcept
{
  return mcIndex;
}

const GLuint& GLtextureUnit::getSamplerID() const noexcept
{
  return mSamplerID;
}

const GLuint& GLtextureUnit::getTextureID() const noexcept
{
  return mTextureID;
}
}