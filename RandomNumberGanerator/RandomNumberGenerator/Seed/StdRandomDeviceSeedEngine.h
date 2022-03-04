/*****************************************************************//**
 * \file   StdRandomDeviceSeedGenerator.h
 * \brief  予測不能な乱数生成器 シードエンジン
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <random>
// My
#include "PrimarySeedEngine.h"

namespace random_number_generator
{
/**
 * \brief 予測不能な乱数生成器 シードエンジン
 * \note std::random_device
 * \tparam Seed_ シードの型
 */
template <typename Seed_>
class StdRandomDeviceSeedEngine : public PrimarySeedEngine<Seed_>
{
public:
    /**
     * \brief コンストラクタ
     */
    StdRandomDeviceSeedEngine(void)
        : PrimarySeedEngine<Seed_>(SeedEngineParameter<Seed_>{SeedEngineID::StdRandomDevice, createEngine()})
    {
    }

private:
    /**
     * \brief シードエンジン生成
     * \return シードエンジン
     */
    SeedEngineParameter<Seed_>::Engine<Seed_> createEngine(void) const
    {
        return []() { return static_cast<Seed_>(std::random_device()()); };
    }
};
} // namespace random_number_generator
