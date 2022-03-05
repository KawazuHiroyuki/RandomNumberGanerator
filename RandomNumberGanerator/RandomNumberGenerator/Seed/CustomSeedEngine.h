/*****************************************************************//**
 * \file   CustomSeedEngine.h
 * \brief  カスタム シードエンジン
 * 
 * \author japan
 * \date   March 2022
 *********************************************************************/

#pragma once

// My
#include "PrimarySeedEngine.h"

namespace random_number_generator
{
/**
 * \brief カスタム シードエンジン
 * \tparam Seed_ シードエンジン生成結果の型
 */
template <typename Seed_>
class CustomSeedEngine : public PrimarySeedEngine<Seed_>
{
public:
    /**
     * \brief コンストラクタ
     * \param generator シード生成関数
     */
    CustomSeedEngine(SeedEngineParameter::Generator<Seed_> generator)
        : PrimarySeedEngine<Seed_>(SeedEngineParameter<Seed_>{SeedEngineID::Custom, generator})
    {
    }
};
} // namespace random_number_generator
