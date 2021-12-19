/*****************************************************************//**
 * \file   StdLiearCongruentialRandomNumberEngine.h
 * \brief  乱数エンジン - std::linear_congruential_engine
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <random>

#include "RandomNumberEngine.h"
#include "../StdLiearCongruentialRandomNumberEngineParameter.h"

namespace random_number_generator
{
/**
 * \brief 乱数エンジン - std::linear_congruential_engine
 */
template <typename EngineResultType_,
    EngineResultType_ A, EngineResultType_ C, EngineResultType_ M
    //template<class> class Param
>
class StdLiearCongruentialRandomNumberEngine : public RandomNumberEngine<EngineResultType_>
{
    using Base = RandomNumberEngine<EngineResultType_>;

    using Engine = std::linear_congruential_engine<Base::EngineResultType, A, C, M>;

    static_assert(std::is_same<Engine::result_type, Base::EngineResultType>::value, "");

public:
    /**
     * \brief コンストラクタ
     * \param seed シードエンジン
     */
    StdLiearCongruentialRandomNumberEngine(std::shared_ptr<SeedEngine<Base::Seed>> seed)
        : Base(makeRandomNumberEngineParameter<Base::EngineResultType>(RandomNumberEngineID::StdLiearCongruential), seed)
        , m_engine(Base::getSeed())
    {
    }

    /**
     * \brief 乱数を生成
     * \return 乱数
     */
    Base::EngineResultType operator()(void) override
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
    constexpr Base::EngineResultType getMin(void) const override
    {
        return m_engine.min();
    }

    /**
     * \brief 生成する値の最大値を取得
     * \return 最大値
     */
    constexpr Base::EngineResultType getMax(void) const override
    {
        return m_engine.max();
    }

private:
    /**
     * \brief 線形合同法
     */
    Engine m_engine;
};
} // namespace random_number_generator
