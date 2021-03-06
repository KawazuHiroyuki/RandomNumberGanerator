/*****************************************************************//**
 * \file   StdUniformIntDistribution.h
 * \brief  範囲内に一様に分布した整数値
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// My
#include "PrimaryRandomNumberDistribution.h"
#include "RandomNumberBaseDistribution.h"

namespace random_number_generator
{
/**
 * \brief 範囲内に一様に分布した整数値
 * \note std::uniform_int_distribution
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_ = int
>
class StdUniformIntDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdUniformIntDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdUniformIntDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdUniformIntDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief コンストラクタ
     * \param low 下限値
     * \param high 上限値
     */
    StdUniformIntDistribution(DistributionResultType_ low, DistributionResultType_ high)
        : Base(RandomNumberDistributionID::StdIntUniform, Distribution(low, high))
    {
    }
};
} // namespace random_number_generator
