/**
 * @file  mogl/allocator.cpp.
 *
 * Implements the allocator class
 */

#include "mogl/allocator.hpp"

namespace mogl
{
Allocator::~Allocator() noexcept
{
  freeAll();
}

void Allocator::freeAll() noexcept
{
  for ( auto it = mObjectMap.begin(); it != mObjectMap.end(); it++ )
  {
    for ( auto obj = it->second.begin(); obj != it->second.end(); obj++ )
    {
      delete obj->second;
      obj->second = nullptr;
    }
  }

  mObjectMap.clear();
}
}