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
#include "Parameter/RandomNumberEngineParameter.h"
#include "Seed/AbstractSeedEngine.h"
#include "AbstractRandomNumberEngine.h"

namespace random_number_generator
{
/**
 * \brief 疑似乱数エンジン
 * \tparam Engine_ エンジンの型
 * \tparam EngineResultType_ 生成する符号なし整数の型
 * \tparam Seed_ シードの型
 */
template <
    typename Engine_,
    typename EngineResultType_,
    typename Seed_ = void
>
class PrimaryPseudoRandomNumberEngine : public AbstractRandomNumberEngine<EngineResultType_, Seed_>
{
public:
    /**
     * \brief エンジンの型
     */
    using Engine = Engine_;

public:
    /**
     * \brief コンストラクタ
     * \param param 乱数エンジンパラメータ
     * \param engine 乱数エンジン
     * \param seed シード生成器
     */
    PrimaryPseudoRandomNumberEngine(const RandomNumberEngineParameter& param, Engine&& engine, std::shared_ptr<AbstractSeedEngine<Seed_>> seed = nullptr)
        : m_param(param)
        , m_engine(engine)
        , m_seed(seed)
    {
    }

    virtual ~PrimaryPseudoRandomNumberEngine(void) = default;

#if 0
    /**
     * \brief シードを設定
     * \param seed シード
     */
    virtual void setSeed(Seed_ seed) override
    {
        m_engine.seed(seed);
    }
#endif

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
    Seed_ getSeed(void) const /*override*/
    {
        return (*m_seed)();
    }

protected:
    /**
     * \brief 乱数エンジンパラメータ
     */
    RandomNumberEngineParameter m_param;

    /**
     * \brief 乱数エンジン
     */
    Engine m_engine;

    /**
     * \brief シードエンジン
     */
    std::shared_ptr<AbstractSeedEngine<Seed_>> m_seed;
};
} // namespace random_number_generator
