#include "Util.h"
#include "random"

namespace mk_robotics
{
    namespace util
    {
        int randomIntFromRange(int min, int max)
        {
            std::random_device rdev;
            std::mt19937 rgen(rdev());
            std::uniform_int_distribution<int> idist(min, max);
            return idist(rgen);
        }
    }
}