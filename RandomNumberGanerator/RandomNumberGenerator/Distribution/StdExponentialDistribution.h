/*****************************************************************//**
 * \file   StdExponentialDistribution.h
 * \brief  指数分布
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
 * \brief 指数分布
 * \note std::exponential_distribution
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_ = double
>
class StdExponentialDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdExponentialDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdExponentialDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdExponentialDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief コンストラクタ
     * \param lambda 指数分布のパラメータ
     */
    StdExponentialDistribution(double lambda)
        : Base(RandomNumberDistributionID::StdExponetial, Distribution(lambda))
    {
    }
};
} // namespace random_number_generator
