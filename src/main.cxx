#include <iostream>

#include "configured_main.hh"

int main(int argc, char** argv) {
	RUN_MAIN({
		// code here.
		std::cout << "starting: " << GameEngine_VERSION_MAJOR << ":" << GameEngine_VERSION_MINOR << std::endl;
	}, argc, argv);
}