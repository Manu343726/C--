#ifndef SIMINUSMINUS_UTILS_DEBUGUTILITIES_HPP
#define SIMINUSMINUS_UTILS_DEBUGUTILITIES_HPP

#include <iostream>
#include <string>

namespace cmm {
namespace utils{

/**
 * \ingroup utils
 * \brief Debug helping class.
 *
 * Help class to debug our libraries. We will use the debug macro "NDEBUG" that
 * cmake sets on release builds.
 */
class DebugUtilities
{
public:

    /**
     * Allows show messages on the console when your build type is on Debug.
     * @param string: string to write on console.
     * @param newline: adds the newline special character at the end of the string.
     */
    static void log(const std::string& string, bool newline = false);
   
};

} // namespace utils
} // namespace cmm

#endif // SIMINUSMINUS_UTILS_DEBUGUTILITIES_HPP
