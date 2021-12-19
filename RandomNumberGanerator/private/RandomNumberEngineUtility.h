

#pragma once

#include "../Utility.h"

namespace random_number_generator
{
class StdRandomDevice;
class StdMinStdRand0RandomNumberEngine;
class StdMinStdRandRandomNumberEngine;
class StdMt199937_32BitRandomNumberEngine;
class StdMt199937_64BitRandomNumberEngine;
class StdRanlux24RandomNumberEngine;
class StdRanlux48RandomNumberEngine;
class StdKnuthRandomNumberEngine;
class StdDefaultRandomEngine;

template <typename Engine>
using BaseEngine =
    typename utility::Switch<
    utility::Case<std::is_same<StdRandomDevice, Engine>::value, std::random_device>,
    utility::Case<std::is_same<StdMinStdRand0RandomNumberEngine, Engine>::value, std::minstd_rand0>,
    utility::Case<std::is_same<StdMinStdRandRandomNumberEngine, Engine>::value, std::minstd_rand>,
    utility::Case<std::is_same<StdMt199937_32BitRandomNumberEngine, Engine>::value, std::mt19937>,
    utility::Case<std::is_same<StdMt199937_64BitRandomNumberEngine, Engine>::value, std::mt19937_64>,
    utility::Case<std::is_same<StdRanlux24RandomNumberEngine, Engine>::value, std::ranlux24>,
    utility::Case<std::is_same<StdRanlux48RandomNumberEngine, Engine>::value, std::ranlux48>,
    utility::Case<std::is_same<StdKnuthRandomNumberEngine, Engine>::value, std::knuth_b>,
    utility::Case<std::is_same<StdDefaultRandomEngine, Engine>::value, std::default_random_engine>
    >::type;

template <typename Engine>
using EngineResultType = typename BaseEngine<Engine>::result_type;

template <typename Engine>
using Seed = typename BaseEngine<Engine>::result_type;
} // namespace random_number_generator
