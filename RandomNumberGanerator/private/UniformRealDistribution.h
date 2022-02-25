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
 * \brief 乱数分布 - std::uniform_real_distribution
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_ = double
>
class UniformRealDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<UniformRealDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<UniformRealDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<UniformRealDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief コンストラクタ
     * \param low 下限値
     * \param high 上限値
     */
    UniformRealDistribution(DistributionResultType_ low, DistributionResultType_ high)
        : Base(RandomNumberDistributionID::StdRealUniform, Distribution(low, high))
    {
    }
};
} // namespace random_number_generator
