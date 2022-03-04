/*****************************************************************//**
 * \file   StdChiSquaredDistribution.h
 * \brief  カイ二乗分布
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
 * \brief カイ二乗分布
 * \note std::chi_squared_distribution
 * \tparam DistributionResultType_ 乱数生成結果の型(実数)
 */
template <
    typename DistributionResultType_ = double
>
class StdChiSquaredDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdChiSquaredDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdChiSquaredDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdChiSquaredDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief コンストラクタ
     * \param n カイ二乗分布の自由度
     */
    StdChiSquaredDistribution(DistributionResultType_ n)
        : Base(RandomNumberDistributionID::StdChiSquared, Distribution(n))
    {
    }
};
} // namespace random_number_generator
