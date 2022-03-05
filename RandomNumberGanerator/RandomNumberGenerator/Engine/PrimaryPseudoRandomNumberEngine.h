/*****************************************************************//**
 * \file   PrimaryPseudoRandomNumberEngine.h
 * \brief  プライマリ疑似乱数エンジン
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <memory>
// My
#include "Seed/AbstractSeedEngine.h"
#include "Seed/SeedEngineFactory.h"
#include "AbstractPseudoRandomNumberEngine.h"
#include "RandomNumberEngineParameter.h"

namespace random_number_generator
{
/**
 * \brief 疑似乱数エンジン
 * \tparam BaseEngine_ ベース乱数エンジンの型
 * \tparam BaseEngineResultType_ ベース乱数エンジン生成結果の型
 * \tparam SeedEngineResultType_ シードエンジン生成結果の型
 */
template <
    typename BaseEngine_,
    typename BaseEngineResultType_,
    typename SeedEngineResultType_
>
class PrimaryPseudoRandomNumberEngine : public AbstractPseudoRandomNumberEngine<BaseEngineResultType_, AbstractSeedEngine<SeedEngineResultType_>, SeedEngineResultType_>
{
public:
    /**
     * \brief ベース乱数エンジンの型
     */
    using BaseEngine = BaseEngine_;

    /**
     * \brief シードエンジンの型
     */
    using SeedEngine = AbstractSeedEngine<SeedEngineResultType_>;

public:
    /**
     * \brief コンストラクタ
     * \param param 乱数エンジンパラメータ
     * \param seedParam シードエンジンパラメータ
     */
    PrimaryPseudoRandomNumberEngine(const RandomNumberEngineParameter& param, const SeedEngineParameter<SeedEngineResultType_>& seedParam = {})
        : m_param(param)
        , m_seedEngine(SeedEngineFactory<SeedEngineResultType_>::create(seedParam))
        , m_baseEngine(BaseEngine(m_seedEngine->operator()()))
    {
    }

    virtual ~PrimaryPseudoRandomNumberEngine(void) = default;

    /**
     * \brief シードエンジンを設定
     * \param seedEngine シードエンジン
     */
    virtual void setSeedEngine(std::shared_ptr<SeedEngine> seedEngine) override
    {
        m_seedEngine = seedEngine;
    }

    /**
     * \brief 乱数を生成
     * \return 乱数
     */
    virtual BaseEngineResultType_ operator()(void) override
    {
        return m_baseEngine();
    }

    /**
     * \brief 指定した回数だけ疑似乱数を生成し、内部状態を進める
     * \param skip 指定回数
     */
    virtual void discard(std::uint64_t skip) override
    {
        m_baseEngine.discard(skip);
    }

    /**
     * \brief エントロピー(乱数の乱雑さの度合い)を取得
     * \return エントロピー
     */
    double getEntropy(void) const noexcept override
    {
        return 0.0; // 疑似乱数はエントロピー0
    }

    /**
     * \brief 生成する値の最小値を取得
     * \return 最小値
     */
    virtual BaseEngineResultType_ getMin(void) const override
    {
        return BaseEngine::min();
    }

    /**
     * \brief 生成する値の最大値を取得
     * \return 最大値
     */
    virtual BaseEngineResultType_ getMax(void) const override
    {
        return BaseEngine::max();
    }

    /**
     * \brief 乱数エンジンIDを取得
     * \return 乱数エンジンID
     */
    RandomNumberEngineID getRandomNumberEngineID(void) const override
    {
        return m_param.id;
    }

protected:
    /**
     * \brief シードを取得
     * \return シード
     */
    SeedEngineResultType_ getSeed(void) const override
    {
        return (*m_seedEngine)();
    }

protected:
    /**
     * \brief 乱数エンジンパラメータ
     */
    RandomNumberEngineParameter m_param;

    /**
     * \brief シードエンジン
     */
    std::shared_ptr<SeedEngine> m_seedEngine;

    /**
     * \brief ベース乱数エンジン
     */
    BaseEngine m_baseEngine;
};
} // namespace random_number_generator
