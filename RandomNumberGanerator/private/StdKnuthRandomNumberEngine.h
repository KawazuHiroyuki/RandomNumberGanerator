/*****************************************************************//**
 * \file   StdKnuthRandomNumberEngine.h
 * \brief  乱数エンジン - std::knuth_b
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <random>

#include "RandomNumberEngine.h"
#include "RandomNumberEngineUtility.h"

namespace random_number_generator
{
/**
 * \brief 乱数エンジン - std::knuth_b
 */
class StdKnuthRandomNumberEngine : public RandomNumberEngine<EngineResultType<StdKnuthRandomNumberEngine>>
{
    using Base = RandomNumberEngine<EngineResultType>;

    using Engine = BaseEngine<StdKnuthRandomNumberEngine>;

public:
    /**
     * \brief コンストラクタ
     * \param seed シードエンジン
     */
    StdKnuthRandomNumberEngine(std::shared_ptr<SeedEngine<Seed>> seed)
        : Base(RandomNumberEngineID::StdKnuth, seed)
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
    static constexpr EngineResultType getMin(void)
    {
        return Engine::min();
    }

    /**
     * \brief 生成する値の最大値を取得
     * \return 最大値
     */
    static constexpr EngineResultType getMax(void)
    {
        return Engine::max();
    }

private:
    /**
     * \brief KnuthのリオーダーアルゴリズムB
     */
    Engine m_engine;
};
} // namespace random_number_generator
