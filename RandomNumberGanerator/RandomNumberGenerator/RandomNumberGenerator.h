/*****************************************************************//**
 * \file   RandomNumberGenerator.h
 * \brief  乱数生成器
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <numeric>
// My
#include "Engine/RandomNumberEngineFactory.h"
#include "Engine/RandomNumberEngineParameter.h"
#include "Seed/SeedEngineParameter.h"

#if 0
namespace random_number_generator
{
/**
 * \brief 乱数生成器
 * \tparam Result_ 乱数の型
 * \tparam Seed_ シードの型
 */
template <
    typename Result_,
    typename Seed_ = std::uint32_t
>
class RandomNumberGenerator
{
public:
    /**
     * \brief 生成する乱数の型
     */
    using Result = Result_;

    /**
     * \brief シードの型
     */
    using Seed = Seed_;

public:
    RandomNumberGenerator(const RandomNumberEngineParameter& engineParam, const SeedEngineParameter<Seed>& seedParam = {})
        : m_engine()
    {
        switch (engineParam.id) {
            //case RandomNumberEngineID::StdRandomDevice:
            //    m_engine = EngineFactory<StdRandomDevice>::create(engineParam);
            //    break;
            //case RandomNumberEngineID::StdLiearCongruential:
            //    break;
            //case RandomNumberEngineID::StdMersenneTwister:
            //    break;
            //case RandomNumberEngineID::StdSubtractWithCarry:
            //    break;
            case RandomNumberEngineID::StdMinStdRand0:
                m_engine = EngineFactory<StdMinStdRand0RandomNumberEngine<Seed>, Seed>::create(engineParam, seedParam);
                break;
            case RandomNumberEngineID::StdMinStdRand:
                m_engine = EngineFactory<StdMinStdRandRandomNumberEngine<Seed>, Seed>::create(engineParam, seedParam);
                break;
            case RandomNumberEngineID::StdMt199937_32Bit:
                m_engine = EngineFactory<StdMt199937_32BitRandomNumberEngine<Seed>, Seed>::create(engineParam, seedParam);
                break;
            case RandomNumberEngineID::StdMt199937_64Bit:
                m_engine = EngineFactory<StdMt199937_64BitRandomNumberEngine<Seed>, Seed>::create(engineParam, seedParam);
                break;
            case RandomNumberEngineID::StdRanlux24:
                m_engine = EngineFactory<StdRanlux24RandomNumberEngine<Seed>, Seed>::create(engineParam, seedParam);
                break;
            case RandomNumberEngineID::StdRanlux48:
                m_engine = EngineFactory<StdRanlux48RandomNumberEngine<Seed>, Seed>::create(engineParam, seedParam);
                break;
            case RandomNumberEngineID::StdKnuth:
                m_engine = EngineFactory<StdKnuthRandomNumberEngine<Seed>, Seed>::create(engineParam, seedParam);
                break;
            case RandomNumberEngineID::StdDefaultRandomEngine:
                m_engine = EngineFactory<StdDefaultRandomEngine<Seed>, Seed>::create(engineParam, seedParam);
                break;
            default:
                break;
        }
    }

    /**
     * \brief 乱数を生成
     * \return 乱数
     */
    virtual Result operator()(void)
    {
        switch (m_engine->getRandomNumberEngineID()) {
            //case RandomNumberEngineID::StdRandomDevice:
            //    return (*getEngine<StdRandomDevice>())();
            case RandomNumberEngineID::StdMinStdRand0:
                return (*getEngine<StdMinStdRand0RandomNumberEngine<Seed>>())();
            case RandomNumberEngineID::StdMinStdRand:
                return (*getEngine<StdMinStdRandRandomNumberEngine<Seed>>())();
            case RandomNumberEngineID::StdMt199937_32Bit:
                return (*getEngine<StdMt199937_32BitRandomNumberEngine<Seed>>())();
            case RandomNumberEngineID::StdMt199937_64Bit:
                return (*getEngine<StdMt199937_64BitRandomNumberEngine<Seed>>())();
            case RandomNumberEngineID::StdRanlux24:
                return (*getEngine<StdRanlux24RandomNumberEngine<Seed>>())();
            case RandomNumberEngineID::StdRanlux48:
                return (*getEngine<StdRanlux48RandomNumberEngine<Seed>>())();
            case RandomNumberEngineID::StdKnuth:
                return (*getEngine<StdKnuthRandomNumberEngine<Seed>>())();
            case RandomNumberEngineID::StdDefaultRandomEngine:
                return (*getEngine<StdDefaultRandomEngine<Seed>>())();
            default:
                return {};
        }
    }

    /**
     * \brief 指定した回数だけ疑似乱数を生成し、内部状態を進める
     * \param skip 指定回数
     */
    virtual void discard(std::uint64_t skip)
    {
        m_engine->discard(skip);
    }

    /**
     * \brief エントロピー(乱数の乱雑さの度合い)を取得
     * \return エントロピー
     */
    double getEntropy(void) const noexcept
    {
        return m_engine->getEntropy();
    }

    /**
     * \brief 生成する値の最小値を取得
     * \return 最小値
     */
    static constexpr Result getMin(void) noexcept
    {
        return std::numeric_limits<Result>::min();
    }

    /**
     * \brief 生成する値の最大値を取得
     * \return 最大値
     */
    static constexpr Result getMax(void) noexcept
    {
        return std::numeric_limits<Result>::max();
    }

    /**
     * \brief 生成する値の最小値を取得
     * \return 最小値
     */
    Result getEngineMin(void) noexcept
    {
        switch (m_engine->getRandomNumberEngineID()) {
            //case RandomNumberEngineID::StdRandomDevice:
            //    return getEngine<StdRandomDevice>()->getMin();
            case RandomNumberEngineID::StdMinStdRand0:
                return getEngine<StdMinStdRand0RandomNumberEngine<Seed>>()->getMin();
            case RandomNumberEngineID::StdMinStdRand:
                return getEngine<StdMinStdRandRandomNumberEngine<Seed>>()->getMin();
            case RandomNumberEngineID::StdMt199937_32Bit:
                return getEngine<StdMt199937_32BitRandomNumberEngine<Seed>>()->getMin();
            case RandomNumberEngineID::StdMt199937_64Bit:
                return getEngine<StdMt199937_64BitRandomNumberEngine<Seed>>()->getMin();
            case RandomNumberEngineID::StdRanlux24:
                return getEngine<StdRanlux24RandomNumberEngine<Seed>>()->getMin();
            case RandomNumberEngineID::StdRanlux48:
                return getEngine<StdRanlux48RandomNumberEngine<Seed>>()->getMin();
            case RandomNumberEngineID::StdKnuth:
                return getEngine<StdKnuthRandomNumberEngine<Seed>>()->getMin();
            case RandomNumberEngineID::StdDefaultRandomEngine:
                return getEngine<StdDefaultRandomEngine<Seed>>()->getMin();
            default:
                return {};
        }
    }

    /**
     * \brief 生成する値の最大値を取得
     * \return 最大値
     */
    Result getEngineMax(void) noexcept
    {
        switch (m_engine->getRandomNumberEngineID()) {
            //case RandomNumberEngineID::StdRandomDevice:
            //    return getEngine<StdRandomDevice>()->getMax();
            case RandomNumberEngineID::StdMinStdRand0:
                return getEngine<StdMinStdRand0RandomNumberEngine<Seed>>()->getMax();
            case RandomNumberEngineID::StdMinStdRand:
                return getEngine<StdMinStdRandRandomNumberEngine<Seed>>()->getMax();
            case RandomNumberEngineID::StdMt199937_32Bit:
                return getEngine<StdMt199937_32BitRandomNumberEngine<Seed>>()->getMax();
            case RandomNumberEngineID::StdMt199937_64Bit:
                return getEngine<StdMt199937_64BitRandomNumberEngine<Seed>>()->getMax();
            case RandomNumberEngineID::StdRanlux24:
                return getEngine<StdRanlux24RandomNumberEngine<Seed>>()->getMax();
            case RandomNumberEngineID::StdRanlux48:
                return getEngine<StdRanlux48RandomNumberEngine<Seed>>()->getMax();
            case RandomNumberEngineID::StdKnuth:
                return getEngine<StdKnuthRandomNumberEngine<Seed>>()->getMax();
            case RandomNumberEngineID::StdDefaultRandomEngine:
                return getEngine<StdDefaultRandomEngine<Seed>>()->getMax();
            default:
                return {};
        }
    }

protected:
    template <typename Engine>
    std::shared_ptr<Engine> getEngine(void) const
    {
        std::shared_ptr<Engine> ptr = std::dynamic_pointer_cast<Engine>(m_engine);
        return ptr;
    }

protected:
    std::shared_ptr<AbstractRandomNumberEngine<Result, Seed>> m_engine;
};
} // namespace random_number_generator
#endif