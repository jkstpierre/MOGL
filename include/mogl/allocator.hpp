/**
 * @file  mogl/allocator.hpp.
 *
 * Declares the allocator class
 */

#ifndef __MOGL_ALLOCATOR_HPP__
#define __MOGL_ALLOCATOR_HPP__

#include "mogl/objects/object.hpp"

#include <unordered_map>
#include <typeindex>
#include <typeinfo>
#include <stdexcept>

namespace mogl
{
/**
 * The Allocator handles the allocation and freeing of mogl objects
 *
 * @author  jkstpierre
 * @date  8/29/2020
 */
class Allocator final
{
  friend class Context; // Grant context allocation rights
public:
  template <class T, class... Args>
  T* alloc(Args&&... args)
  {
    static_assert(std::is_base_of<Object, T>::value);

    // Create a new OpenGL object
    T* pNewObj = new T(std::forward<Args>(args)...);

    std::type_index tIndex = typeid(T);
    if ( mObjectMap.find(tIndex) == mObjectMap.end() )
    {
      // Create a new entry if necessary
      mObjectMap.emplace(std::piecewise_construct, std::make_tuple(tIndex), std::make_tuple());
    }

    // Add the object to the objects map
    auto pBaseObj = static_cast<Object*>(pNewObj);

    if ( mObjectMap.at(tIndex).find(pBaseObj->getID()) == mObjectMap.at(tIndex).end() )
    {
      mObjectMap.at(tIndex)[pBaseObj->getID()] = pNewObj;
    }
    else
    {
      // Should never happen
      delete pNewObj;
      pNewObj = nullptr;
      throw std::runtime_error("Failed to allocate OpenGL object.");
    }

    // Return the newly created object
    return pNewObj;
  }

  /**
   * Gets an OpenGL Object using the given identifier
   *
   * @tparam  T Generic type parameter.
   * @param   id  The identifier.
   *
   * @returns Null if it fails, else a pointer to a T.
   */
  template <class T>
  T* get(GLuint id) noexcept
  {
    static_assert(std::is_base_of<Object, T>::value);

    std::type_index tIndex = typeid(T);
    if ( mObjectMap.find(tIndex) != mObjectMap.end() )
    {
      auto&& objects = mObjectMap.at(tIndex);
      if ( objects.find(id) != objects.end() )
      {
        return dynamic_cast<T*>(objects.at(id));
      }
    }

    return nullptr;
  }

  /**
   * Frees the given OpenGL object
   *
   * @tparam  T Generic type parameter.
   * @param [in,out]  ppObj If non-null, the object.
   */
  template <class T>
  void free(T** ppObj)
  {
    static_assert(std::is_base_of<Object, T>::value);

    // Cast T to base class Object
    auto pObj = static_cast<Object*>(*ppObj);

    std::type_index tIndex = typeid(T);
    if ( mObjectMap.find(tIndex) != mObjectMap.end() )
    {
      auto&& objects = mObjectMap.at(tIndex);
      if ( objects.find(pObj->getID()) != objects.end() )
      {
        // Remove the object from the map
        objects.erase(pObj->getID());
        delete pObj;
        pObj = nullptr;
      }
      else
      {
        throw std::runtime_error("Failed to free Modern OpenGL object.");
      }
    }
    else
    {
      // TODO: C++20 will allow for nicer string formatting
      throw std::runtime_error("Failed to free Modern OpenGL object.");
    }
  }

private:
  // Default constructor and destructor 
  Allocator() = default;
  ~Allocator() noexcept;

  // Delete copy constructor and copy assignment
  Allocator(const Allocator&) = delete;
  Allocator& operator=(const Allocator&) = delete;

  // Delete move constructor and move assignment
  Allocator(Allocator&&) noexcept = delete;
  Allocator& operator=(Allocator&&) noexcept = delete;

private:
  /**
   * Free all the OpenGL objects in memory
   *
   * @author  jkstpierre
   * @date  8/29/2020
   */
  void freeAll() noexcept;

private:
  /** The map of allocated objects*/
  std::unordered_map<std::type_index, std::unordered_map<GLuint, Object*>> mObjectMap;
};
}

#endif