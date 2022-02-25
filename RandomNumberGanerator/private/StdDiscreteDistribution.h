/*****************************************************************//**
 * \file   StdDiscreteDistribution.h
 * \brief  乱数分布
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <initializer_list>
// MyProject
#include "PrimaryRandomNumberDistribution.h"
#include "RandomNumberDistributionUtility.h"

namespace random_number_generator
{
/**
 * \brief 乱数分布 - std::discrete_distribution
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_ = int
>
class StdDiscreteDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdDiscreteDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdDiscreteDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdDiscreteDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief コンストラクタ
     * \param wl 確率列リスト
     */
    StdDiscreteDistribution(std::initializer_list<double> wl)
        : Base(RandomNumberDistributionID::StdDiscrete, Distribution(wl))
    {
    }

    /**
     * \brief コンストラクタ
     * \tparam UnaryOperation 単項関数オブジェクト
     * \param nw 確率列の要素数
     * \param xmin 最小確率
     * \param xmax 最大確率
     * \param fw 確率値を求める単項関数
     */
    template <typename UnaryOperation>
    StdDiscreteDistribution(std::size_t nw, double xmin, double xmax, UnaryOperation fw)
        : Base(RandomNumberDistributionID::StdDiscrete, Distribution(nw, xmin, xmax, fw))
    {
    }
};
} // namespace random_number_generator
