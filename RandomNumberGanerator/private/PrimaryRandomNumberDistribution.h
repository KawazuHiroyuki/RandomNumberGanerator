#pragma once

#include "../RandomNumberDistributionParameter.h"
#include "AbstractRandomNumberDistribution.h"

namespace random_number_generator
{
/**
 * \brief 乱数分布
 * \tparam Distribution_乱数分布
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename Distribution_,
    typename DistributionResultType_
>
class PrimaryRandomNumberDistribution : public AbstractRandomNumberDistribution<DistributionResultType_>
{
public:
    /**
     * \brief 乱数分布の型
     */
    using Distribution = Distribution_;

public:
    /**
     * \brief コンストラクタ
     * \param param 乱数分布パラメータ
     * \param distribution 乱数分布
     */
    PrimaryRandomNumberDistribution(const RandomNumberDistributionParameter& param, Distribution&& engine)
        : m_param(param)
        , m_distribution(engine)
    {
    }

    virtual ~PrimaryRandomNumberDistribution(void) = default;

    /**
     * \brief 乱数を生成
     * \param engine 乱数エンジン
     * \return 乱数
     */
    template <typename RandomNumberEngine>
    virtual DistributionResultType_ operator()(RandomNumberEngine& engine) override
    {
        DistributionResultType_ result = m_distribution(engine);
        return result;
    }

    /**
     * \brief 状態をリセット
     */
    virtual void reset(void) override
    {
        m_distribution.reset();
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

    /**
     * \brief 乱数分布
     */
    Distribution m_distribution;
};
} // namespace random_number_generator