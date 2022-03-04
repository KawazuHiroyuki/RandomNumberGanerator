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
#include "SeedEngine.h"

namespace random_number_generator
{
/**
 * \brief 予測不能な乱数生成器
 * \note std::random_device
 * \tparam Seed_ シードの型
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
