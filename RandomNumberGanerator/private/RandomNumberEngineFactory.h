/*****************************************************************//**
 * \file   RandomNumberEngineFactory.h
 * \brief  乱数エンジンファクトリ
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

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
    /**
     * \brief 乱数エンジンを生成
     * \param param 乱数エンジンパラメータ
     * \param seed シードエンジン
     * \return 乱数エンジン
     */
    template <typename ResultType_, typename EngineResultType_>
    static std::shared_ptr<RandomNumberEngine<ResultType_, EngineResultType_>> create(
        std::shared_ptr<RandomNumberEngineParameter<ResultType_, EngineResultType_>> param = makeRandomNumberEngineParameter<ResultType_, EngineResultType_>(),
        std::shared_ptr<SeedEngine<EngineResultType_>> seed = SeedEngineFactory::create<EngineResultType_>())
    {
        switch (param->id) {
            case RandomNumberEngineID::StdRandomDevice:
                return std::make_shared<StdRandomDevice<ResultType_, EngineResultType_>>();
            case RandomNumberEngineID::StdLiearCongruential:
                return std::make_shared<StdLiearCongruentialRandomNumberEngine<ResultType_, EngineResultType_,
                    16807, 0, 2147483647>>
                    (seed);
                // TODO パラメータ
            case RandomNumberEngineID::StdMersenneTwister:
                return std::make_shared<StdMersenneTwisterRandomNumberEngine<ResultType_, EngineResultType_,
                    32, 624, 397, 31,
                    0x9908b0df, 11, 0xffffffff, 7,
                    0x9d2c5680, 15, 0xefc60000, 18, 1812433253>>
                    (seed);
            case RandomNumberEngineID::StdSubtractWithCarry:
                return std::make_shared<StdSubtractWithCarryRandomNumberEngine<ResultType_, EngineResultType_,
                    24, 10, 24>>
                    (seed);
            case RandomNumberEngineID::StdMinStdRand0:
                return std::make_shared<StdMinStdRand0RandomNumberEngine<ResultType_, EngineResultType_>>(seed);
            case RandomNumberEngineID::StdMinStdRand:
                return std::make_shared<StdMinStdRandRandomNumberEngine<ResultType_, EngineResultType_>>(seed);
            case RandomNumberEngineID::StdMt199937_32Bit:
                return std::make_shared<StdMt199937_32BitRandomNumberEngine<ResultType_, EngineResultType_>>(seed);
            case RandomNumberEngineID::StdMt199937_64Bit:
                return std::make_shared<StdMt199937_64BitRandomNumberEngine<ResultType_, EngineResultType_>>(seed);
            case RandomNumberEngineID::StdRanlux24:
                return std::make_shared<StdRanlux24RandomNumberEngine<ResultType_, EngineResultType_>>(seed);
            case RandomNumberEngineID::StdRanlux48:
                return std::make_shared<StdRanlux48RandomNumberEngine<ResultType_, EngineResultType_>>(seed);
            case RandomNumberEngineID::StdKnuth:
                return std::make_shared<StdKnuthRandomNumberEngine<ResultType_, EngineResultType_>>(seed);
            case RandomNumberEngineID::StdDefaultRandomEngine:
                return std::make_shared<StdDefaultRandomEngine<ResultType_, EngineResultType_>>(seed);
            default:
                return nullptr;
        }
    }
};
} // namespace random_number_generator
