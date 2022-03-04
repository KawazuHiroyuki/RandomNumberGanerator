/*****************************************************************//**
 * \file   StdGammaDistribution.h
 * \brief  ガンマ分布
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
 * \brief ガンマ分布
 * \note std::gamma_distribution
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_ = double
>
class StdGammaDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdGammaDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdGammaDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdGammaDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief コンストラクタ
     * \param alpha ガンマ分布の形状母数
     * \param beta ガンマ分布の尺度母数
     */
    StdGammaDistribution(DistributionResultType_ alpha, DistributionResultType_ beta)
        : Base(RandomNumberDistributionID::StdGamma, Distribution(alpha, beta))
    {
    }
};
} // namespace random_number_generator
