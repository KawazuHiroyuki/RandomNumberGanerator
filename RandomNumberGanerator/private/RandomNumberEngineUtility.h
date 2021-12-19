

#pragma once

#include "../Utility.h"

namespace random_number_generator
{
//template <typename Seed>
class StdRandomDevice;
template <typename Seed>
class StdMinStdRand0RandomNumberEngine;
template <typename Seed>
class StdMinStdRandRandomNumberEngine;
template <typename Seed>
class StdMt199937_32BitRandomNumberEngine;
template <typename Seed>
class StdMt199937_64BitRandomNumberEngine;
template <typename Seed>
class StdRanlux24RandomNumberEngine;
template <typename Seed>
class StdRanlux48RandomNumberEngine;
template <typename Seed>
class StdKnuthRandomNumberEngine;
template <typename Seed>
class StdDefaultRandomEngine;

template <typename Engine, typename Seed = void>
using BaseEngine =
    typename utility::Switch<
    utility::Case<std::is_same<StdRandomDevice, Engine>::value, std::random_device>,
    utility::Case<std::is_same<StdMinStdRand0RandomNumberEngine<Seed>, Engine>::value, std::minstd_rand0>,
    utility::Case<std::is_same<StdMinStdRandRandomNumberEngine<Seed>, Engine>::value, std::minstd_rand>,
    utility::Case<std::is_same<StdMt199937_32BitRandomNumberEngine<Seed>, Engine>::value, std::mt19937>,
    utility::Case<std::is_same<StdMt199937_64BitRandomNumberEngine<Seed>, Engine>::value, std::mt19937_64>,
    utility::Case<std::is_same<StdRanlux24RandomNumberEngine<Seed>, Engine>::value, std::ranlux24>,
    utility::Case<std::is_same<StdRanlux48RandomNumberEngine<Seed>, Engine>::value, std::ranlux48>,
    utility::Case<std::is_same<StdKnuthRandomNumberEngine<Seed>, Engine>::value, std::knuth_b>,
    utility::Case<std::is_same<StdDefaultRandomEngine<Seed>, Engine>::value, std::default_random_engine>
    >::type;

template <typename Engine, typename Seed = void>
using EngineResultType = typename BaseEngine<Engine, Seed>::result_type;

//template <typename Engine>
//using Seed = typename BaseEngine<Engine>::result_type;
} // namespace random_number_generator
