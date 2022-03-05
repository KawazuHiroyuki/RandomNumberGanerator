/*****************************************************************//**
 * \file   RandomNumberEngineFactory.h
 * \brief  乱数エンジンファクトリ
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// My
#include "Utility/Utility.h"
#include "StdRandomDevice.h"
#include "StdMinStdRand0RandomNumberEngine.h"
#include "StdMinStdRandRandomNumberEngine.h"
#include "StdMt199937_32BitRandomNumberEngine.h"
#include "StdMt199937_64BitRandomNumberEngine.h"
#include "StdRanlux24RandomNumberEngine.h"
#include "StdRanlux48RandomNumberEngine.h"
#include "StdKnuthRandomNumberEngine.h"
#include "StdDefaultRandomEngine.h"
#include "StdLiearCongruentialRandomNumberEngine.h"
#include "StdMersenneTwisterRandomNumberEngine.h"
#include "StdSubtractWithCarryRandomNumberEngine.h"

namespace random_number_generator
{
/**
 * \brief 真性乱数エンジンファクトリ
 * \tparam Engine_ 乱数エンジンの型
 * \tparam EngineResultType_ 乱数エンジン生成結果の型
 */
template <
    typename Engine_,
    typename EngineResultType_
>
class TrueRandomNumberEngineFactory
{
private:
    /**
     * \brief 乱数エンジンの型
     */
    using Engine = Engine_;

    /**
     * \brief 乱数エンジン生成結果の型
     */
    using EngineResultType = EngineResultType_;

public:
    static std::shared_ptr<Engine> create(
        const RandomNumberEngineParameter& engineParam = {})
    {
        return std::make_shared<Engine>();
    }
};

/**
 * \brief 疑似乱数エンジンファクトリ
 * \tparam Engine_ 乱数エンジンの型
 * \tparam EngineResultType_ 乱数エンジン生成結果の型
 * \tparam Seed_ シードの型
 */
template <
    typename Engine_,
    typename EngineResultType_,
    typename Seed_
>
class PseudoRandomNumberEngineFactory
{
private:
    /**
     * \brief 乱数エンジンの型
     */
    using Engine = Engine_;

    /**
     * \brief 乱数エンジン生成結果の型
     */
    using EngineResultType = EngineResultType_;

    /**
     * \brief シードの型
     */
    using Seed = Seed_;

public:
    static std::shared_ptr<Engine> create(
        const RandomNumberEngineParameter& engineParam = {},
        const SeedEngineParameter<Seed>& seedParam = {})
    {
        // TODO Seed_のチェック 
        // ・符号なし整数型に変換可能？
        // ・sizeof(EngineResultType(Engine)) >= sizeof(Seed_)？

        return std::make_shared<Engine>(seedParam);
    }

    template <
        EngineResultType_ A,
        EngineResultType_ C,
        EngineResultType_ M
    >
    static std::shared_ptr<Engine> create(
        const RandomNumberEngineParameter& engineParam = {},
        const SeedEngineParameter<Seed>& seedParam = {})
    {
        return std::make_shared<Engine>(seedParam);
        //auto object = std::make_shared<StdLiearCongruentialRandomNumberEngine<EngineResultType_, 16807, 0, 2147483647>>(seed);
    }

    template <
        std::size_t W, std::size_t N, std::size_t M, std::size_t R,
        EngineResultType_ A, std::size_t U, EngineResultType_ D, std::size_t S,
        EngineResultType_ B, std::size_t T,
        EngineResultType_ C, std::size_t L, EngineResultType_ F
    >
    static std::shared_ptr<Engine> create(
        const RandomNumberEngineParameter& engineParam = {},
        const SeedEngineParameter<Seed>& seedParam = {})
    {
        return std::make_shared<Engine>(seedParam);
        //auto object = std::make_shared<StdMersenneTwisterRandomNumberEngine<EngineResultType_,
        //    32, 624, 397, 31,
        //    0x9908b0df, 11, 0xffffffff, 7,
        //    0x9d2c5680, 15, 0xefc60000, 18, 1812433253>>
        //    (seed);
    }

    template <
        typename EngineResultType_,
        std::size_t W,
        std::size_t S,
        std::size_t R
    >
    static std::shared_ptr<Engine> create(
        const RandomNumberEngineParameter& engineParam = {},
        const SeedEngineParameter<Seed>& seedParam = {})
    {
        return std::make_shared<Engine>(seedParam);
        //auto object = std::make_shared<StdSubtractWithCarryRandomNumberEngine<EngineResultType_, 24, 10, 24>>(seed);
        //return std::dynamic_pointer_cast<AbstractRandomNumberEngine>(object);
    }
};

/**
 * \brief 乱数エンジンファクトリの型
 * \tparam Engine_ 乱数エンジンの型
 * \tparam Seed_ シードの型
 */
template <typename Engine, typename Seed = void>
using EngineFactory =
typename utility::Switch<
    utility::Case<std::is_same<Engine, StdRandomDevice>::value, TrueRandomNumberEngineFactory<StdRandomDevice, BaseEngineResultType<StdRandomDevice>>>,
    utility::Case<std::is_same<Engine, StdMinStdRand0RandomNumberEngine<Seed>>::value, PseudoRandomNumberEngineFactory<StdMinStdRand0RandomNumberEngine<Seed>, BaseEngineResultType<StdMinStdRand0RandomNumberEngine<Seed>, Seed>, Seed>>,
    utility::Case<std::is_same<Engine, StdMinStdRandRandomNumberEngine<Seed>>::value, PseudoRandomNumberEngineFactory<StdMinStdRandRandomNumberEngine<Seed>, BaseEngineResultType<StdMinStdRandRandomNumberEngine<Seed>, Seed>, Seed>>,
    utility::Case<std::is_same<Engine, StdMt199937_32BitRandomNumberEngine<Seed>>::value, PseudoRandomNumberEngineFactory<StdMt199937_32BitRandomNumberEngine<Seed>, BaseEngineResultType<StdMt199937_32BitRandomNumberEngine<Seed>, Seed>, Seed>>,
    utility::Case<std::is_same<Engine, StdMt199937_64BitRandomNumberEngine<Seed>>::value, PseudoRandomNumberEngineFactory<StdMt199937_64BitRandomNumberEngine<Seed>, BaseEngineResultType<StdMt199937_64BitRandomNumberEngine<Seed>, Seed>, Seed>>,
    utility::Case<std::is_same<Engine, StdRanlux24RandomNumberEngine<Seed>>::value, PseudoRandomNumberEngineFactory<StdRanlux24RandomNumberEngine<Seed>, BaseEngineResultType<StdRanlux24RandomNumberEngine<Seed>, Seed>, Seed>>,
    utility::Case<std::is_same<Engine, StdRanlux48RandomNumberEngine<Seed>>::value, PseudoRandomNumberEngineFactory<StdRanlux48RandomNumberEngine<Seed>, BaseEngineResultType<StdRanlux48RandomNumberEngine<Seed>, Seed>, Seed>>,
    utility::Case<std::is_same<Engine, StdKnuthRandomNumberEngine<Seed>>::value, PseudoRandomNumberEngineFactory<StdKnuthRandomNumberEngine<Seed>, BaseEngineResultType<StdKnuthRandomNumberEngine<Seed>, Seed>, Seed>>,
    utility::Case<std::is_same<Engine, StdDefaultRandomEngine<Seed>>::value, PseudoRandomNumberEngineFactory<StdDefaultRandomEngine<Seed>, BaseEngineResultType<StdDefaultRandomEngine<Seed>, Seed>, Seed>>
>::type;
} // namespace random_number_generator
