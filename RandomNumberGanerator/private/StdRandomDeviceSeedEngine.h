/*****************************************************************//**
 * \file   StdRandomDeviceSeedGenerator.h
 * \brief  シードエンジン - std::random_device
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <random>

#include "SeedEngine.h"

namespace random_number_generator
{
/**
 * \brief シードエンジン - std::random_device
 */
template <typename Seed_>
class StdRandomDeviceSeedEngine : public SeedEngine<Seed_>
{
    using SeedEngine<Seed_>::Seed;

    /**
     * \brief エンジンの型
     */
    using Engine = std::random_device;

public:
    /**
     * \brief コンストラクタ
     */
    StdRandomDeviceSeedEngine(void)
        : SeedEngine<Seed>(SeedEngineParameter<Seed>{
            SeedEngineID::StdRandomDevice,
            []() { return Engine()(); }
            })
    {
    }
};
} // namespace random_number_generator
