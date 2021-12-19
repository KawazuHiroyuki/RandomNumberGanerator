/*****************************************************************//**
 * \file   StdMinStdRand0RandomNumberEngine.h
 * \brief  乱数エンジン - std::minstd_rand0
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <random>

#include "RandomNumberEngine.h"

namespace random_number_generator
{
/**
 * \brief 乱数エンジン - std::minstd_rand0
 */
template <typename ResultType_, typename EngineResultType_>
class StdMinStdRand0RandomNumberEngine : public RandomNumberEngine<ResultType_, EngineResultType_>
{
    using RandomNumberEngine<ResultType_, EngineResultType_>::ResultType;

    using RandomNumberEngine<ResultType_, EngineResultType_>::EngineResultType;

    using RandomNumberEngine<ResultType_, EngineResultType_>::Seed;

    using RandomNumberEngine<ResultType_, EngineResultType_>::getSeed;

    using Engine = std::minstd_rand0;

    static_assert(std::is_same<Engine::result_type, EngineResultType>::value, "");

public:
    /**
     * \brief コンストラクタ
     * \param param 乱数エンジンパラメータ
     * \param seed シード生成器
     */
    StdMinStdRand0RandomNumberEngine(std::shared_ptr<RandomNumberEngineParameter<ResultType, EngineResultType>> param, std::shared_ptr<SeedEngine<Seed>> seed)
        : RandomNumberEngine<ResultType, EngineResultType>(param, seed)
        , m_engine(getSeed())
    {
    }

    /**
     * \brief 乱数を生成
     * \return 乱数
     */
    EngineResultType operator()(void) override
    {
        return m_engine();
    }

    /**
     * \brief 指定した回数だけ疑似乱数を生成し、内部状態を進める
     * \param times 指定回数
     */
    void discard(std::uint64_t skip) override
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
    constexpr EngineResultType getMin(void) const override
    {
        return m_engine.min();
    }

    /**
     * \brief 生成する値の最大値を取得
     * \return 最大値
     */
    constexpr EngineResultType getMax(void) const override
    {
        return m_engine.max();
    }

private:
    /**
     * \brief 最小標準MINSTD
     */
    Engine m_engine;
};
} // namespace random_number_generator
