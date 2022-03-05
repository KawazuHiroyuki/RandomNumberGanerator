﻿/*****************************************************************//**
 * \file   StdRandomDeviceSeedGenerator.h
 * \brief  予測不能な乱数生成 シードエンジン
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
 * \brief 予測不能な乱数生成 シードエンジン
 * \note std::random_device
 * \tparam Seed_ シードエンジン生成結果の型
 */
template <typename Seed_>
class StdRandomDeviceSeedEngine : public PrimarySeedEngine<Seed_>
{
public:
    /**
     * \brief コンストラクタ
     */
    StdRandomDeviceSeedEngine(void)
        : PrimarySeedEngine<Seed_>(SeedEngineParameter<Seed_>{SeedEngineID::StdRandomDevice, createGenerator()})
    {
    }

private:
    /**
     * \brief シード生成関数を生成
     * \return シード生成関数
     */
    SeedEngineParameter<Seed_>::Generator<Seed_> createGenerator(void) const
    {
        return []() { return static_cast<Seed_>(std::random_device()()); };
    }
};
} // namespace random_number_generator
