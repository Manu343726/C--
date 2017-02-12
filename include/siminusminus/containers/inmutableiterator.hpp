#ifndef SIMINUSMINUS_CONTAINERS_INMUTABLEITERATOR_HPP
#define SIMINUSMINUS_CONTAINERS_INMUTABLEITERATOR_HPP

#include <algorithm>

namespace cmm {
namespace containers {

/**
 * \ingroup containers
 * \brief iterator to inmutable objects.
 * 
 * The InmutableIterator class allows to create an iterator which cannot be
 * modified, only allows read operations.
 */
template <typename T>
class InmutableIterator : public std::iterator<std::input_iterator_tag, // iterator_category
                                               const T* const           // value_type
                                              > 
{

public:

    /**
     * Default constructor. Init the iterator to null.
     */
    InmutableIterator(): _pointer(nullptr)
    {

    }

    /**
     * Constructor that takes a T object to point to object memory direction.
     * @param object: object of T Type to init the iterator.
     */
    InmutableIterator(const T& object) : _pointer(&object)
    {
        
    }

    /**
     * Copy constructor.
     * @param iit: InmutableIterator<T> object that we'll copy from.
     */
    InmutableIterator(const InmutableIterator<T>& iit): InmutableIterator<T>(*iit._pointer) 
    {

    }

    /**
     * Default destructor. Leaves point to T Object. 
     */
    ~InmutableIterator()
    {
        setDefault();
    }

    /**
     * Assignment operator. Copy the InmutableIterator of right hand side to 
     * the left hand side.
     * @param rhs: the right hand side of the operation.
     */
    InmutableIterator<T>& operator=(const InmutableIterator<T>& rhs)
    {
        if (this == &rhs) // Points to the same data
            return *this; // Not doing the assignment

        setDefault(); // To take precautions

        _pointer = rhs._pointer;

        return *this; // Return the own object
    }

    /**
     * Assignment operator. Set a null value.
     * @param rhs: the right hand side of the operation.
     */
    InmutableIterator<T>& operator=(const std::nullptr_t& rhs)
    {
        setDefault(); // To take precautions

        _pointer = nullptr;

        return *this; // Return the own object
    }

    /**
     * Pre-increment operator that allows go over the object.
     */
    InmutableIterator<T>& operator++()
    {
        ++_pointer;
        return *this;
    }

    /**
     * Post-increment operator that allows go over the object.
     * @param rhs: Syntax operator to can different between pre and postincrement.
     */
    InmutableIterator<T> operator++(int rhs)
    {
        InmutableIterator<T> auxiterator (*this);

        ++_pointer;

        return auxiterator;
    }

    /**
     * Gets the object pointed.
     */
    const T& operator*() const
    {
        return *_pointer;
    }

    /**
     * Given a InmutableIterator object and a output buffer, it writes the string to 
     * the given buffer.
     * @param os: output buffer.
     * @param iit: Inmutable iterator object.
     */
    friend std::ostream& operator<<(std::ostream& os, const InmutableIterator<T>& iit)
    {
        os << iit;

        return os;
    }

    /**
     * Returns true if a T object points to the same as rhs.
     * @param rhs: right hand side object.
     */
    bool operator==(const InmutableIterator<T>& rhs)
    {
        return _pointer == rhs._pointer;
    }

    /**
     * Returns true if a T object not points to the same as rhs.
     * @param rhs: right hand side object.
     */
    bool operator!=(const InmutableIterator<T>& rhs)
    {
        return _pointer != rhs._pointer;
    }


private:

    /**
     * Set a deafult value to InmutableIterator
     */
    void setDefault()
    {
        _pointer = nullptr;
    }

    const T* _pointer;

}; // class InmutableIterator

} // namespace containers
} // namespace cmm

#endif // SIMINUSMINUS_CONTAINERS_INMUTABLESTRING_HPP