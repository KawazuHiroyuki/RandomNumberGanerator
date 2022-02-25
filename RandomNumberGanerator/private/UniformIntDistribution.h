/*****************************************************************//**
 * \file   RandomNumberDistribution.h
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
 * \brief 乱数分布 - std::uniform_int_distribution
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_ = int
>
class UniformIntDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<UniformIntDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<UniformIntDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<UniformIntDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    UniformIntDistribution(DistributionResultType_ low, DistributionResultType_ high)
        : Base(RandomNumberDistributionID::StdIntUniform, Distribution(low, high))
    {
    }
};
} // namespace random_number_generator
