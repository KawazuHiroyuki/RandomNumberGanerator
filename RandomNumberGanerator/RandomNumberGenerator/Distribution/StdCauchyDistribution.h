/*****************************************************************//**
 * \file   StdCauchyDistribution.h
 * \brief  コーシー分布
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
 * \brief コーシー分布
 * \note std::cauchy_distribution
 * \tparam DistributionResultType_ 乱数生成結果の型(実数)
 */
template <
    typename DistributionResultType_ = double
>
class StdCauchyDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdCauchyDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdCauchyDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdCauchyDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief コンストラクタ
     * \param a コーシー分布の位置母数
     * \param b コーシー分布の尺度母数
     */
    StdCauchyDistribution(DistributionResultType_ a, DistributionResultType_ b)
        : Base(RandomNumberDistributionID::StdCauchy, Distribution(a, b))
    {
    }
};
} // namespace random_number_generator
