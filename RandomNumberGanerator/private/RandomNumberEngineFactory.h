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
#include "StdLiearCongruentialRandomNumberEngine.h"
#include "StdMersenneTwisterRandomNumberEngine.h"
#include "StdSubtractWithCarryRandomNumberEngine.h"

#include "StdMinStdRand0RandomNumberEngine.h"
#include "StdMinStdRandRandomNumberEngine.h"
#include "StdMt199937_32BitRandomNumberEngine.h"
#include "StdMt199937_64BitRandomNumberEngine.h"
#include "StdRanlux24RandomNumberEngine.h"
#include "StdRanlux48RandomNumberEngine.h"
#include "StdKnuthRandomNumberEngine.h"

#include "StdDefaultRandomEngine.h"

namespace random_number_generator
{
//template<typename A>
//inline std::shared_ptr<A> a = std::make_shared<A>();

//static inline std::shared_ptr<int> a = std::make_shared<int>();

/**
 * \brief 乱数エンジンファクトリ
 */
class RandomNumberEngineFactory
{
public:
    //template <typename Engine>
    //using BaseEngine =
    //    typename utility::Switch<
    //    utility::Case<std::is_same<StdRandomDevice, Engine>::value, std::random_device>,
    //    utility::Case<std::is_same<StdMinStdRand0RandomNumberEngine, Engine>::value, std::minstd_rand0>,
    //    utility::Case<std::is_same<StdMinStdRandRandomNumberEngine, Engine>::value, std::minstd_rand>,
    //    utility::Case<std::is_same<StdMt199937_32BitRandomNumberEngine, Engine>::value, std::mt19937>,
    //    utility::Case<std::is_same<StdMt199937_64BitRandomNumberEngine, Engine>::value, std::mt19937_64>,
    //    utility::Case<std::is_same<StdRanlux24RandomNumberEngine, Engine>::value, std::ranlux24>,
    //    utility::Case<std::is_same<StdRanlux48RandomNumberEngine, Engine>::value, std::ranlux48>,
    //    utility::Case<std::is_same<StdKnuthRandomNumberEngine, Engine>::value, std::knuth_b>,
    //    utility::Case<std::is_same<StdDefaultRandomEngine, Engine>::value, std::default_random_engine>,
    //    >::type;

    //template <typename Engine>
    //using EngineResultType = BaseEngine<Engine>::result_type;


public:
    /**
     * \brief 乱数エンジンを生成
     * \param param 乱数エンジンパラメータ
     * \param seed シードエンジン
     * \return 乱数エンジン
     */
    template <typename EngineResultType_>
    static std::shared_ptr<AbstractRandomNumberEngine> create(
        std::shared_ptr<RandomNumberEngineParameter<EngineResultType_>> param = makeRandomNumberEngineParameter<EngineResultType_>(),
        std::shared_ptr<SeedEngine<EngineResultType_>> seed = SeedEngineFactory::create<EngineResultType_>())
    {
        std::shared_ptr<AbstractRandomNumberEngine> object;
        switch (param->id) {
            case RandomNumberEngineID::StdRandomDevice:
                object = std::make_shared<StdRandomDevice>();
                break;
            case RandomNumberEngineID::StdLiearCongruential:
                object = std::make_shared<StdLiearCongruentialRandomNumberEngine<EngineResultType_,
                    16807, 0, 2147483647>>
                    (seed);
                // TODO パラメータ
                break;
            case RandomNumberEngineID::StdMersenneTwister:
                object = std::make_shared<StdMersenneTwisterRandomNumberEngine<EngineResultType_,
                    32, 624, 397, 31,
                    0x9908b0df, 11, 0xffffffff, 7,
                    0x9d2c5680, 15, 0xefc60000, 18, 1812433253>>
                    (seed);
                break;
            case RandomNumberEngineID::StdSubtractWithCarry:
                object = std::make_shared<StdSubtractWithCarryRandomNumberEngine<EngineResultType_,
                    24, 10, 24>>
                    (seed);
                break;
            case RandomNumberEngineID::StdMinStdRand0:
                object = std::make_shared<StdMinStdRand0RandomNumberEngine>(seed);
                break;
            case RandomNumberEngineID::StdMinStdRand:
                object = std::make_shared<StdMinStdRandRandomNumberEngine>(seed);
                break;
            case RandomNumberEngineID::StdMt199937_32Bit:
                object = std::make_shared<StdMt199937_32BitRandomNumberEngine>(seed);
                break;
#if 0
            case RandomNumberEngineID::StdMt199937_64Bit: // uint64_t
                object = std::make_shared<StdMt199937_64BitRandomNumberEngine>(seed);
                break;
#endif
            case RandomNumberEngineID::StdRanlux24:
                object = std::make_shared<StdRanlux24RandomNumberEngine>(seed);
                break;
#if 0
            case RandomNumberEngineID::StdRanlux48: // uint64_t
                object = std::make_shared<StdRanlux48RandomNumberEngine>(seed);
                break;
#endif
            case RandomNumberEngineID::StdKnuth:
                object = std::make_shared<StdKnuthRandomNumberEngine>(seed);
                break;
            case RandomNumberEngineID::StdDefaultRandomEngine:
                object = std::make_shared<StdDefaultRandomEngine>(seed);
                break;
            default:
                return nullptr;
        }

        return std::dynamic_pointer_cast<RandomNumberEngine<EngineResultType_>>(object);
    }
};
} // namespace random_number_generator
