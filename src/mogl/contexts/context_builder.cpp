/**
 * @file context_builder.cpp
 * @author jkstpierre (jkstpierre@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2020-07-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <mogl/contexts/context_builder.hpp>

namespace mogl::contexts
{
  ContextBuilder::ContextBuilder(ContextPolicy &rPolicy) : mrContextPolicy(rPolicy)
  {
  }
} // namespace mogl::contexts