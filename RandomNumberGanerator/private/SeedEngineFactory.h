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
     * \tparam Seed_ シードの型
     * \param param シードエンジンパラメータ
     * \return シートエンジン
     */
    template <typename Seed_>
    static std::shared_ptr<SeedEngine<Seed_>> create(const SeedEngineParameter<Seed_>& param = {})
    {
        switch (param.id) {
            case SeedEngineID::StdRandomDevice:
                return std::make_shared<StdRandomDeviceSeedEngine<Seed_>>();
            case SeedEngineID::CurrentTime:
                return std::make_shared <CurrentTimeSeedEngine<Seed_>>();
            case SeedEngineID::Custom:
                if (!param.engine) {
                    return nullptr;
                }
                return std::make_shared<SeedEngine<Seed_>>(param);
            default:
                return nullptr;
        }
    }
};
} // namespace random_number_generator
