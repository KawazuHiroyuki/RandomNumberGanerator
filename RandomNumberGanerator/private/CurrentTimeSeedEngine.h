/*****************************************************************//**
 * \file   CurrentTimeSeedEngine.h
 * \brief  シードエンジン - 現在時刻
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <ctime>

#include "SeedEngine.h"

namespace random_number_generator
{
/**
 * \brief シードエンジン - 現在時刻
 */
template <typename Seed_>
class CurrentTimeSeedEngine : public SeedEngine<Seed_>
{
    using SeedEngine<Seed_>::Seed;

public:
    /**
     * \brief コンストラクタ
     */
    CurrentTimeSeedEngine(void)
        : SeedEngine<Seed>(SeedEngineParameter<Seed>{
            SeedEngineID::CurrentTime,
            []() { return static_cast<Seed>(std::time(nullptr)); }
            })
    {
    }
};
} // namespace random_number_generator
