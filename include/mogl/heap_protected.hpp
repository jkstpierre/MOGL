/**
 * @file  mogl/heap_protected.hpp.
 *
 * Declares the heap protected class
 */

#ifndef __MOGL_HEAP_PROTECTED_HPP__
#define __MOGL_HEAP_PROTECTED_HPP__

namespace mogl
{
/**
 * An Abstract base class for children to inherit who wish to be kept safe from "delete"
 *
 * @author  jkstpierre
 * @date  9/1/2020
 *
 * @tparam  T Generic type parameter.
 */
template <class T>
class HeapProtected
{
public:
  /**
   * A deleter for smart pointers to use.
   *
   * @author  jkstpierre
   * @date  9/1/2020
   */
  class Deleter
  {
  public:
    /**
     * Function call operator
     *
     * @author  jkstpierre
     * @date  8/31/2020
     *
     * @param [in,out]  pT  If non-null, the attribute.
     */
    void operator()(T* pT)
    {
      delete pT;
    }
  };

protected:
  // Prevent direct instantiation for abstract base class
  HeapProtected() = default;
  virtual ~HeapProtected() = default;

protected:
  /**
   * Object de-allocation operator
   *
   * @author  jkstpierre
   * @date  9/1/2020
   *
   * @param [in,out]  p If non-null, the parameter 1 to delete.
   *
   * @returns The result of the operation.
   */
  void operator delete(void* p)
  {
    free(p);
  }
};
}

#endif