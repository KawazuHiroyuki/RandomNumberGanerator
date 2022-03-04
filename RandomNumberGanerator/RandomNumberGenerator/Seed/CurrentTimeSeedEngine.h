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
#include "PrimarySeedEngine.h"

namespace random_number_generator
{
/**
 * \brief 現在時刻 シードエンジン
 * \tparam Seed_ シードの型
 */
template <typename Seed_>
class CurrentTimeSeedEngine : public PrimarySeedEngine<Seed_>
{
    using PrimarySeedEngine<Seed_>::Seed;

public:
    /**
     * \brief コンストラクタ
     */
    CurrentTimeSeedEngine(void)
        : PrimarySeedEngine<Seed>(SeedEngineParameter<Seed>{
            SeedEngineID::CurrentTime,
            []() { return static_cast<Seed>(std::time(nullptr)); }
            })
    {
    }
};
} // namespace random_number_generator
