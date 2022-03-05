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
 * \tparam Seed_ シードエンジン生成結果の型
 */
template <typename Seed_>
class CurrentTimeSeedEngine : public PrimarySeedEngine<Seed_>
{
public:
    /**
     * \brief コンストラクタ
     */
    CurrentTimeSeedEngine(void)
        : PrimarySeedEngine<Seed_>(SeedEngineParameter<Seed_>{SeedEngineID::CurrentTime, createGenerator()})
    {
    }

private:
    /**
     * \brief シード生成関数を生成
     * \return シード生成関数
     */
    SeedEngineParameter<Seed_>::Generator<Seed_> createGenerator(void) const
    {
        return []() { return static_cast<Seed_>(std::time(nullptr)); };
    }
};
} // namespace random_number_generator
