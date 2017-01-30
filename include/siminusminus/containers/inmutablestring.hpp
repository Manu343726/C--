#ifndef SIMINUSMINUS_CONTAINERS_INMUTABLESTRING_HPP
#define SIMINUSMINUS_CONTAINERS_INMUTABLESTRING_HPP

#include "siminusminus/utils/debugutilities.hpp"
#include <cstring>

namespace cmm
{

namespace containers
{

/**
 * \ingroup containers
 * \brief Implements an inmutable string
 *
 * Inmutable strings are string objects that cannot be
 * modified after being initialized with a given value.
 * For example:
 *
 * ``` cpp
 * cmm::containers::InmutableString str{"hello, world!"};
 *
 * std::cout << str[0]; // Ok
 * str[0] = 'a'; // Not Ok
 *
 * auto str2 = str + "foo"; // Ok
 * str += "foo"; // Not Ok
 * ```
 */
class InmutableString
{
public:

    /**
     * Default constructor.
     * by default a string with the "" chain is created.
     */
    InmutableString();

    /**
     * Contructor from a C string.
     * @param string: chain to create a InmutableString object.
     */
    InmutableString(const char* string);

    /**
     * Copy constructor. creates a new InmutableString object from another (istring).
     * @param istring: The object which copy the data to create another InmutableSring object.
     */
    InmutableString(const InmutableString& istring);

    /**
     * Default destructor. Free an InmutableString.
     */
    ~InmutableString();

    /**
     * Returns the i th position from our string.
     * @param index: index to string access.
     */
    char operator[](const size_t index) const;

    /**
     * An InmutableString is equal to another if their strings values
     * are the same.
     * @param rhs: the right hand side of the operation.
     */
    bool operator==(const InmutableString& rhs) const;

    /**
     * Returns true if the left hand side has more length than rhs.
     * @param rhs: the right hand side of the operation.
     */
    bool operator>(const InmutableString& rhs) const;

    /**
     * Returns true if the left hand side has less length than rhs.
     * @param rhs: the right hand side of the operation.
     */
    bool operator<(const InmutableString& rhs) const;

    /**
     * Returns true if the left hand side has more or equal length than rhs.
     * @param rhs: the right hand side of the operation.
     */
    bool operator>=(const InmutableString& rhs) const;

    /**
     * Returns true if the left hand side has less or equal length than rhs.
     * @param rhs: the right hand side of the operation.
     */
    bool operator<=(const InmutableString& rhs) const;

    /**
     * Assignment operator. Copy the InmutableString of right hand side to 
     * the left hand side.
     * @param rhs: the right hand side of the operation.
     */
    InmutableString& operator=(const InmutableString& rhs);

    /**
     * Returns the concatenation of lhs and rhs.
     * @param lhs: the left hand side of the operation.
     * @param rhs: the right hand side of the operation.
     */
    friend InmutableString operator+(InmutableString lhs, const InmutableString& rhs);

    /**
     * Given a InmutableString object and a output buffer, it writes the string to 
     * the given buffer.
     * @param os: output buffer.
     * @param istring: Inmutable string object.
     */
    friend std::ostream& operator<<(std::ostream& os, const InmutableString& istring);

    /**
     * Returns an std::string c++ object.
     */
    std::string toString() const;

private:

	/**
     * Create a string on memory.
     * @param newLenght: lenght of the string to create.
     * @param newString: C string.
     */
	void createString(const size_t& newLenght, const char* newString);

	/**
     * For debug. The function returns the length and the string from the
     * InmutableString object.
     */
	void stringLog() const;

	char* _string;  // String value
	size_t _length; // length of the string
};

} // NAMESPACE containers

} // NAMESPACE cmm

#endif // SIMINUSMINUS_CONTAINERS_INMUTABLESTRING_HPP
