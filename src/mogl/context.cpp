/**
 * @file  mogl/context.cpp.
 *
 * Implements the context class
 */

#include "mogl/context.hpp"

namespace mogl
{
/** There is no active context by default */
bool Context::sActive = false;

Allocator& Context::getAllocator() noexcept
{
  return mAllocator;
}
}