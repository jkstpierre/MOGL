/**
 * @file context_builder.hpp
 * @author jkstpierre (jkstpierre@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2020-07-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __MOGL_CONTEXTS_CONTEXT_BUILDER_HPP__
#define __MOGL_CONTEXTS_CONTEXT_BUILDER_HPP__

namespace mogl::contexts
{
  /**
   * @brief Forward declaration
   * 
   */
  class ContextPolicy;

  /**
   * @brief A ContextBuilder builds a Context instance
   * 
   */
  class ContextBuilder
  {
  public:
    Context *const &build();

  private:
    friend class ContextPolicy; // Grant ContextPolicy exclusive allocation rights

    /**
     * @brief Construct a new Context Builder object
     * 
     */
    ContextBuilder(ContextPolicy &rPolicy) noexcept;

    /**
     * @brief Destroy the Context Builder object
     * 
     */
    virtual ~ContextBuilder() noexcept = default;

    /**
     * @brief Reset the ContextBuilder to its initial settings
     * 
     */
    void reset() noexcept;

  private:
    ContextPolicy &mrContextPolicy; // Reference to parent ContextPolicy object
  };
} // namespace mogl::contexts

#endif