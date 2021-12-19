/*****************************************************************//**
 * \file   RandomNumberGenerator.h
 * \brief  乱数生成器
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <numeric>

#include "private/RandomNumberEngineFactory.h"

#include "RandomNumberEngineParameter.h"
#include "SeedEngineParameter.h"


namespace random_number_generator
{
/**
 * \brief 乱数生成器
 * \tparam ResultType_ ResultType_
 * \tparam EngineResultType_ 乱数エンジンが生成する符号なし整数の型
 */
template <typename ResultType_>
class RandomNumberGenerator
{
public:
    /**
     * \brief 生成する乱数の型
     */
    using ResultType = ResultType_;

public:
    //template <typename Seed>
    RandomNumberGenerator(const RandomNumberEngineParameter& engineParam, const SeedEngineParameter<ResultType_>& seedEngine = {})
        : m_engine()
    {
        switch (engineParam.id) {
            case RandomNumberEngineID::StdRandomDevice:
                m_engine = EngineFactory<StdRandomDevice>::create();
                break;
            //case RandomNumberEngineID::StdLiearCongruential:
            //    break;
            //case RandomNumberEngineID::StdMersenneTwister:
            //    break;
            //case RandomNumberEngineID::StdSubtractWithCarry:
            //    break;
            case RandomNumberEngineID::StdMinStdRand0:
                m_engine = EngineFactory<StdMinStdRand0RandomNumberEngine>::create();
                break;
            case RandomNumberEngineID::StdMinStdRand:
                m_engine = EngineFactory<StdMinStdRandRandomNumberEngine>::create();
                break;
            case RandomNumberEngineID::StdMt199937_32Bit:
                m_engine = EngineFactory<StdMt199937_32BitRandomNumberEngine>::create();
                break;
            case RandomNumberEngineID::StdMt199937_64Bit:
                m_engine = EngineFactory<StdMt199937_64BitRandomNumberEngine>::create();
                break;
            case RandomNumberEngineID::StdRanlux24:
                m_engine = EngineFactory<StdRanlux24RandomNumberEngine>::create();
                break;
            case RandomNumberEngineID::StdRanlux48:
                m_engine = EngineFactory<StdRanlux48RandomNumberEngine>::create();
                break;
            case RandomNumberEngineID::StdKnuth:
                m_engine = EngineFactory<StdKnuthRandomNumberEngine>::create();
                break;
            case RandomNumberEngineID::StdDefaultRandomEngine:
                m_engine = EngineFactory<StdDefaultRandomEngine>::create();
                break;
            default:
                break;
        }
    }

    /**
     * \brief 乱数を生成
     * \return 乱数
     */
    virtual ResultType operator()(void)
    {
        switch (m_engine->getRandomNumberEngineID()) {
            case RandomNumberEngineID::StdRandomDevice:
                return (*getEngine<StdRandomDevice>())();
            case RandomNumberEngineID::StdMinStdRand0:
                return (*getEngine<StdMinStdRand0RandomNumberEngine>())();
            case RandomNumberEngineID::StdMinStdRand:
                return (*getEngine<StdMinStdRandRandomNumberEngine>())();
            case RandomNumberEngineID::StdMt199937_32Bit:
                return (*getEngine<StdMt199937_32BitRandomNumberEngine>())();
            case RandomNumberEngineID::StdMt199937_64Bit:
                return (*getEngine<StdMt199937_64BitRandomNumberEngine>())();
            case RandomNumberEngineID::StdRanlux24:
                return (*getEngine<StdRanlux24RandomNumberEngine>())();
            case RandomNumberEngineID::StdRanlux48:
                return (*getEngine<StdRanlux48RandomNumberEngine>())();
            case RandomNumberEngineID::StdKnuth:
                return (*getEngine<StdKnuthRandomNumberEngine>())();
            case RandomNumberEngineID::StdDefaultRandomEngine:
                return (*getEngine<StdDefaultRandomEngine>())();
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
     * \brief 生成する値の最小値を取得
     * \return 最小値
     */
    ResultType getMin(void) const
    {
        return std::numeric_limits<ResultType>::min();
    }

    /**
     * \brief 生成する値の最大値を取得
     * \return 最大値
     */
    ResultType getMax(void) const
    {
        return std::numeric_limits<ResultType>::max();
    }

    template <typename Engine>
    std::shared_ptr<Engine> getEngine(void) const
    {
        std::shared_ptr<Engine> ptr = std::dynamic_pointer_cast<Engine>(m_engine);
        return ptr;
    }

protected:
    std::shared_ptr<AbstractRandomNumberEngine> m_engine;
};
} // namespace random_number_generator
