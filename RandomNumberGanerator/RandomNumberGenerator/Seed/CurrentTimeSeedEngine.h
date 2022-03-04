/*****************************************************************//**
 * \file   CurrentTimeSeedEngine.h
 * \brief  現在時刻 シードエンジン
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <ctime>
// My
#include "SeedEngine.h"

namespace random_number_generator
{
/**
 * \brief シードエンジン - 現在時刻
 * \tparam Seed_ シードの型
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
