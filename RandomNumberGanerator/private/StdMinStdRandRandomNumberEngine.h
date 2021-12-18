/*****************************************************************//**
 * \file   StdMinStdRandRandomNumberEngine.h
 * \brief  乱数エンジン - std::minstd_rand
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
 * \brief 乱数エンジン - std::minstd_rand
 */
template <typename Type, typename EngineType>
class StdMinStdRandRandomNumberEngine : public RandomNumberEngine<Type, EngineType>
{
    static_assert(std::is_same<std::minstd_rand::result_type, EngineType>::value, "");

public:
    /**
     * \brief コンストラクタ
     * \param param 乱数エンジンパラメータ
     * \param seed シード生成器
     */
    StdMinStdRandRandomNumberEngine(std::shared_ptr<RandomNumberEngineParameter<Type, EngineType>> param, std::shared_ptr<SeedGenerator<EngineType>> seed)
        : RandomNumberEngine<Type, EngineType>(param, seed)
        , m_engine(RandomNumberEngine<Type, EngineType>::getSeed())
    {
    }

    /**
     * \brief 乱数を生成
     * \return 乱数
     */
    typename StdMinStdRandRandomNumberEngine::EngineRandom operator()(void) override
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
    constexpr typename StdMinStdRandRandomNumberEngine::EngineRandom getMin(void) const override
    {
        return m_engine.min();
    }

    /**
     * \brief 生成する値の最大値を取得
     * \return 最大値
     */
    constexpr typename StdMinStdRandRandomNumberEngine::EngineRandom getMax(void) const override
    {
        return m_engine.max();
    }

private:
    /**
     * \brief 最小標準MINSTDのパラメータ改良版
     */
    std::minstd_rand m_engine;
};
} // namespace random_number_generator
