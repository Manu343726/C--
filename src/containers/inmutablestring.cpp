#include <siminusminus/containers/inmutablestring.hpp>

using namespace cmm::utils;

namespace cmm {
namespace containers {

///////////////////
// InmutableString
///////////////////

InmutableString::InmutableString(): _string(nullptr), _length(0), _begin(), _end()
{
    createString(_length, "");
    DebugUtilities::log(std::string("+++ InmutableString() called. void string created."));
    stringLog();
}

InmutableString::InmutableString(const char* string): _string(nullptr), _length(0), _begin(), _end()
{

    createString(std::strlen(string), string);
    DebugUtilities::log(std::string("+++ InmutableString(const char* string) called."));
    stringLog();
}

InmutableString::InmutableString(const InmutableString& istring): InmutableString(istring._string)
{
    DebugUtilities::log(std::string("+++ InmutableString(const InmutableString& istring). Copy constructor."));
}

InmutableString::InmutableString(InmutableString&& istring): _string(nullptr), _length(0), _begin(), _end()
{
    DebugUtilities::log(std::string("+++ InmutableString(const InmutableString&& istring). Move constructor."));
    stealValues(istring); // points to the same string
    istring.setDefault(); // erase the reference from istring
}

InmutableString::~InmutableString()
{
    if (_string != nullptr)
    {
        DebugUtilities::log(std::string("--- ~InmutableString()."));
        stringLog();

        delete[] _string;
        setDefault(); // To take precautions
    }
    else
        DebugUtilities::log(std::string("--- ~InmutableString(). Nothing to delete, void string."));
}

char& InmutableString::operator[](const size_t index) const
{
    return _string[index];
}

bool InmutableString::operator==(const InmutableString& rhs) const
{
    return std::strcmp(_string, rhs._string) == 0;
}

bool InmutableString::operator>(const InmutableString& rhs) const
{
    InmutableViewer<char> thisViewer(_begin, _end);
    InmutableViewer<char> rhsViewer(rhs._begin, rhs._end);

    return !std::lexicographical_compare(thisViewer.begin(), thisViewer.end(),
                                        rhsViewer.begin(), rhsViewer.end());
}

bool InmutableString::operator<(const InmutableString& rhs) const
{
    InmutableViewer<char> thisViewer(_begin, _end);
    InmutableViewer<char> rhsViewer(rhs._begin, rhs._end);

    return std::lexicographical_compare(thisViewer.begin(), thisViewer.end(),
                                        rhsViewer.begin(), rhsViewer.end());
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
    DebugUtilities::log(std::string("*** InmutableString::operator=(const InmutableString& rhs)."));

    if (this == &rhs) // Points to the same data
        return *this; // Not doing the assignment

    if (_string) 
        delete _string; // Erase data

    setDefault(); // To take precautions

    createString(rhs._length, rhs._string);

    return *this; // Return the own object
}

InmutableString& InmutableString::operator=(InmutableString&& rhs)
{
    DebugUtilities::log(std::string("*** InmutableString::operator=(const InmutableString&& rhs)."));

    stealValues(rhs);
    rhs.setDefault();

    return *this;
}

InmutableString operator+(InmutableString lhs, const InmutableString& rhs)
{
    DebugUtilities::log(std::string("*** operator+(InmutableString lhs, const InmutableString& rhs)."));
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
    size_t newSize = newLength+1; // Inlude '/0'

    _string = new char[newSize]; // Get allocation memory for our string
    _length = newLength;

    std::strcpy(_string, newString); // Copy the string

    _begin = _string[0];
    _end = _string[_length + 2];
}

void InmutableString::stringLog() const
{
    DebugUtilities::log("String: " + toString());
    DebugUtilities::log("String length: " + std::to_string(_length) + "\n");
}

void InmutableString::setDefault()
{
    _string = nullptr;
    _length = 0;
    _begin  = nullptr;
    _end    = nullptr;
}

void InmutableString::stealValues( InmutableString& istring)
{
    _string = istring._string;
    _length = istring._length;
    _begin  = istring._begin;
    _end    = istring._end;
}

} // namespace containers
} // namespace cmm