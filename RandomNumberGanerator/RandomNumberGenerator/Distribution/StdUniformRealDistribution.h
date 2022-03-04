﻿/*****************************************************************//**
 * \file   StdUniformRealDistribution.h
 * \brief  範囲内に一様に分布した実数値
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// My
#include "PrimaryRandomNumberDistribution.h"
#include "RandomNumberDistributionUtility.h"

namespace random_number_generator
{
/**
 * \brief 範囲内に一様に分布した実数値
 * \note std::uniform_real_distribution
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_ = double
>
class StdUniformRealDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdUniformRealDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdUniformRealDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdUniformRealDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief コンストラクタ
     * \param low 下限値
     * \param high 上限値
     */
    StdUniformRealDistribution(DistributionResultType_ low, DistributionResultType_ high)
        : Base(RandomNumberDistributionID::StdRealUniform, Distribution(low, high))
    {
    }
};
} // namespace random_number_generator
