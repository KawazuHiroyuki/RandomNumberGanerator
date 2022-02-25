

#pragma once
// C++
#include <random>
// My
#include "../Utility.h"

namespace random_number_generator
{
template <typename ResultType>
class StdUniformIntDistribution;
template <typename ResultType>
class StdUniformRealDistribution;
template <typename ResultType>
class StdBernoulliDistribution;
template <typename ResultType>
class StdBinomialDistribution;
//template <typename Seed>
//class StdMt199937_64BitRandomNumberEngine;
//template <typename Seed>
//class StdRanlux24RandomNumberEngine;
//template <typename Seed>
//class StdRanlux48RandomNumberEngine;
//template <typename Seed>
//class StdKnuthRandomNumberEngine;
//template <typename Seed>
//class StdDefaultRandomEngine;

template <typename Distribution, typename ResultType>
using BaseDistribution =
    typename utility::Switch<
    utility::Case<std::is_same<Distribution, StdUniformIntDistribution<ResultType>>::value, std::uniform_int_distribution<ResultType>>,
    utility::Case<std::is_same<Distribution, StdUniformRealDistribution<ResultType>>::value, std::uniform_real_distribution<ResultType>>,
    utility::Case<std::is_same<Distribution, StdBernoulliDistribution<ResultType>>::value, std::bernoulli_distribution>,
    utility::Case<std::is_same<Distribution, StdBinomialDistribution<ResultType>>::value, std::binomial_distribution<ResultType>>
    //utility::Case<std::is_same<Engine, StdMt199937_32BitRandomNumberEngine<Seed>>::value, std::mt19937>,
    //utility::Case<std::is_same<Engine, StdMt199937_64BitRandomNumberEngine<Seed>>::value, std::mt19937_64>,
    //utility::Case<std::is_same<Engine, StdRanlux24RandomNumberEngine<Seed>>::value, std::ranlux24>,
    //utility::Case<std::is_same<Engine, StdRanlux48RandomNumberEngine<Seed>>::value, std::ranlux48>,
    //utility::Case<std::is_same<Engine, StdKnuthRandomNumberEngine<Seed>>::value, std::knuth_b>,
    //utility::Case<std::is_same<Engine, StdDefaultRandomEngine<Seed>>::value, std::default_random_engine>
    >::type;


template <typename Distribution, typename ResultType>
using DistributionResultType = typename BaseDistribution<Distribution, ResultType>::result_type;

} // namespace random_number_generator
