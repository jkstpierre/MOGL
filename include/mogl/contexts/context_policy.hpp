/**
 * @file context_policy.hpp
 * @author jkstpierre (jkstpierre@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2020-07-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __MOGL_CONTEXTS_CONTEXT_POLICY_HPP__
#define __MOGL_CONTEXTS_CONTEXT_POLICY_HPP__

#include <mogl/contexts/context.hpp>
#include <mogl/contexts/context_builder.hpp>

namespace mogl::contexts
{
  /**
   * @brief A ContextPolicy handles the allocation, storage, and deallocation of Context objects
   * 
   */
  class ContextPolicy
  {
  public:
    /**
     * @brief Construct a new Context Policy object
     * 
     */
    ContextPolicy() noexcept;

    /**
     * @brief Destroy the Context Policy object
     * 
     */
    virtual ~ContextPolicy() noexcept;

    /**
     * @brief Resets the ContextBuilder state and returns a reference to it
     * 
     * @return ContextBuilder& 
     */
    ContextBuilder &newBuilder() noexcept;

    /**
     * @brief Get the Context object. Returns null if no Context exists
     * 
     * @return Context *const &
     */
    Context *const &get() const noexcept;

    /**
     * @brief Destroy the Context object if one exists
     * 
     */
    void free() noexcept;

  private:
    friend class ContextBuilder; // Grant ContextBuilder exclusive rights to set active Context

    /**
     * @brief Set the active Context
     * 
     * @param context 
     */
    void set(Context *context) noexcept;

  private:
    ContextBuilder mContextBuilder; // The builder for creating Context objects
    Context *mpContext;             // The Context object managed by this Policy
  };
} // namespace mogl::contexts

#endif