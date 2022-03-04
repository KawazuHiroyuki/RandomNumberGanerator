/*****************************************************************//**
 * \file   StdLognormalDistribution.h
 * \brief  対数正規分布
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
 * \brief 対数正規分布
 * \note std::lognormal_distribution
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_ = double
>
class StdLognormalDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdLognormalDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdLognormalDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdLognormalDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief コンストラクタ
     * \param mean 対数正規分布の平均値
     * \param stddev 対数正規分布の標準偏差
     */
    StdLognormalDistribution(DistributionResultType_ mean, DistributionResultType_ stddev)
        : Base(RandomNumberDistributionID::StdLognomarl, Distribution(mean, stddev))
    {
    }
};
} // namespace random_number_generator
