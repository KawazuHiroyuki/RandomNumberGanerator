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
 * \tparam Engine_ 乱数エンジンの型
 * \tparam EngineResultType_ 乱数エンジン生成結果の型
 * \tparam Seed_ シードの型
 */
template <
    typename Engine_,
    typename EngineResultType_,
    typename Seed_
>
class PrimaryPseudoRandomNumberEngine : public AbstractPseudoRandomNumberEngine<EngineResultType_, AbstractSeedEngine<Seed_>, Seed_>
{
public:
    /**
     * \brief 乱数エンジンの型
     */
    using Engine = Engine_;

    /**
     * \brief シードエンジンの型
     */
    using SeedEngine = AbstractSeedEngine<Seed_>;

    /**
     * \brief シードエンジンパラメータの型
     */
    //using SeedParameter = SeedEngineParameter<Seed_>;

public:
    /**
     * \brief コンストラクタ
     * \param param 乱数エンジンパラメータ
     * \param seedParam シードエンジンパラメータ
     */
    PrimaryPseudoRandomNumberEngine(const RandomNumberEngineParameter& param, const SeedEngineParameter<Seed_>& seedParam = {})
        : m_param(param)
        , m_seed(SeedEngineFactory<Seed_>::create(seedParam))
        , m_engine(Engine(m_seed->operator()()))
    {
    }

    virtual ~PrimaryPseudoRandomNumberEngine(void) = default;

    /**
     * \brief シードエンジンを設定
     * \param seed シードエンジン
     */
    virtual void setSeedEngine(std::shared_ptr<SeedEngine> seed) override
    {
        m_seed = seed;
    }

    /**
     * \brief 乱数を生成
     * \return 乱数
     */
    virtual EngineResultType_ operator()(void) override
    {
        return m_engine();
    }

    /**
     * \brief 指定した回数だけ疑似乱数を生成し、内部状態を進める
     * \param skip 指定回数
     */
    virtual void discard(std::uint64_t skip) override
    {
        m_engine.discard(skip);
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
    virtual EngineResultType_ getMin(void) const override
    {
        return Engine::min();
    }

    /**
     * \brief 生成する値の最大値を取得
     * \return 最大値
     */
    virtual EngineResultType_ getMax(void) const override
    {
        return Engine::max();
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
    Seed_ getSeed(void) const override
    {
        return (*m_seed)();
    }

protected:
    /**
     * \brief 乱数エンジンパラメータ
     */
    RandomNumberEngineParameter m_param;

    /**
     * \brief シードエンジン
     */
    std::shared_ptr<SeedEngine> m_seed;

    /**
     * \brief 乱数エンジン
     */
    Engine m_engine;
};
} // namespace random_number_generator
