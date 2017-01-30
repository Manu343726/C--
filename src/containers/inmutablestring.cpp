#include <siminusminus/containers/inmutablestring.hpp>

namespace cmm{
namespace containers{

////////////////
// Constructors
////////////////

cmm::containers::InmutableString::InmutableString(): _string(nullptr), _length(0)
{
	createString(_length, "");
	cmm::utils::DebugUtilities::log(std::string("+++ InmutableString() called. void string created."));
	stringLog();
}

cmm::containers::InmutableString::InmutableString(const char* string): _string(nullptr), _length(0)
{

	createString(std::strlen(string), string);
	cmm::utils::DebugUtilities::log(std::string("+++ InmutableString(const char* string) called."));
	stringLog();
}

cmm::containers::InmutableString::InmutableString(const InmutableString& istring): InmutableString(istring._string)
{
	cmm::utils::DebugUtilities::log(std::string("+++ InmutableString(const InmutableString& istring). Copy constructor."));
}

//////////////
// Destructor
//////////////

cmm::containers::InmutableString::~InmutableString()
{
	if (_string != nullptr)
	{
		cmm::utils::DebugUtilities::log(std::string("--- ~InmutableString()."));
		stringLog();

		delete(_string);
		_string = nullptr;
		_length = 0;
	}
	else
		cmm::utils::DebugUtilities::log(std::string("--- ~InmutableString(). Nothing to delete, void string."));
}

/////////////
// Operators
/////////////

char cmm::containers::InmutableString::operator[](const size_t index) const
{
	return _string[index];
}

bool cmm::containers::InmutableString::operator==(const InmutableString& rhs) const
{
	return strcmp(this->_string, rhs._string) == 0;
}

bool cmm::containers::InmutableString::operator>(const InmutableString& rhs) const
{
	return strcmp(this->_string, rhs._string) < 0; // -1 means that this is greather than rhs.
}

bool cmm::containers::InmutableString::operator<(const InmutableString& rhs) const
{
	return strcmp(this->_string, rhs._string) > 0; // 1 means that rhs is greather than this.
}

bool cmm::containers::InmutableString::operator>=(const InmutableString& rhs) const
{
	return operator>(rhs) && operator==(rhs);
}

bool cmm::containers::InmutableString::operator<=(const InmutableString& rhs) const
{
	return operator<(rhs) && operator==(rhs);
}

InmutableString& cmm::containers::InmutableString::operator=(const InmutableString& rhs)
{
	cmm::utils::DebugUtilities::log(std::string("*** InmutableString::operator=(const InmutableString& rhs)."));

	if (this == &rhs) // Points to the same data
		return *this; // Not doing the assignment

	if (this->_string) 
		::operator delete(this->_string); // Erase data

	this->_string = nullptr; // To take precautions
	this->_length = 0;       // To take precautions

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

///////////
// Methods
///////////

std::string cmm::containers::InmutableString::toString() const
{
	return std::string(_string);
}

void cmm::containers::InmutableString::createString(const size_t& newLength, const char* newString)
{
	size_t newSize = sizeof(char) * (newLength+1); // Inlude '/0'

	_string = new char(newSize); // Get allocation memory for our string
	_length = newLength;

	std::strcpy(_string, newString); // Copy the string
}

void cmm::containers::InmutableString::stringLog() const
{
	cmm::utils::DebugUtilities::log(std::string("String: " + this->toString()));
	cmm::utils::DebugUtilities::log(std::string("String length: ") + std::to_string(_length), true);
}

} // NAMESPACE containers
} // NAMESPACE cmm