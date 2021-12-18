/*****************************************************************//**
 * \file   SeedGeneratorFactory.h
 * \brief  シード生成器ファクトリ
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <memory>

#include "CurrentTimeSeedGenerator.h"
#include "SeedGenerator.h"
#include "StdRandomDeviceSeedGenerator.h"

namespace random_number_generator
{
/**
 * \brief シード生成器ファクトリ
 */
class SeedGeneratorFactory
{
public:
    template <typename Seed>
    static std::shared_ptr<SeedGenerator<Seed>> create(SeedGeneratorParameter<Seed> param)
    {
        switch (param.id) {
            case SeedGeneratorID::StdRandomDevice:
                return std::make_shared<StdRandomDeviceSeedGenerator<Seed>>();
            case SeedGeneratorID::CurrentTime:
                return std::make_shared <CurrentTimeSeedGenerator<Seed>>();
            case SeedGeneratorID::Custom:
                if (!param.generator) {
                    return nullptr;
                }
                return std::make_shared<SeedGenerator<Seed>>(param);
            default:
                return nullptr;
        }
    }
};
} // namespace random_number_generator
