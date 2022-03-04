/*****************************************************************//**
 * \file   StdExtremeValueDistribution.h
 * \brief  極値分布
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
 * \brief 極値分布
 * \note std::extreme_value_distribution
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_ = double
>
class StdExtremeValueDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdExtremeValueDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdExtremeValueDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdExtremeValueDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief コンストラクタ
     * \param a 極値分布の位置パラメータ
     * \param b 極値分布の尺度パラメータ
     */
    StdExtremeValueDistribution(DistributionResultType_ a, DistributionResultType_ b)
        : Base(RandomNumberDistributionID::StdExtreme, Distribution(a, b))
    {
    }
};
} // namespace random_number_generator
