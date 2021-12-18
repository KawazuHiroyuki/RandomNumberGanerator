/*****************************************************************//**
 * \file   StdRandomDevice.h
 * \brief  乱数エンジン - std::random_device
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
 * \brief 乱数エンジン - std::random_device
 */
template <typename T1, typename T2>
class StdRandomDevice : public RandomNumberEngine<T1, T2>
{
    using RandomNumberEngine<T1, T2>::ResultType;

    using RandomNumberEngine<T1, T2>::EngineResultType;

    using RandomNumberEngine<T1, T2>::Seed;

    using RandomNumberEngine<T1, T2>::getSeed;

    using Engine = std::random_device;

    static_assert(std::is_same<Engine::result_type, EngineResultType>::value, "");

public:
    /**
     * \brief コンストラクタ
     * \param param 乱数エンジンパラメータ
     * \param seed シード生成器
     */
    StdRandomDevice(std::shared_ptr<RandomNumberEngineParameter<ResultType, EngineResultType>> param, std::shared_ptr<SeedGenerator<Seed>> seed)
        : RandomNumberEngine<ResultType, EngineResultType>(param, seed)
        , m_engine()
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
        // なし
    }

    /**
     * \brief エントロピー(乱数の乱雑さの度合い)を取得
     * \return エントロピー
     */
    double getEntropy(void) const noexcept override
    {
        return m_engine.entropy();
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
     * \brief 予測不能な乱数生成器
     */
    Engine m_engine;
};
} // namespace random_number_generator
