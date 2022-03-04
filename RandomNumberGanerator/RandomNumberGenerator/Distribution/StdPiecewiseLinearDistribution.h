/*****************************************************************//**
 * \file   StdPiecewiseLinearDistribution.h
 * \brief  指定された区間に線形に分布
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <initializer_list>
// My
#include "PrimaryRandomNumberDistribution.h"
#include "RandomNumberDistributionUtility.h"

namespace random_number_generator
{
/**
 * \brief 指定された区間に線形に分布
 * \note std::piecewise_linear_distribution
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_ = double
>
class StdPiecewiseLinearDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdPiecewiseLinearDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdPiecewiseLinearDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdPiecewiseLinearDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief コンストラクタ
     * \tparam UnaryOperation 単項関数オブジェクト
     * \param bl 区間数列
     * \param fw 重み付けを計算する関数
     */
    template <typename UnaryOperation>
    StdPiecewiseLinearDistribution(std::initializer_list<DistributionResultType_> bl, UnaryOperation fw)
        : Base(RandomNumberDistributionID::StdPiecewiseLinear, Distribution(bl))
    {
    }

    /**
     * \brief コンストラクタ
     * \tparam UnaryOperation 単項関数オブジェクト
     * \param nw 区間列の要素数
     * \param xmin 区間の最小値
     * \param xmax 区間の最大値
     * \param fw 区間列それぞれのインデックスに対する重み値を求めるための関数
     */
    template <typename UnaryOperation>
    StdPiecewiseLinearDistribution(std::size_t nw, DistributionResultType_ xmin, DistributionResultType_ xmax, UnaryOperation fw)
        : Base(RandomNumberDistributionID::StdPiecewiseLinear, Distribution(nw, xmin, xmax, fw))
    {
    }
};
} // namespace random_number_generator
