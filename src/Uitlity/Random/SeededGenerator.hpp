#ifndef DE_RINTO_ENGINE_UITILITY_RANDOM_SEEDEDGENERATOR_HPP_INLUCDED
#define DE_RINTO_ENGINE_UITILITY_RANDOM_SEEDEDGENERATOR_HPP_INLUCDED

#include <cstdlib>

namespace de::rinto::Engine::Utility::Random {
    /**
     * A simple seeded random number generator.
     * 
     * TODO: Maybe use std::mt19937 instead.
     */
    class SeededGenerator {
    protected:
        unsigned int seed;
        unsigned int initialSeed;
        unsigned int seedRandomizer;

    public:
        inline SeededGenerator(unsigned int seed) {
            this->initialSeed = this->seed = seed;
            this->seedRandomizer = seedRandomizer;
        }

        inline ~SeededGenerator() {
        }

        inline void reset() {
            this->seed = initialSeed;
        }

        inline unsigned int get() {
            this->seed = this->seedRandomizer * this->seed + 2396403;
            return seed;
        }
    };
} // namespace de::rinto::Engine::Utility::Random


#endif // DE_RINTO_ENGINE_UITILITY_RANDOM_SEEDEDGENERATOR_HPP_INLUCDED