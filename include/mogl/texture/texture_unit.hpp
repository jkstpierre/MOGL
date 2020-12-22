/**
 * @file  texture/texture_unit.hpp.
 *
 * Declares the texture unit class
 */

#ifndef __MOGL_TEXTURE_GL_TEXTURE_UNIT_HPP__
#define __MOGL_TEXTURE_GL_TEXTURE_UNIT_HPP__

#include "mogl/base/heap_protected.hpp"
#include "mogl/platform.hpp"
#include "mogl/texture/sampler.hpp"
#include "mogl/texture/base/texture.hpp"

namespace mogl
{
/**
 * A GLtextureUnit represents a location for GLsamplers and GLtextures to be bound together in a 1-
 * 1 relationship. This class cannot be inherited..
 *
 * @author  jkstpierre
 * @date  9/4/2020
 */
class GLtextureUnit final : public HeapProtected<GLtextureUnit>
{
  friend class GLcontext;
public:
  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  9/5/2020
   */
  ~GLtextureUnit() noexcept;

public:
  /**
   * Bind sampler
   *
   * @author  jkstpierre
   * @date  9/5/2020
   *
   * @param   pSampler  The sampler.
   */
  void bindSampler(const GLsampler* pSampler) noexcept;

  /**
   * Bind texture
   *
   * @author  jkstpierre
   * @date  9/5/2020
   *
   * @param   pTexture  The texture.
   */
  template <class T, int N>
  void bindTexture(const GLtexture<T, N>* pTexture) noexcept
  {
    mTextureID = pTexture ? pTexture->getID() : GL_NONE;
    glBindTextureUnit(mcIndex, mTextureID);
  }

  /**
   * Bind null texture
   *
   * @author  jkstpierre
   * @date  9/6/2020
   *
   * @param   parameter1  The first parameter.
   */
  void bindTexture(nullptr_t) noexcept;

  /**
   * Gets the index
   *
   * @author  jkstpierre
   * @date  9/5/2020
   *
   * @returns The index.
   */
  const GLuint& getIndex() const noexcept;

  /**
   * Gets sampler identifier
   *
   * @author  jkstpierre
   * @date  9/5/2020
   *
   * @returns The sampler identifier.
   */
  const GLuint& getSamplerID() const noexcept;

  /**
   * Gets texture identifier
   *
   * @author  jkstpierre
   * @date  9/5/2020
   *
   * @returns The texture identifier.
   */
  const GLuint& getTextureID() const noexcept;

private:
  /**
   * Constructor
   *
   * @author  jkstpierre
   * @date  9/5/2020
   *
   * @param   index Zero-based index of the.
   */
  GLtextureUnit(GLuint index);

private:
  /** Zero-based index of the mc */
  const GLuint mcIndex;

  /** Identifier for the sampler */
  GLuint mSamplerID = GL_NONE;

  /** Identifier for the texture */
  GLuint mTextureID = GL_NONE;
};
}

#endif