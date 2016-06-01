/*
* Util class with static functions
*
*/

#include <random>
#include "Utils.h"

unsigned int Utils::GetRandomUIntInRange(unsigned int a, unsigned int b) {
    unsigned int retval = 0;

    std::default_random_engine generator;
    std::uniform_int_distribution<unsigned int> distribution(a, b);

    retval = distribution(generator);

    return retval;
}