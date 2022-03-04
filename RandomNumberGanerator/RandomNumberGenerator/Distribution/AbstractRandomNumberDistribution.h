/*****************************************************************//**
 * \file   AbstractRandomNumberDistribution.h
 * \brief  抽象乱数分布
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// My
#include "RandomNumberDistributionID.h"

namespace random_number_generator
{
/**
 * \brief 抽象乱数分布
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_
>
class AbstractRandomNumberDistribution
{
public:
    /**
     * \brief 乱数分布 生成結果の型
     */
    using DistributionResultType = DistributionResultType_;

public:
    /**
     * \brief 乱数を生成
     * \param engine 乱数エンジン
     * \return 乱数
     */
    template <typename RandomNumberEngine>
    virtual DistributionResultType operator()(RandomNumberEngine& engine) = 0;

    /**
     * \brief 状態をリセット
     */
    virtual void reset(void) = 0;

    /**
     * \brief 乱数分布IDを取得
     * \return 乱数分布ID
     */
    virtual RandomNumberDistributionID getRandomNumberDistributionID(void) const = 0;
};
} // namespace random_number_generator
