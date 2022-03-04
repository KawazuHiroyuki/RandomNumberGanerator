/*****************************************************************//**
 * \file   RandomNumberEngineUtility.h
 * \brief  乱数エンジンユーティリティ
 * 
 * \author japan
 * \date   March 2022
 *********************************************************************/

#pragma once

// My
#include "Utility/Utility.h"

namespace random_number_generator
{
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
    utility::Case<std::is_same<Engine, StdRandomDevice>::value, std::random_device>,
    utility::Case<std::is_same<Engine, StdMinStdRand0RandomNumberEngine<Seed>>::value, std::minstd_rand0>,
    utility::Case<std::is_same<Engine, StdMinStdRandRandomNumberEngine<Seed>>::value, std::minstd_rand>,
    utility::Case<std::is_same<Engine, StdMt199937_32BitRandomNumberEngine<Seed>>::value, std::mt19937>,
    utility::Case<std::is_same<Engine, StdMt199937_64BitRandomNumberEngine<Seed>>::value, std::mt19937_64>,
    utility::Case<std::is_same<Engine, StdRanlux24RandomNumberEngine<Seed>>::value, std::ranlux24>,
    utility::Case<std::is_same<Engine, StdRanlux48RandomNumberEngine<Seed>>::value, std::ranlux48>,
    utility::Case<std::is_same<Engine, StdKnuthRandomNumberEngine<Seed>>::value, std::knuth_b>,
    utility::Case<std::is_same<Engine, StdDefaultRandomEngine<Seed>>::value, std::default_random_engine>
    >::type;

template <typename Engine, typename Seed = void>
using EngineResultType = typename BaseEngine<Engine, Seed>::result_type;
} // namespace random_number_generator
