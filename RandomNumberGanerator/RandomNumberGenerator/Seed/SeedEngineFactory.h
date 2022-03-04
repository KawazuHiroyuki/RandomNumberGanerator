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
#include "CurrentTimeSeedEngine.h"
#include "StdRandomDeviceSeedEngine.h"
#include "CustomSeedEngine.h"

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
     * \
     */
    template <typename Seed_>
    static std::shared_ptr<AbstractSeedEngine<Seed_>> create(const SeedEngineParameter<Seed_>& param = {})
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
                return std::make_shared<CustomSeedEngine<Seed_>>(param.engine);
            default:
                return nullptr;
        }
    }
};
} // namespace random_number_generator
