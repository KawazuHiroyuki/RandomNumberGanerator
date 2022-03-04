﻿/*****************************************************************//**
 * \file   StdWeibullDistribution.h
 * \brief  ワイブル分布
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// My
#include "PrimaryRandomNumberDistribution.h"
#include "RandomNumberBaseDistribution.h"

namespace random_number_generator
{
/**
 * \brief ワイブル分布
 * \note std::weibull_distribution
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_ = double
>
class StdWeibullDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdWeibullDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdWeibullDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdWeibullDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief コンストラクタ
     * \param a ワイプル分布の形状パラメータ
     * \param b ワイプル分布の尺度パラメータ
     */
    StdWeibullDistribution(DistributionResultType_ a, DistributionResultType_ b)
        : Base(RandomNumberDistributionID::StdWeibull, Distribution(a, b))
    {
    }
};
} // namespace random_number_generator
