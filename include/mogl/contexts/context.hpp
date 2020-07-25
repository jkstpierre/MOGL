/**
 * @file context.hpp
 * @author jkstpierre (jkstpierre@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2020-07-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __MOGL_CONTEXTS_CONTEXT_HPP__
#define __MOGL_CONTEXTS_CONTEXT_HPP__

namespace mogl::contexts
{
  /**
   * @brief A Context is an active OpenGL state and is used by Window objects to update their frames
   * 
   */
  class Context
  {
  public:
  
  private:
    friend class ContextBuilder; // Grant ContextBuilder exclusive allocation rights
  };
} // namespace mogl::contexts

#endif