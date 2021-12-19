/*****************************************************************//**
 * \file   RandomNumberEngineFactory.h
 * \brief  乱数エンジンファクトリ
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include "RandomNumberEngine.h"

namespace random_number_generator
{
/**
 * \brief 乱数エンジンファクトリ
 */
class RandomNumberEngineFactory
{
public:
    template <typename ResultType, typename EngineResultType>
    static std::shared_ptr<RandomNumberEngine<ResultType, EngineResultType>> create(
        std::shared_ptr<RandomNumberEngineParameter<ResultType, EngineResultType>> param, std::shared_ptr<SeedEngine<EngineResultType>> seed)
    {
        switch (param->id) {
            case RandomNumberEngineID::StdRandomDevice:
                break;
            case RandomNumberEngineID::StdLiearCongruential:
                break;
            case RandomNumberEngineID::StdMersenneTwister:
                break;
            case RandomNumberEngineID::StdSubtractWithCarry:
                break;
            case RandomNumberEngineID::StdMinStdRand0:
                break;
            case RandomNumberEngineID::StdMinStdRand:
                break;
            case RandomNumberEngineID::StdMt199937_32Bit:
                break;
            case RandomNumberEngineID::StdMt199937_64Bit:
                break;
            case RandomNumberEngineID::StdRanlux24:
                break;
            case RandomNumberEngineID::StdRanlux48:
                break;
            case RandomNumberEngineID::StdKnuth:
                break;
            case RandomNumberEngineID::StdDefaultRandomEngine:
                break;
            default:
                return nullptr;
        }
    }
};
} // namespace random_number_generator
