/**
 * @file  shader_program/binary.cpp.
 *
 * Implements the binary class
 */

#include "mogl/shader_program/base/binary.hpp"

namespace mogl
{
const GLbinary* GLbinary::scpActiveBinary = nullptr;

bool GLbinary::isActive() const noexcept
{
  return this == scpActiveBinary;
}
}