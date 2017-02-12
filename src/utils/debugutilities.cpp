#include <siminusminus/utils/debugutilities.hpp>

namespace cmm{
namespace utils{

    void cmm::utils::DebugUtilities::log(const std::string& string)
    {
        #ifndef NDEBUG
            std::cout << string << std::endl;
        #endif
    }

} // NAMESPACE utils
} // NAMESPACE cmm