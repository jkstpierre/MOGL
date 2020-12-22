/**
 * @file  texture/sampler.hpp.
 *
 * Declares the sampler class
 */

#ifndef __MOGL_TEXTURE_GL_SAMPLER_HPP__
#define __MOGL_TEXTURE_GL_SAMPLER_HPP__

#include "mogl/base/object.hpp"

namespace mogl
{
/**
 * A GLsampler object is an OpenGL object that stores the sampling parameters for a GLtexture
 * inside a shader. This class cannot be inherited..
 *
 * @author  jkstpierre
 * @date  9/4/2020
 */
class GLsampler final : public GLobject<GLsampler>
{
  friend class GLcontext; // 
private:

public:
};
}

#endif