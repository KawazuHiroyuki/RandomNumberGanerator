/*****************************************************************//**
 * \file   StdPoissonDistribution.h
 * \brief  ポアソン分布
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
 * \brief ポアソン分布
 * \note std::poisson_distribution
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_ = int
>
class StdPoissonDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdPoissonDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdPoissonDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdPoissonDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief コンストラクタ
     * \param mean ポワソン分布の平均値
     */
    StdPoissonDistribution(double mean)
        : Base(RandomNumberDistributionID::StdPoisson, Distribution(mean))
    {
    }
};
} // namespace random_number_generator
