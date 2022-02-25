/*****************************************************************//**
 * \file   StdGeometricDistribution.h
 * \brief  乱数分布
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

 // MyProject
#include "PrimaryRandomNumberDistribution.h"
#include "RandomNumberDistributionUtility.h"

namespace random_number_generator
{
/**
 * \brief 乱数分布 - std::geometric_distribution
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_ = int
>
class StdGeometricDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdGeometricDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdGeometricDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdGeometricDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief コンストラクタ
     * \param p 確率
     */
    StdGeometricDistribution(double p)
        : Base(RandomNumberDistributionID::StdGeometric, Distribution(p))
    {
    }
};
} // namespace random_number_generator
