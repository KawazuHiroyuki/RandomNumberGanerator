/*****************************************************************//**
 * \file   RandomNumberEngineFactory.h
 * \brief  乱数エンジンファクトリ
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include "../Utility.h"
#include "SeedEngineFactory.h"

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
 * \brief 乱数エンジンファクトリ - std::random_device
 */
class StdRandomDeviceFactory
{
    using Engine = StdRandomDevice<>;

public:
    static std::shared_ptr<AbstractRandomNumberEngine> create(const RandomNumberEngineParameter& engineParam = {})
    {
        auto object = std::make_shared<Engine>();
        return std::dynamic_pointer_cast<AbstractRandomNumberEngine>(object);
    }
};

/**
 * \brief 乱数エンジンファクトリ - パラメータ定義済み用
 */
template <typename Engine_, typename Seed_>
class RandomNumberEngineFactory
{
    using Engine = Engine_;

public:
    static std::shared_ptr<AbstractRandomNumberEngine> create(
        const RandomNumberEngineParameter& engineParam = {},
        const SeedEngineParameter<Seed_>& seedParam = {})
    {
        // TODO Seed_のチェック 
        // ・符号なし整数型に変換可能？
        // ・sizeof(EngineResultType(Engine)) >= sizeof(Seed_)？

        std::shared_ptr<SeedEngine<Seed_>> seed = SeedEngineFactory::create(seedParam);
        auto object = std::make_shared<Engine>(seed);
        return std::dynamic_pointer_cast<AbstractRandomNumberEngine>(object);
    }
};

template <typename Engine, typename Seed = void>
using EngineFactory =
typename utility::Switch<
    utility::Case<std::is_same<StdRandomDevice<>, Engine>::value, StdRandomDeviceFactory>,
    utility::Case<std::is_same<StdMinStdRand0RandomNumberEngine<Seed>, Engine>::value, RandomNumberEngineFactory<StdMinStdRand0RandomNumberEngine<Seed>, Seed>>,
    utility::Case<std::is_same<StdMinStdRandRandomNumberEngine<Seed>, Engine>::value, RandomNumberEngineFactory<StdMinStdRandRandomNumberEngine<Seed>, Seed>>,
    utility::Case<std::is_same<StdMt199937_32BitRandomNumberEngine<Seed>, Engine>::value, RandomNumberEngineFactory<StdMt199937_32BitRandomNumberEngine<Seed>, Seed>>,
    utility::Case<std::is_same<StdMt199937_64BitRandomNumberEngine<Seed>, Engine>::value, RandomNumberEngineFactory<StdMt199937_64BitRandomNumberEngine<Seed>, Seed>>,
    utility::Case<std::is_same<StdRanlux24RandomNumberEngine<Seed>, Engine>::value, RandomNumberEngineFactory<StdRanlux24RandomNumberEngine<Seed>, Seed>>,
    utility::Case<std::is_same<StdRanlux48RandomNumberEngine<Seed>, Engine>::value, RandomNumberEngineFactory<StdRanlux48RandomNumberEngine<Seed>, Seed>>,
    utility::Case<std::is_same<StdKnuthRandomNumberEngine<Seed>, Engine>::value, RandomNumberEngineFactory<StdKnuthRandomNumberEngine<Seed>, Seed>>,
    utility::Case<std::is_same<StdDefaultRandomEngine<Seed>, Engine>::value, RandomNumberEngineFactory<StdDefaultRandomEngine<Seed>, Seed>>
>::type;

#if 0
template <
    typename EngineResultType_,
    EngineResultType_ A,
    EngineResultType_ C,
    EngineResultType_ M
>
class StdLiearCongruentialRandomNumberEngineFactory
{
    //using Engine = StdLiearCongruentialRandomNumberEngine;

public:
    static std::shared_ptr<AbstractRandomNumberEngine> create(
        const RandomNumberEngineParameter& engine = {},
        const SeedEngineParameter<EngineResultType<EngineResultType_>>& seed = {})
    {
        auto object = std::make_shared<StdLiearCongruentialRandomNumberEngine<EngineResultType_, 16807, 0, 2147483647>>(seed);
        return std::dynamic_pointer_cast<AbstractRandomNumberEngine>(object);
    }
};

template <typename EngineResultType_,
    std::size_t W, std::size_t N, std::size_t M, std::size_t R,
    EngineResultType_ A, std::size_t U, EngineResultType_ D, std::size_t S,
    EngineResultType_ B, std::size_t T,
    EngineResultType_ C, std::size_t L, EngineResultType_ F
>
class StdMersenneTwisterRandomNumberEngineFactory
{
public:
    static std::shared_ptr<AbstractRandomNumberEngine> create(
        const RandomNumberEngineParameter& engine = {},
        const SeedEngineParameter<EngineResultType<EngineResultType_>>& seed = {})
    {
        auto object = std::make_shared<StdMersenneTwisterRandomNumberEngine<EngineResultType_,
            32, 624, 397, 31,
            0x9908b0df, 11, 0xffffffff, 7,
            0x9d2c5680, 15, 0xefc60000, 18, 1812433253>>
            (seed);
        return std::dynamic_pointer_cast<AbstractRandomNumberEngine>(object);
    }
};

template <
    typename EngineResultType_,
    std::size_t W,
    std::size_t S,
    std::size_t R
>
class StdSubtractWithCarryRandomNumberEngineFactory
{
public:
    static std::shared_ptr<AbstractRandomNumberEngine> create(
        const RandomNumberEngineParameter& engine = {},
        const SeedEngineParameter<EngineResultType<EngineResultType_>>& seed = {})
    {
        auto object = std::make_shared<StdSubtractWithCarryRandomNumberEngine<EngineResultType_, 24, 10, 24>>(seed);
        return std::dynamic_pointer_cast<AbstractRandomNumberEngine>(object);
    }
};
#endif
} // namespace random_number_generator
