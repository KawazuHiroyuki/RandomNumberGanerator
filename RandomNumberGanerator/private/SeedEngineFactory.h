/*****************************************************************//**
 * \file   SeedEngineFactory.h
 * \brief  シードエンジンファクトリ
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <memory>

#include "CurrentTimeSeedEngine.h"
#include "SeedEngine.h"
#include "StdRandomDeviceSeedEngine.h"

namespace random_number_generator
{
/**
 * \brief シードエンジンファクトリ
 */
class SeedEngineFactory
{
public:
    /**
     * \brief シードエンジンを生成
     * \param param シードエンジンパラメータ
     * \return シートエンジン
     */
    template <typename Seed>
    static std::shared_ptr<SeedEngine<Seed>> create(SeedEngineParameter<Seed> param = {})
    {
        switch (param.id) {
            case SeedEngineID::StdRandomDevice:
                return std::make_shared<StdRandomDeviceSeedEngine<Seed>>();
            case SeedEngineID::CurrentTime:
                return std::make_shared <CurrentTimeSeedEngine<Seed>>();
            case SeedEngineID::Custom:
                if (!param.engine) {
                    return nullptr;
                }
                return std::make_shared<SeedEngine<Seed>>(param);
            default:
                return nullptr;
        }
    }
};
} // namespace random_number_generator
