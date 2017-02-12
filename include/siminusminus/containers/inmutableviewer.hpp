#ifndef SIMINUSMINUS_CONTAINERS_INMUTABLEVIEWER_HPP
#define SIMINUSMINUS_CONTAINERS_INMUTABLEVIEWER_HPP

#include <siminusminus/containers/inmutableiterator.hpp>

namespace cmm {
namespace containers {

/**
 * \ingroup containers
 * \brief Defines a range to iterate.
 * 
 * The InmutableViewer allows to iterate from a range of values. For example
 * we can iterate between integers numbers as [5,10] or memory diretions like 
 * a string also.
 */
template <typename T>
class InmutableViewer : public InmutableIterator<T>
{

public:
    /**
     * Constructor that takes two T objects, from and to, memory directions to iterate.
     * @param from: T object to start the range.
     * @param to: T object that ends the range.
     */
    InmutableViewer(const T& from, const T& to): _begin(from), _end(to)
    {

    }

    /**
     * Constructor that takes two InmutableIterator<T>, from and to, memory directions to iterate.
     * @param from: InmutableIterator<T> object to start the range.
     * @param to: InmutableIterator<T> object that ends the range.
     */
    InmutableViewer(const InmutableIterator<T>& from, const InmutableIterator<T>& to): _begin(from), _end(to)
    {

    }

    /**
     * Returns an InmutableIterator that points to the begining of the range.
     */
    InmutableIterator<T> begin() const
    {
        return _begin;
    }

    /**
     * Returns an InmutableIterator that points to the ending of the range.
     */
    InmutableIterator<T> end() const
    {
        return _end;
    }

private:

    const InmutableIterator<T> _begin; // Begining of the view
    const InmutableIterator<T> _end;   // Ending of the view
    
}; // class InmutableViewer

} // namespace containers
} // namespace cmm

#endif // SIMINUSMINUS_CONTAINERS_INMUTABLESTRING_HPP