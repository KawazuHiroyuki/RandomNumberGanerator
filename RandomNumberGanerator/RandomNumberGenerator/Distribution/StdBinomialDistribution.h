/*****************************************************************//**
 * \file   StdBinomialDistribution.h
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
 * \brief 乱数分布 - std::binomial_distribution
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_ = int
>
class StdBinomialDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdBinomialDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdBinomialDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdBinomialDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief コンストラクタ
     * \param t 試行回数
     * \param p 確率
     */
    StdBinomialDistribution(DistributionResultType_ t, double p)
        : Base(RandomNumberDistributionID::StdBinomial, Distribution(t, p))
    {
    }
};
} // namespace random_number_generator
