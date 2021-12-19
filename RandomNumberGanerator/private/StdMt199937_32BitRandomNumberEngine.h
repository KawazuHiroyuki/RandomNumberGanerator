/*****************************************************************//**
 * \file   StdMt199937_32BitRandomNumberEngine.h
 * \brief  乱数エンジン - std::mt19937
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
 * \brief 乱数エンジン - std::mt19937
 * \tparam EngineResultType_ 生成する符号なし整数の型
 */
class StdMt199937_32BitRandomNumberEngine : public RandomNumberEngine<std::mt19937::result_type>
{
    using Base = RandomNumberEngine<EngineResultType>;

    using Engine = std::mt19937;

public:
    /**
     * \brief コンストラクタ
     * \param seed シードエンジン
     */
    StdMt199937_32BitRandomNumberEngine(std::shared_ptr<SeedEngine<Seed>> seed)
        : Base(makeRandomNumberEngineParameter<EngineResultType>(RandomNumberEngineID::StdMt199937_32Bit), seed)
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
    EngineResultType getMin(void) const override
    {
        return m_engine.min();
    }

    /**
     * \brief 生成する値の最大値を取得
     * \return 最大値
     */
    EngineResultType getMax(void) const override
    {
        return m_engine.max();
    }

private:
    /**
     * \brief メルセンヌツイスターの32ビット版
     */
    Engine m_engine;
};
} // namespace random_number_generator
