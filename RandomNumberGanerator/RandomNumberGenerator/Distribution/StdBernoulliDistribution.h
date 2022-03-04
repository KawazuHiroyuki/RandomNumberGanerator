/*****************************************************************//**
 * \file   StdBernoulliDistribution.h
 * \brief  ベルヌーイ分布
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
 * \brief ベルヌーイ分布
 * \note std::bernoulli_distribution
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_
>
class StdBernoulliDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdBernoulliDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdBernoulliDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdBernoulliDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief コンストラクタ
     * \param p 確率
     */
    StdBernoulliDistribution(double p)
        : Base(RandomNumberDistributionID::StdBernoulli, Distribution(p))
    {
    }
};
} // namespace random_number_generator
