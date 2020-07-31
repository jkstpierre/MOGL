/**
 * @file mogl.hpp
 * @author jkstpierre (jkstpierre@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2020-07-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __MOGL_MOGL_HPP__
#define __MOGL_MOGL_HPP__

#include <mogl/platform.hpp>
#include <mogl/base/gl_object.hpp>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <vector>
#include <stdexcept>

namespace mogl
{
  /**
   * @brief The OpenGL context's major version number
   * 
   */
  const unsigned int MOGL_MAJOR_VERSION = 4U;

  /**
   * @brief The OpenGL context's minor version number
   * 
   */
  const unsigned int MOGL_MINOR_VERSION = 6U;

  /**
   * @brief A ModernOpenGL instance represents an OpenGL 4.6 context and upon successful construction 
   * grants access to the OpenGL API in a C++ friendly OOP manner
   * 
   */
  class ModernOpenGL
  {
  public:
#if defined(MOGL_OS_WINDOWS)
    /**
     * @brief Construct a new Modern Open G L object
     * 
     * @param colorBits 
     * @param depthBits 
     * @param stencilBits 
     * @param samples 
     * @param window 
     */
    ModernOpenGL(uint8_t colorBits, uint8_t depthBits, uint8_t stencilBits, uint16_t samples, const HWND window);
#elif defined(MOGL_OS_LINUX)
    /**
     * @brief Construct a new Modern Open G L object
     * 
     * @param colorBits The number of bits for the color buffer
     * @param depthBits The number of bits for the depth buffer
     * @param stencilBits The number of bits for the stencil buffer
     * @param samples The number of samples for antialiasing
     * @param pDisplay The X11 display server pointer
     * @param rWindow The X11 window reference
     */
    ModernOpenGL(uint8_t colorBits, uint8_t depthBits, uint8_t stencilBits, uint16_t samples, const Display *pDisplay, const Window &rWindow);
#endif
    /**
     * @brief Destroy the Modern OpenGL object
     * 
     */
    virtual ~ModernOpenGL() noexcept;

    /**
     * @brief Delete all copy and move constructors and operators
     * 
     */
    ModernOpenGL(const ModernOpenGL &) = delete;
    ModernOpenGL(ModernOpenGL &&) noexcept = delete;
    ModernOpenGL &operator=(const ModernOpenGL &) = delete;
    ModernOpenGL &operator=(ModernOpenGL &&) noexcept = delete;

    /**
     * @brief Enable/disable vsync.
     * 
     * @param enabled true to enable vsync, false to disable
     */
    void setVerticalSync(bool enabled) noexcept;

    /**
     * @brief Allocate and return a new mogl object
     * 
     * @tparam T The type of mogl object to create
     * @tparam Args 
     * @param args The list of arguments to send to the constructor
     * @return T* 
     */
    template <class T, class... Args>
    T *alloc(Args &&... args)
    {
      static_assert(std::is_base_of<base::GLobject, T>::value); // Ensure T is a mogl object

      T *pNewObj = new T(std::forward<Args>(args)...);

      std::type_index tIndex = typeid(T);
      if (mObjectMap.find(tIndex) == mObjectMap.end())
      {
        // Create a new entry
        mObjectMap.emplace(std::piecewise_construct, std::make_tuple(tIndex), std::make_tuple());
      }

      // Add the object to the map of mogl objects
      auto pBaseObj = static_cast<base::GLobject *>(pNewObj);

      if (mObjectMap.at(tIndex).find(pBaseObj->getID()) == mObjectMap.at(tIndex).end())
      {
        mObjectMap.at(tIndex)[pBaseObj->getID()] = pNewObj;
      }
      else
      {
        // Should never happen
        throw std::runtime_error("Failed to allocate ModernOpenGL object.");
      }

      // Return our new object to the caller
      return pNewObj;
    };

    /**
     * @brief Get a mogl object by its type and id number. Returns nullptr if failed to find a mogl object.
     * 
     * @tparam T 
     * @param rID 
     * @return T* 
     */
    template <class T>
    T *get(const GLuint &rID)
    {
      static_assert(std::is_base_of<base::GLobject, T>::value);

      std::type_index tIndex = typeid(T);
      if (mObjectMap.find(tIndex) != mObjectMap.end())
      {
        auto &objects = mObjectMap.at(tIndex);
        if (objects.find(rID) != objects.end())
        {
          return dynamic_cast<T *>(objects.at(rID));
        }
      }

      return nullptr;
    }

    /**
     * @brief Free a mogl obj and set the obj pointer to nullptr. If rpObj is not nullptr after return, rpObj was not freed.
     * 
     * @tparam T The type of mogl object to free
     * @param rpObj Referenced pointer to the object to delete
     */
    template <class T>
    void free(T *&rpObj)
    {
      static_assert(std::is_base_of<base::GLobject, T>::value);

      // Cast templated object to base class
      auto pObj = static_cast<base::GLobject *>(rpObj);

      std::type_index tIndex = typeid(T);
      if (mObjectMap.find(tIndex) != mObjectMap.end())
      {
        auto &&objects = mObjectMap.at(tIndex);
        if (objects.find(pObj->getID()) != objects.end())
        {
          // Remove the object from map
          size_t r = objects.erase(pObj->getID());

          // Delete the object
          delete rpObj;
          // Indicate deletion to caller
          rpObj = nullptr;
        }
        else
        {
          throw std::runtime_error("Failed to free ModernOpenGL object.");
        }
      }
      else
      {
        throw std::runtime_error("Failed to free ModernOpenGL object.");
      }
    }

  private:
    /**
     * @brief Free all the allocated objects handled by mogl
     * 
     */
    void freeAllObjects() noexcept;

  private:
    /**
     * @brief ModernOpenGL only supports one active context at a time, for this reason
     * we introduce a static field that tracks whether there is an active context or not
     * 
     */
    static ModernOpenGL *spInstance;

  private:
#if defined(MOGL_OS_WINDOWS)
    HGLRC mContext; // The active OpenGL context
#elif defined(MOGL_OS_LINUX)
    GLXContext mContext;      // The active OpenGL context
    const Display *mpDisplay; // The connection to the XServer for this context
#endif

    // The currently active mogl objects
    std::unordered_map<std::type_index, std::unordered_map<int, base::GLobject *>> mObjectMap;
  };
} // namespace mogl

#endif