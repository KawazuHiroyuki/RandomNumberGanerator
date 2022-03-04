/*****************************************************************//**
 * \file   StdNegativeBinomialDistribution.h
 * \brief  負の二項分布
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
 * \brief 負の二項分布
 * \note std::negative_binomial_distribution
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_ = int
>
class StdNegativeBinomialDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdNegativeBinomialDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdNegativeBinomialDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdNegativeBinomialDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief コンストラクタ
     * \param k 成功数
     * \param p 確率
     */
    StdNegativeBinomialDistribution(DistributionResultType_ k, double p)
        : Base(RandomNumberDistributionID::StdNegaivaBinomial, Distribution(k, p))
    {
    }
};
} // namespace random_number_generator
