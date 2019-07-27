#include "configuration.hh"
#include <iostream>

#ifdef TESTING // Testing is enabled.
#include "gtest/gtest.h"
#endif

int main(int argc, char** argv) {
	#ifdef TESTING // Testing is enabled.
	::testing::InitGoogleTest(&argc, argv);
	#ifdef TESTING_ONLY // We do not want to run the application.
	return RUN_ALL_TESTS();
	#endif
	
	int result = RUN_ALL_TESTS();
	#endif
	
	// code here.
	std::cout << "starting: " << GameEngine_VERSION_MAJOR << ":" << GameEngine_VERSION_MINOR << std::endl;
	
	
	#ifdef TESTING
	return result;
	#endif
	return 0;
}