/*****************************************************************//**
 * \file   NoAdaptDistribution.h
 * \brief  乱数分布
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

 // MyProject
#include "../RandomNumberDistributionParameter.h"
 #include "AbstractRandomNumberDistribution.h"

namespace random_number_generator
{
/**
 * \brief 乱数分布 - std::uniform_int_distribution
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_
>
class NoAdaptDistribution : public AbstractRandomNumberDistribution<DistributionResultType_>
{
private:
    using Base = AbstractRandomNumberDistribution<DistributionResultType_>;

public:
    NoAdaptDistribution(void)
        : Base()
        , m_param(RandomNumberDistributionID::NoAdapt)
    {
    }

    /**
     * \brief 乱数を生成
     * \param engine 乱数エンジン
     * \return 乱数
     */
    template <typename RandomNumberEngine>
    virtual DistributionResultType operator(RandomNumberEngine& engine) = 0;

    /**
     * \brief 状態をリセット
     */
    virtual void reset(void) = 0;

    /**
     * \brief 乱数分布IDを取得
     * \return 乱数分布ID
     */
    virtual RandomNumberDistributionID getRandomNumberDistributionID(void) const = 0;

protected:
    /**
     * \brief 乱数分布パラメータ
     */
    RandomNumberDistributionParameter m_param;
};
} // namespace random_number_generator
