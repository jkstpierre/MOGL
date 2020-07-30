/**
 * @file object.hpp
 * @author jkstpierre (jkstpierre@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2020-07-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __MOGL_BASE_OBJECT_HPP__
#define __MOGL_BASE_OBJECT_HPP__

#include <mogl/platform.hpp>

namespace mogl
{
  /**
   * @brief Forward declaration
   * 
   */
  class ModernOpenGL;
} // namespace mogl

namespace mogl::base
{
  const GLuint OBJECT_ID_NONE = 0U;

  /**
   * @brief An Object is an abstract base class for all objects created and managed by OpenGL that have an id.
   * 
   */
  class Object
  {
  public:
    /**
     * @brief 
     * 
     * @return const GLuint& 
     */
    const GLuint &getID() const noexcept;

  protected:
    Object() = default;
    virtual ~Object() = default;

    /**
     * @brief Delete copy and move constructors for all Objects
     * 
     */
    Object(const Object &) = delete;
    Object(Object &&) noexcept = delete;
    Object &operator=(const Object &) = delete;
    Object &operator=(Object &&) noexcept = delete;

  protected:
    friend class mogl::ModernOpenGL; // Grant ModernOpenGL access to private fields

    /**
     * @brief The id number of this object
     * 
     */
    GLuint mID = OBJECT_ID_NONE;
  };
} // namespace mogl::base

#endif