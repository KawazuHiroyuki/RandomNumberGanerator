/*****************************************************************//**
 * \file   StdNormalDistribution.h
 * \brief  標準正規(ガウス)分布
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
 * \brief 標準正規(ガウス)分布
 * \note std::normal_distribution
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_ = double
>
class StdNormalDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdNormalDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdNormalDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdNormalDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief コンストラクタ
     * \param mean 正規分布の平均値
     * \param stddev 正規分布の標準偏差
     */
    StdNormalDistribution(DistributionResultType_ mean, DistributionResultType_ stddev)
        : Base(RandomNumberDistributionID::StdNormal, Distribution(mean, stddev))
    {
    }
};
} // namespace random_number_generator
