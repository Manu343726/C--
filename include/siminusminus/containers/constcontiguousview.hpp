#ifndef SIMINUSMINUS_CONTAINERS_CONSTCONTIGUOUSVIEW_HPP
#define SIMINUSMINUS_CONTAINERS_CONSTCONTIGUOUSVIEW_HPP

#include <siminusminus/containers/constcontiguousiterator.hpp>

namespace cmm {
namespace containers {

/**
 * \ingroup containers
 * \brief Defines a range to iterate.
 * 
 * The ConstContiguousView allows to iterate from a range of values. For example
 * we can iterate between integers numbers as [5,10] or memory diretions like 
 * a string also.
 */
template <typename T>
class ConstContiguousView : public ConstContiguousIterator<T>
{

public:
    /**
     * Constructor that takes two T objects, from and to, memory directions to iterate.
     * @param from: The start of the range.
     * @param to: The end of the range.
     */
    ConstContiguousView(const T* from, const T* to): _begin(from), _end(to){}

    /**
     * Constructor that takes two ConstContiguousIterator<T>, from and to, memory directions to iterate.
     * @param from: ConstContiguousIterator<T> object to start the range.
     * @param to: ConstContiguousIterator<T> object that ends the range.
     */
    ConstContiguousView(const ConstContiguousIterator<T>& from, const ConstContiguousIterator<T>& to): _begin(from), _end(to){}

    /**
     * Returns an ConstContiguousIterator that points to the beginning of the range.
     */
    ConstContiguousIterator<T> begin() const
    {
        return _begin;
    }

    /**
     * Returns an ConstContiguousIterator that points to the end of the range.
     */
    ConstContiguousIterator<T> end() const
    {
        return _end;
    }

private:

    const ConstContiguousIterator<T> _begin; // Beginning of the view
    const ConstContiguousIterator<T> _end;   // Ending of the view
    
}; // class ConstContiguousView

} // namespace containers
} // namespace cmm

#endif // SIMINUSMINUS_CONTAINERS_CONSTCONTIGUOUSVIEW_HPP