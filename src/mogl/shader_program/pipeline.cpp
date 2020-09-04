/**
 * @file  shader_program/pipeline.cpp.
 *
 * Implements the pipeline class
 */

#include "mogl/shader_program/pipeline.hpp"
#include <stdexcept>

namespace mogl
{
GLpipeline::GLpipeline()
{
  glCreateProgramPipelines(1, &mID);
  if ( !mID )
  {
    throw std::runtime_error("Failed to create GLpipeline.");
  }
}

GLpipeline::~GLpipeline() noexcept
{
  glDeleteProgramPipelines(1, &mID);
}

void GLpipeline::use() const noexcept
{
  if ( !isActive() )
  {
    glUseProgram(GL_NONE);
    glBindProgramPipeline(mID);
    scpActiveBinary = this; // Track this binary as active
  }
}

void GLpipeline::attachProgram(const GLprogram& program)
{
  // Attach the program to the pipeline
  glUseProgramStages(mID, GL_ALL_SHADER_BITS, program.getID());

  // Validate the pipeline
  glValidateProgramPipeline(mID);

  // Check the status of the validation
  static const GLuint ERROR_LOG_SIZE = 512U;
  static GLchar errorLog[ERROR_LOG_SIZE];
  static GLint success;
  glGetProgramPipelineiv(mID, GL_VALIDATE_STATUS, &success);
  if ( !success )
  {
    glGetProgramPipelineInfoLog(mID, ERROR_LOG_SIZE, nullptr, errorLog);
    glDeleteProgramPipelines(1, &mID);
    throw std::runtime_error("GLpipeline failed validation. OpenGL Error: " + std::string(errorLog));
  }
}

void GLpipeline::attachProgram(const std::unique_ptr<GLprogram, GLprogram::Deleter>& pProgram)
{
  if ( pProgram.get() )
  {
    attachProgram(*pProgram.get());
  }
  else
  {
    throw std::runtime_error("GLpipeline cannot attach null program.");
  }
}
}