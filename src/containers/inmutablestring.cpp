#include <siminusminus/containers/inmutablestring.hpp>

using namespace cmm::utils;

namespace cmm{
namespace containers{

///////////////////
// InmutableString
///////////////////

InmutableString::InmutableString(): _string(nullptr), _length(0)
{
	createString(_length, "");
	cmm::utils::DebugUtilities::log(std::string("+++ InmutableString() called. void string created."));
	stringLog();
}

InmutableString::InmutableString(const char* string): _string(nullptr), _length(0)
{

	createString(std::strlen(string), string);
	cmm::utils::DebugUtilities::log(std::string("+++ InmutableString(const char* string) called."));
	stringLog();
}

InmutableString::InmutableString(const InmutableString& istring): InmutableString(istring._string)
{
	cmm::utils::DebugUtilities::log(std::string("+++ InmutableString(const InmutableString& istring). Copy constructor."));
}

InmutableString::~InmutableString()
{
	if (_string != nullptr)
	{
		cmm::utils::DebugUtilities::log(std::string("--- ~InmutableString()."));
		stringLog();

		delete _string;
		setDefault(); // To take precautions
	}
	else
		cmm::utils::DebugUtilities::log(std::string("--- ~InmutableString(). Nothing to delete, void string."));
}

char InmutableString::operator[](const size_t index) const
{
	return _string[index];
}

bool InmutableString::operator==(const InmutableString& rhs) const
{
	InmutableStringIterator lhsit(this->_string);
	InmutableStringIterator rhsit(rhs._string);

	return !std::lexicographical_compare(lhsit.begin(), lhsit.end(),
								 rhsit.begin(), rhsit.end());
}

bool InmutableString::operator>(const InmutableString& rhs) const
{
	InmutableStringIterator lhsit(this->_string);
	InmutableStringIterator rhsit(rhs._string);

	return std::lexicographical_compare(lhsit.begin(), lhsit.end(),
								 rhsit.begin(), rhsit.end());
}

bool InmutableString::operator<(const InmutableString& rhs) const
{
	InmutableStringIterator lhsit(this->_string);
	InmutableStringIterator rhsit(rhs._string);

	return !std::lexicographical_compare(lhsit.begin(), lhsit.end(),
								 rhsit.begin(), rhsit.end());
}

bool InmutableString::operator>=(const InmutableString& rhs) const
{
	return *this == rhs || *this > rhs;
}

bool InmutableString::operator<=(const InmutableString& rhs) const
{
	return *this == rhs || *this < rhs;
}

InmutableString& InmutableString::operator=(const InmutableString& rhs)
{
	cmm::utils::DebugUtilities::log(std::string("*** InmutableString::operator=(const InmutableString& rhs)."));

	if (this == &rhs) // Points to the same data
		return *this; // Not doing the assignment

	if (this->_string) 
		delete this->_string; // Erase data

	setDefault(); // To take precautions

	createString(rhs._length, rhs._string);

	return *this; // Return the own object
}

InmutableString operator+(InmutableString lhs, const InmutableString& rhs)
{
	cmm::utils::DebugUtilities::log(std::string("*** operator+(InmutableString lhs, const InmutableString& rhs)."));
	lhs.createString(lhs._length + rhs._length, strcat(lhs._string, rhs._string));
	lhs.stringLog();

	return lhs;
}

std::ostream& operator<<(std::ostream& os, const InmutableString& istring)
{
	os << istring._string;

    return os;
}

std::string InmutableString::toString() const
{
	return std::string(_string);
}

void InmutableString::createString(const size_t newLength, const char* newString)
{
	size_t newSize = sizeof(char) * (newLength+1); // Inlude '/0'

	_string = new char[newSize]; // Get allocation memory for our string
	_length = newLength;

	std::strcpy(_string, newString); // Copy the string
}

void InmutableString::stringLog() const
{
	DebugUtilities::log("String: " + this->toString());
	DebugUtilities::log("String length: " + std::to_string(_length), true);
}

void InmutableString::setDefault()
{
	_string = nullptr;
	_length = 0;
}

//////////////////////////
// InmutableStringIterator
//////////////////////////

InmutableStringIterator::InmutableStringIterator(const InmutableString& istring): _istring(istring),
																				  _currentpos(0),
																				  _begin(_istring._string),
																				  _end(&_istring._string[_istring._length])
{

}

InmutableStringIterator::InmutableStringIterator(const InmutableStringIterator& istringit): InmutableStringIterator(istringit._istring)
{

}

InmutableStringIterator& InmutableStringIterator::operator++()
{
	if (!arriveEnd())
		++_currentpos;

	return *this;
}

InmutableStringIterator InmutableStringIterator::operator++(int rhs)
{
	InmutableStringIterator istringit (this->_istring);
	++istringit;
	return istringit;
}

bool InmutableStringIterator::operator==(const InmutableStringIterator& rhs)
{
	return _currentpos == rhs._currentpos;
}

bool InmutableStringIterator::operator!=(const InmutableStringIterator& rhs)
{
	return _currentpos != rhs._currentpos;
}

bool InmutableStringIterator::arriveEnd() const
{
	return _currentpos >= _istring._length;
}

char& InmutableStringIterator::operator*() const
{
	return _istring._string[_currentpos];
}

const char* const InmutableStringIterator::begin() const
{
	return _begin;
}

const char* const InmutableStringIterator::end() const
{
	return _end;
}

} // namespace containers
} // namespace cmm