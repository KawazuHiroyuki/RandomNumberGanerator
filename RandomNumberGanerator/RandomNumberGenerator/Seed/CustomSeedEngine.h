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
 * \tparam SeedEngineResultType_ シードエンジン生成結果の型
 */
template <typename SeedEngineResultType_>
class CustomSeedEngine : public PrimarySeedEngine<SeedEngineResultType_>
{
public:
    /**
     * \brief コンストラクタ
     * \param generator シード生成関数
     */
    CustomSeedEngine(SeedEngineParameter::Generator<SeedEngineResultType_> generator)
        : PrimarySeedEngine<SeedEngineResultType_>(SeedEngineParameter<SeedEngineResultType_>{SeedEngineID::Custom, generator})
    {
    }

    virtual ~CustomSeedEngine(void) override = default;
};
} // namespace random_number_generator
