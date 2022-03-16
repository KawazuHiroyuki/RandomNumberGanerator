/*****************************************************************//**
 * \file   RandomNumberBaseEngineFactory.h
 * \brief  乱数ベースエンジンファクトリ
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// My
#include "PrimaryTrueRandomNumberEngine.h" 
#include "PrimaryPseudoRandomNumberEngine.h"
#include "StdRandomDeviceBaseEngineTraits.h"
#include "StdDefaultRandomEngineBaseEngineTraits.h"
#include "StdMinStdRand0BaseEngineTraits.h"

//#include "Utility/Utility.h"
//#include "StdRandomDevice.h"
//#include "StdMinStdRand0RandomNumberEngine.h"
//#include "StdMinStdRandRandomNumberEngine.h"
//#include "StdMt199937_32BitRandomNumberEngine.h"
//#include "StdMt199937_64BitRandomNumberEngine.h"
//#include "StdRanlux24RandomNumberEngine.h"
//#include "StdRanlux48RandomNumberEngine.h"
//#include "StdKnuthRandomNumberEngine.h"
//#include "StdDefaultRandomEngine.h"
//#include "StdLiearCongruentialRandomNumberEngine.h"
//#include "StdMersenneTwisterRandomNumberEngine.h"
//#include "StdSubtractWithCarryRandomNumberEngine.h"

namespace random_number_generator
{

/**
 * \brief 乱数ベースエンジンファクトリ
 * \tparam BaseEngineTraits_ 乱数ベースエンジン特性
 */
template <typename BaseEngineTraits_>
class RandomNumberBaseEngineFactory
{
public:
    /**
     * \brief 乱数ベースエンジン特性
     */
    using BaseEngineTraits = BaseEngineTraits_;

    /**
     * \brief 乱数ベースエンジン
     */
    using BaseEngine = typename BaseEngineTraits::BaseEngine;

    /**
     * \brief デフォルトのシードエンジン生成結果の型
     */
    using DefaultSeedEngineResultType = typename BaseEngineTraits::DefaultSeedEngineResultType;

     /**
      * \brief ベースエンジン生成結果の型
      */
    using BaseEngineResultType = typename BaseEngineTraits::BaseEngineResultType;

    /**
     * \brief 乱数エンジンID
     */
    static constexpr RandomNumberEngineID ENGINE_ID = BaseEngineTraits::ID;
};

/**
 * \brief 疑似乱数ベースエンジンファクトリ
 * \tparam BaseEngineTraits_ 乱数ベースエンジン特性
 */
template <typename BaseEngineTraits_>
class PseudoRandomNumberBaseEngineFactory : public RandomNumberBaseEngineFactory<BaseEngineTraits_>
{
private:
    /**
     * \brief 基底クラス
     */
    using Base = RandomNumberBaseEngineFactory<BaseEngineTraits_>;

public:
    /**
     * \brief 乱数エンジン
     * \tparam SeedEngineResultType シードエンジン生成結果の型
     */
    template <typename SeedEngineResultType>
    using Engine = PrimaryPseudoRandomNumberEngine<Base::BaseEngine, Base::BaseEngineResultType, SeedEngineResultType>;

public:
    /**
     * \brief 乱数エンジンを生成
     * \tparam SeedEngineResultType シードエンジン生成結果の型
     * \param seedParam シートエンジンパラメータ
     * \return 乱数エンジン
     */
    template <typename SeedEngineResultType = Base::DefaultSeedEngineResultType>
    std::shared_ptr<AbstractRandomNumberEngine> create(const SeedEngineParameter<SeedEngineResultType>& seedParam = {})
    {
        RandomNumberEngineParameter engineParam = RandomNumberEngineParameter(Base::ENGINE_ID);
        return std::make_shared<Engine<SeedEngineResultType>>(engineParam, seedParam);
    }
};

/**
 * \brief 真性乱数ベースエンジンファクトリ
 * \tparam BaseEngineTraits_ 乱数ベースエンジン特性
 */
template <typename BaseEngineTraits_>
class TrueRandomNumberBaseEngineFactory : public RandomNumberBaseEngineFactory<BaseEngineTraits_>
{
private:
    /**
     * \brief 基底クラス
     */
    using Base = RandomNumberBaseEngineFactory<BaseEngineTraits_>;

public:
    /**
     * \brief 乱数エンジン
     */
    using Engine = PrimaryTrueRandomNumberEngine<typename Base::BaseEngine, typename Base::BaseEngineResultType>;

public:
    /**
     * \brief 乱数エンジンを生成
     * \return 乱数エンジン
     */
    virtual std::shared_ptr<AbstractRandomNumberEngine> create(void)
    {
        RandomNumberEngineParameter engineParam = RandomNumberEngineParameter(Base::ENGINE_ID);
        return std::make_shared<Engine>(engineParam);
    }
};

/**
 * \brief 予測不能な乱数生成器の乱数ベースエンジンファクトリ
 */
using StdRandomDeviceBaseEngineFactory = TrueRandomNumberBaseEngineFactory<StdRandomDeviceBaseEngineTraits>;

/**
 * \brief 非専門用途でデフォルト使用する擬似乱数生成器の乱数ベースエンジンファクトリ
 */
using StdDefaultRandomEngineBaseEngineFactory = PseudoRandomNumberBaseEngineFactory<StdDefaultRandomEngineBaseEngineTraits>;

/**
 * \brief 最小標準MINSTD擬似乱数生成器の乱数ベースエンジンファクトリ
 */
using StdMinStdRand0BaseEngineFactory = PseudoRandomNumberBaseEngineFactory<StdMinStdRand0BaseEngineTraits>;

#if 0
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
#endif

/**
 * \brief 乱数エンジンファクトリの型
 * \tparam Engine_ 乱数エンジンの型
 * \tparam Seed_ シードの型
 */
//template <typename Engine, typename Seed = void>
//using EngineFactory =
//typename utility::Switch<
//    utility::Case<std::is_same<Engine, StdRandomDevice>::value, TrueRandomNumberEngineFactory<StdRandomDevice, BaseEngineResultType<StdRandomDevice>>>,
//    utility::Case<std::is_same<Engine, StdMinStdRand0RandomNumberEngine<Seed>>::value, PseudoRandomNumberEngineFactory<StdMinStdRand0RandomNumberEngine<Seed>, BaseEngineResultType<StdMinStdRand0RandomNumberEngine<Seed>, Seed>, Seed>>,
//    utility::Case<std::is_same<Engine, StdMinStdRandRandomNumberEngine<Seed>>::value, PseudoRandomNumberEngineFactory<StdMinStdRandRandomNumberEngine<Seed>, BaseEngineResultType<StdMinStdRandRandomNumberEngine<Seed>, Seed>, Seed>>,
//    utility::Case<std::is_same<Engine, StdMt199937_32BitRandomNumberEngine<Seed>>::value, PseudoRandomNumberEngineFactory<StdMt199937_32BitRandomNumberEngine<Seed>, BaseEngineResultType<StdMt199937_32BitRandomNumberEngine<Seed>, Seed>, Seed>>,
//    utility::Case<std::is_same<Engine, StdMt199937_64BitRandomNumberEngine<Seed>>::value, PseudoRandomNumberEngineFactory<StdMt199937_64BitRandomNumberEngine<Seed>, BaseEngineResultType<StdMt199937_64BitRandomNumberEngine<Seed>, Seed>, Seed>>,
//    utility::Case<std::is_same<Engine, StdRanlux24RandomNumberEngine<Seed>>::value, PseudoRandomNumberEngineFactory<StdRanlux24RandomNumberEngine<Seed>, BaseEngineResultType<StdRanlux24RandomNumberEngine<Seed>, Seed>, Seed>>,
//    utility::Case<std::is_same<Engine, StdRanlux48RandomNumberEngine<Seed>>::value, PseudoRandomNumberEngineFactory<StdRanlux48RandomNumberEngine<Seed>, BaseEngineResultType<StdRanlux48RandomNumberEngine<Seed>, Seed>, Seed>>,
//    utility::Case<std::is_same<Engine, StdKnuthRandomNumberEngine<Seed>>::value, PseudoRandomNumberEngineFactory<StdKnuthRandomNumberEngine<Seed>, BaseEngineResultType<StdKnuthRandomNumberEngine<Seed>, Seed>, Seed>>,
//    utility::Case<std::is_same<Engine, StdDefaultRandomEngine<Seed>>::value, PseudoRandomNumberEngineFactory<StdDefaultRandomEngine<Seed>, BaseEngineResultType<StdDefaultRandomEngine<Seed>, Seed>, Seed>>
//>::type;
} // namespace random_number_generator
