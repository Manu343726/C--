#ifndef SIMINUSMINUS_CONTAINERS_CONSTCONTIGUOUSITERATOR_HPP
#define SIMINUSMINUS_CONTAINERS_CONSTCONTIGUOUSITERATOR_HPP

#include <algorithm>

namespace cmm {
namespace containers {

/**
 * \ingroup containers
 * \brief iterator to inmutable objects.
 * 
 * The ConstContiguousIterator template allows to create an iterator which cannot be
 * modified, only allows read operations.
 */
template <typename T>
class ConstContiguousIterator : public std::iterator<std::input_iterator_tag, // iterator_category
                                                    T                         // value_type
                                                    > 
{

public:

    /**
     * Default constructor. Init the iterator to null.
     */
    ConstContiguousIterator(): _pointer(nullptr){}

    /**
     * Constructor that takes a T object to point to object memory direction.
     * @param object: object of T Type to init the iterator.
     */
    ConstContiguousIterator(const T* object) : _pointer(object){}

    /**
     * Copy constructor.
     * @param iit: ConstContiguousIterator<T> object that we'll copy from.
     */
    ConstContiguousIterator(const ConstContiguousIterator<T>& iit): ConstContiguousIterator<T>(iit._pointer){}

    /**
     * Default destructor. Leaves point to T Object. 
     */
    ~ConstContiguousIterator()
    {
        setDefault();
    }

    /**
     * Assignment operator. Copy the ConstContiguousIterator of right hand side to 
     * the left hand side.
     * @param rhs: the right hand side of the operation.
     */
    ConstContiguousIterator<T>& operator=(const ConstContiguousIterator<T>& rhs)
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
    ConstContiguousIterator<T>& operator=(const std::nullptr_t& rhs)
    {
        setDefault(); // To take precautions

        _pointer = nullptr;

        return *this; // Return the own object
    }

    /**
     * Increments the value of ConstContiguousIterator and returns a reference to the result. 
     */
    ConstContiguousIterator<T>& operator++()
    {
        ++_pointer;
        return *this;
    }

    /**
     * Creates a copy of ConstContiguousIterator, increments the value and returns the copy from before the increment. 
     * @param rhs: Syntax operator to differentiate between pre and post increment.
     */
    ConstContiguousIterator<T> operator++(int rhs)
    {
        ConstContiguousIterator<T> auxiterator (*this);

        ++_pointer;

        return auxiterator;
    }

    /**
     * Decrements the value of ConstContiguousIterator and returns a reference to the result. 
     */
    ConstContiguousIterator<T>& operator--()
    {
        --_pointer;
        return *this;
    }

    /**
     * Creates a copy of ConstContiguousIterator, decrements the value and returns the copy from before the decrement. 
     * @param rhs: Syntax operator to differentiate between pre and post decrement.
     */
    ConstContiguousIterator<T> operator--(int rhs)
    {
        ConstContiguousIterator<T> auxiterator (*this);

        --_pointer;

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
     * Given a ConstContiguousIterator object and a output buffer, it writes the string to 
     * the given buffer.
     * @param os: output buffer.
     * @param iit: Inmutable iterator object.
     */
    friend std::ostream& operator<<(std::ostream& os, const ConstContiguousIterator<T>& iit)
    {
        os << iit;

        return os;
    }

    /**
     * Returns true if a T object points to the same as rhs.
     * @param rhs: right hand side object.
     */
    bool operator==(const ConstContiguousIterator<T>& rhs)
    {
        return _pointer == rhs._pointer;
    }

    /**
     * Returns true if a T object not points to the same as rhs.
     * @param rhs: right hand side object.
     */
    bool operator!=(const ConstContiguousIterator<T>& rhs)
    {
        return _pointer != rhs._pointer;
    }


private:

    /**
     * Set a deafult value to ConstContiguousIterator
     */
    void setDefault()
    {
        _pointer = nullptr;
    }

    const T* _pointer;

}; // class InmutableIterator

} // namespace containers
} // namespace cmm

#endif // SIMINUSMINUS_CONTAINERS_CONSTCONTIGUOUSITERATOR_HPP