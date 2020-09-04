/**
 * @file  shader_program/pipeline.hpp.
 *
 * Declares the pipeline class
 */

#ifndef __MOGL_SHADER_PROGRAM_GL_PIPELINE_HPP__
#define __MOGL_SHADER_PROGRAM_GL_PIPELINE_HPP__

#include "mogl/object.hpp"
#include "mogl/shader_program/program.hpp"

namespace mogl
{
/**
 * A pipeline allows for stages from separate GLprogram objects to run as if they were a single
 * GLprogram object. This class cannot be inherited..
 *
 * @author  jkstpierre
 * @date  9/2/2020
 */
class GLpipeline final : public GLobject<GLpipeline>, public GLbinary
{
  friend class GLcontext;
public:
  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  9/3/2020
   */
  ~GLpipeline() noexcept;

  /**
   * Use this pipeline object for rendering
   *
   * @author  jkstpierre
   * @date  9/3/2020
   */
  void use() const noexcept override;

  /**
   * Attach program
   *
   * @author  jkstpierre
   * @date  9/4/2020
   *
   * @param   program The program.
   */
  void attachProgram(const GLprogram& program);

  /**
   * Attach program
   *
   * @author  jkstpierre
   * @date  9/4/2020
   *
   * @param   pProgram  The program.
   */
  void attachProgram(const std::unique_ptr<GLprogram, GLprogram::Deleter>& pProgram);

private:
  /**
   * Default constructor
   *
   * @author  jkstpierre
   * @date  9/3/2020
   */
  GLpipeline();
};
}

#endif