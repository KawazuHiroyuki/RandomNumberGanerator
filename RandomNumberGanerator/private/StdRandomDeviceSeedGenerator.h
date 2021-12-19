/*****************************************************************//**
 * \file   StdRandomDeviceSeedGenerator.h
 * \brief  シード生成器 - std::random_device
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <random>

#include "SeedGenerator.h"

namespace random_number_generator
{
/**
 * \brief シード生成器 - std::random_device
 */
template <typename Seed_>
class StdRandomDeviceSeedGenerator : public SeedGenerator<Seed_>
{
    using SeedGenerator<Seed_>::Seed;

    using Engine = std::random_device;

public:
    /**
     * \brief コンストラクタ
     */
    StdRandomDeviceSeedGenerator(void)
        : SeedGenerator<Seed>(SeedGeneratorParameter<Seed>{
            SeedGeneratorID::StdRandomDevice,
            []() { return Engine()(); }
            })
    {
    }
};
} // namespace random_number_generator
