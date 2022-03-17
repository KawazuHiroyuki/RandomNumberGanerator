/*****************************************************************//**
 * \file   AbstractBaseDistributionTraits.h
 * \brief  抽象乱数分布特性
 * 
 * \author japan
 * \date   March 2022
 *********************************************************************/

#pragma once

// C++
#include <random>
// My
#include "RandomNumberDistributionID.h"

namespace random_number_generator
{
/**
 * \brief 抽象乱数分布特性
 * \tparam BaseDistribution_ ベース乱数分布
 * \tparam DefaultDistributionResultType_ デフォルトの乱数分布生成結果の型
 * \tparam ID_ 乱数分布ID
 */
template <
    typename BaseDistribution_,
    typename DefaultDistributionResultType_,
    RandomNumberDistributionID ID_
>
struct AbstractBaseDistributionTraits
{
    /**
     * \brief ベース乱数分布
     */
    using BaseDistribution = BaseDistribution_;

    /**
     * \brief デフォルトの乱数分布生成結果の型
     */
    using DefaultDistributionResultType = DefaultDistributionResultType_;

    /**
     * \brief 乱数分布ID
     */
    static constexpr RandomNumberDistributionID ID = ID_;
};

// TODO 生成結果=指定、生成結果=型固定用に分離


template <typename DefaultDistributionResultType>
using StdUniformIntBaseDistributionTraits = AbstractBaseDistributionTraits<std::uniform_int_distribution<DefaultDistributionResultType>, int, RandomNumberDistributionID::StdIntUniform>;

template <typename DefaultDistributionResultType>
using StdUniformRealBaseDistributionTraits = AbstractBaseDistributionTraits<std::uniform_real_distribution<DefaultDistributionResultType>, double, RandomNumberDistributionID::StdRealUniform>;

//template <typename DefaultDistributionResultType>
using StdBernoulliBaseDistributionTraits = AbstractBaseDistributionTraits<std::bernoulli_distribution, std::bernoulli_distribution::result_type, RandomNumberDistributionID::StdBernoulli>;

template <typename DefaultDistributionResultType>
using StdBinomialBaseDistributionTraits = AbstractBaseDistributionTraits<std::binomial_distribution<DefaultDistributionResultType>, int, RandomNumberDistributionID::StdBinomial>;

template <typename DefaultDistributionResultType>
using StdGeometricBaseDistributionTraits = AbstractBaseDistributionTraits<std::geometric_distribution<DefaultDistributionResultType>, int, RandomNumberDistributionID::StdGeometric>;

template <typename DefaultDistributionResultType>
using StdNegativeBinomialBaseDistributionTraits = AbstractBaseDistributionTraits<std::negative_binomial_distribution<DefaultDistributionResultType>, int, RandomNumberDistributionID::StdNegaivaBinomial>;

template <typename DefaultDistributionResultType>
using StdPoissonBaseDistributionTraits = AbstractBaseDistributionTraits<std::poisson_distribution<DefaultDistributionResultType>, int, RandomNumberDistributionID::StdPoisson>;

template <typename DefaultDistributionResultType>
using StdExponentialBaseDistributionTraits = AbstractBaseDistributionTraits<std::exponential_distribution<DefaultDistributionResultType>, double, RandomNumberDistributionID::StdExponetial>;

template <typename DefaultDistributionResultType>
using StdGammaBaseDistributionTraits = AbstractBaseDistributionTraits<std::gamma_distribution<DefaultDistributionResultType>, double, RandomNumberDistributionID::StdGamma>;

template <typename DefaultDistributionResultType>
using StdWeibullBaseDistributionTraits = AbstractBaseDistributionTraits<std::weibull_distribution<DefaultDistributionResultType>, double, RandomNumberDistributionID::StdWeibull>;

template <typename DefaultDistributionResultType>
using StdExtremeValueBaseDistributionTraits = AbstractBaseDistributionTraits<std::extreme_value_distribution<DefaultDistributionResultType>, double, RandomNumberDistributionID::StdExtreme>;

template <typename DefaultDistributionResultType>
using StdNormalBaseDistributionTraits = AbstractBaseDistributionTraits<std::normal_distribution<DefaultDistributionResultType>, double, RandomNumberDistributionID::StdNormal>;

template <typename DefaultDistributionResultType>
using StdLognormalBaseDistributionTraits = AbstractBaseDistributionTraits<std::lognormal_distribution<DefaultDistributionResultType>, double, RandomNumberDistributionID::StdLognomarl>;

template <typename DefaultDistributionResultType>
using StdChiSquaredBaseDistributionTraits = AbstractBaseDistributionTraits<std::chi_squared_distribution<DefaultDistributionResultType>, double, RandomNumberDistributionID::StdChiSquared>;

template <typename DefaultDistributionResultType>
using StdCauchyBaseDistributionTraits = AbstractBaseDistributionTraits<std::cauchy_distribution<DefaultDistributionResultType>, double, RandomNumberDistributionID::StdCauchy>;

template <typename DefaultDistributionResultType>
using StdFisherFBaseDistributionTraits = AbstractBaseDistributionTraits<std::fisher_f_distribution<DefaultDistributionResultType>, double, RandomNumberDistributionID::StdFisherF>;

template <typename DefaultDistributionResultType>
using StdStudentTBaseDistributionTraits = AbstractBaseDistributionTraits<std::student_t_distribution<DefaultDistributionResultType>, double, RandomNumberDistributionID::StdStudentT>;

template <typename DefaultDistributionResultType>
using StdDiscreteBaseDistributionTraits = AbstractBaseDistributionTraits<std::student_t_distribution<DefaultDistributionResultType>, int, RandomNumberDistributionID::StdDiscrete>;

template <typename DefaultDistributionResultType>
using StdPiecewiseConstantBaseDistributionTraits = AbstractBaseDistributionTraits<std::piecewise_constant_distribution<DefaultDistributionResultType>, double, RandomNumberDistributionID::StdPiecewiseConstant>;

template <typename DefaultDistributionResultType>
using StdPiecewiseLinearBaseDistributionTraits = AbstractBaseDistributionTraits<std::piecewise_linear_distribution<DefaultDistributionResultType>, double, RandomNumberDistributionID::StdPiecewiseLinear>;

} // namespace random_number_generator