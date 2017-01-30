#include <gmock/gmock.h>
#include <siminusminus/containers/inmutablestring.hpp>

using namespace ::testing;
using namespace cmm::containers;

int main(int argc, char **argv)
{
	// #ifdef _DEBUG
	// 	std::cout << "Hola" << std::endl;
	::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    
	// return 0;
}
