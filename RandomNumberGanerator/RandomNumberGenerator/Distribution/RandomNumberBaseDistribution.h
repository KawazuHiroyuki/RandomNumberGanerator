/*****************************************************************//**
 * \file   RandomNumberBaseDistribution.h
 * \brief  乱数分布ユーティリティ
 * 
 * \author japan
 * \date   March 2022
 *********************************************************************/

#pragma once

// C++
#include <random>
// My
#include "Utility/Utility.h"

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
template <typename ResultType>
class StdGeometricDistribution;
template <typename ResultType>
class StdNegativeBinomialDistribution;
template <typename ResultType>
class StdPoissonDistribution;
template <typename ResultType>
class StdExponentialDistribution;
template <typename ResultType>
class StdExponentialDistribution;
template <typename ResultType>
class StdWeibullDistribution;
template <typename ResultType>
class StdExtremeValueDistribution;
template <typename ResultType>
class StdNormalDistribution;
template <typename ResultType>
class StdLognormalDistribution;
template <typename ResultType>
class StdChiSquaredDistribution;
template <typename ResultType>
class StdCauchyDistribution;
template <typename ResultType>
class StdStudentTDistribution;
template <typename ResultType>
class StdDiscreteDistribution;
template <typename ResultType>
class StdPiecewiseConstantDistribution;
template <typename ResultType>
class StdPiecewiseLinearDistribution;

template <typename Distribution, typename ResultType>
using BaseDistribution =
    typename utility::Switch<
    utility::Case<std::is_same<Distribution, StdUniformIntDistribution<ResultType>>::value, std::uniform_int_distribution<ResultType>>,
    utility::Case<std::is_same<Distribution, StdUniformRealDistribution<ResultType>>::value, std::uniform_real_distribution<ResultType>>,
    utility::Case<std::is_same<Distribution, StdBernoulliDistribution<ResultType>>::value, std::bernoulli_distribution>,
    utility::Case<std::is_same<Distribution, StdBinomialDistribution<ResultType>>::value, std::binomial_distribution<ResultType>>,
    utility::Case<std::is_same<Distribution, StdGeometricDistribution<ResultType>>::value, std::geometric_distribution<ResultType>>,
    utility::Case<std::is_same<Distribution, StdNegativeBinomialDistribution<ResultType>>::value, std::negative_binomial_distribution<ResultType>>,
    utility::Case<std::is_same<Distribution, StdPoissonDistribution<ResultType>>::value, std::poisson_distribution<ResultType>>,
    utility::Case<std::is_same<Distribution, StdExponentialDistribution<ResultType>>::value, std::exponential_distribution<ResultType>>,
    utility::Case<std::is_same<Distribution, StdExponentialDistribution<ResultType>>::value, std::gamma_distribution<ResultType>>,
    utility::Case<std::is_same<Distribution, StdWeibullDistribution<ResultType>>::value, std::weibull_distribution<ResultType>>,
    utility::Case<std::is_same<Distribution, StdExtremeValueDistribution<ResultType>>::value, std::extreme_value_distribution<ResultType>>,
    utility::Case<std::is_same<Distribution, StdNormalDistribution<ResultType>>::value, std::normal_distribution<ResultType>>,
    utility::Case<std::is_same<Distribution, StdLognormalDistribution<ResultType>>::value, std::lognormal_distribution<ResultType>>,
    utility::Case<std::is_same<Distribution, StdChiSquaredDistribution<ResultType>>::value, std::chi_squared_distribution<ResultType>>,
    utility::Case<std::is_same<Distribution, StdCauchyDistribution<ResultType>>::value, std::cauchy_distribution<ResultType>>,
    utility::Case<std::is_same<Distribution, StdStudentTDistribution<ResultType>>::value, std::student_t_distribution<ResultType>>,
    utility::Case<std::is_same<Distribution, StdDiscreteDistribution<ResultType>>::value, std::discrete_distribution<ResultType>>,
    utility::Case<std::is_same<Distribution, StdPiecewiseConstantDistribution<ResultType>>::value, std::piecewise_constant_distribution<ResultType>>,
    utility::Case<std::is_same<Distribution, StdPiecewiseLinearDistribution<ResultType>>::value, std::piecewise_linear_distribution<ResultType>>
    >::type;

template <typename Distribution, typename ResultType>
using DistributionResultType = typename BaseDistribution<Distribution, ResultType>::result_type;
} // namespace random_number_generator
