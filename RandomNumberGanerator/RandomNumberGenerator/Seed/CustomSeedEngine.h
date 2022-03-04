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
 * \tparam Seed_ シードの型
 */
template <typename Seed_>
class CustomSeedEngine : public PrimarySeedEngine<Seed_>
{
public:
    /**
     * \brief コンストラクタ
     * \param engine シード生成関数
     */
    CustomSeedEngine(SeedEngineParameter::Engine<Seed_> engine)
        : PrimarySeedEngine<Seed_>(SeedEngineParameter<Seed_>{SeedEngineID::Custom, engine})
    {
    }
};
} // namespace random_number_generator
