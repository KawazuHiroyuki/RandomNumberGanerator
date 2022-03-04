/*****************************************************************//**
 * \file   NoAdaptDistribution.h
 * \brief  分布無適応
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <type_traits>
// MyProject
#include "Parameter/RandomNumberDistributionParameter.h"
#include "AbstractRandomNumberDistribution.h"

namespace random_number_generator
{
/**
 * \brief 分布無適応
 * \tparam DistributionResultType_ 乱数生成結果の型(算術型)
 */
template <
    typename DistributionResultType_
>
class NoAdaptDistribution : public AbstractRandomNumberDistribution<DistributionResultType_>
{
    static_assert(std::is_arithmetic_v<DistributionResultType_>);

private:
    using Base = AbstractRandomNumberDistribution<DistributionResultType_>;

public:
    /**
     * \brief コンストラクタ
     */
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
    virtual DistributionResultType_ operator()(RandomNumberEngine& engine) override
    {
        DistributionResultType_ result = static_cast<DistributionResultType_>(engine());
        return result;
    }

    /**
     * \brief 状態をリセット
     */
    virtual void reset(void) override
    {
    }

    /**
     * \brief 乱数分布IDを取得
     * \return 乱数分布ID
     */
    virtual RandomNumberDistributionID getRandomNumberDistributionID(void) const override
    {
        return m_param.id;
    }

protected:
    /**
     * \brief 乱数分布パラメータ
     */
    RandomNumberDistributionParameter m_param;
};
} // namespace random_number_generator
