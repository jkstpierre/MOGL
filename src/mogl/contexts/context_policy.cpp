/**
 * @file context_policy.cpp
 * @author jkstpierre (jkstpierre@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2020-07-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <mogl/contexts/context_policy.hpp>

namespace mogl::contexts
{
  ContextPolicy::ContextPolicy() noexcept : mContextBuilder(*this), mpContext(nullptr)
  {
  }

  ContextPolicy::~ContextPolicy() noexcept
  {
    free();
  }

  ContextBuilder &ContextPolicy::newBuilder() noexcept
  {
    mContextBuilder.reset();
    return mContextBuilder;
  }

  Context *const &ContextPolicy::get() const noexcept
  {
    return mpContext;
  }

  void ContextPolicy::free() noexcept
  {
    if (mpContext)
    {
      delete mpContext;
      set(nullptr);
    }
  }

  void ContextPolicy::set(Context *context) noexcept
  {
    mpContext = context;
  }
} // namespace mogl::contexts