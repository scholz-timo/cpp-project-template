#ifndef DE_RINTO_ENGINE_RUNNER_HH_INCLUDED
#define DE_RINTO_ENGINE_RUNNER_HH_INCLUDED

#include "configuration.hh"

#ifdef TESTING
#include "../tests/include_tests.hh"
#endif // Testing enabled and tests imported.

#ifdef TESTING_ONLY
#define RUN_MAIN(fnc, argc, argv) { \
	::testing::InitGoogleTest(&argc, argv); \
	return RUN_ALL_TESTS(); \
}
#else
#ifdef TESTING
#define RUN_MAIN(fnc, argc, argv) { \
	::testing::InitGoogleTest(&argc, argv); \
	const int result = RUN_ALL_TESTS();\
	\
	[argc, argv] () fnc();\
	\
	return result;\
}
#else
#define RUN_MAIN(fnc, argc, argv) { \
	fnc() \
}
#endif // TESTING
#endif // TESTING_ONLY

#endif // DE_RINTO_ENGINE_RUNNER_HH_INCLUDED