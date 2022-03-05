/*****************************************************************//**
 * \file   SeedEngineFactory.h
 * \brief  シードエンジンファクトリ
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <memory>
// My
#include "StdRandomDeviceSeedEngine.h"
#include "CurrentTimeSeedEngine.h"
#include "CustomSeedEngine.h"

namespace random_number_generator
{
/**
 * \brief シードエンジンファクトリ
 * \tparam SeedEngineResultType_ シードエンジン生成結果の型
 */
template <typename SeedEngineResultType_>
class SeedEngineFactory
{
private:
    /**
     * \brief シードエンジン生成結果の型
     */
    using SeedEngineResultType = SeedEngineResultType_;

public:
    /**
     * \brief シードエンジンを生成
     * \param param シードエンジンパラメータ
     * \return シートエンジン
     */
    static std::shared_ptr<AbstractSeedEngine<SeedEngineResultType>> create(const SeedEngineParameter<SeedEngineResultType>& param = {})
    {
        switch (param.id) {
            case SeedEngineID::StdRandomDevice:
                return std::make_shared<StdRandomDeviceSeedEngine<SeedEngineResultType>>();
            case SeedEngineID::CurrentTime:
                return std::make_shared <CurrentTimeSeedEngine<SeedEngineResultType>>();
            case SeedEngineID::Custom:
                if (!param.generator) {
                    return nullptr;
                }
                return std::make_shared<CustomSeedEngine<SeedEngineResultType>>(param.generator);
            default:
                return nullptr;
        }
    }
};
} // namespace random_number_generator
