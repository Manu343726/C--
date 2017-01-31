#include <siminusminus/utils/debugutilities.hpp>

namespace cmm{
namespace utils{

	void cmm::utils::DebugUtilities::log(const std::string& string, bool newline)
	{
		#ifndef NDEBUG
			std::cout << string << std::endl;
			if (newline) // We do this to not mix '/n' and std::endl
				std::cout << std::endl;
		#endif
	}

} // NAMESPACE utils
} // NAMESPACE cmm