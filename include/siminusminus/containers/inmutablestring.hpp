#ifndef SIMINUSMINUS_CONTAINERS_INMUTABLESTRING_HPP
#define SIMINUSMINUS_CONTAINERS_INMUTABLESTRING_HPP

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
    // TODO
};

}

}

#endif // SIMINUSMINUS_CONTAINERS_INMUTABLESTRING_HPP
