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
 * \tparam Seed_ シードエンジン生成結果の型
 */
template <typename Seed_>
class SeedEngineFactory
{
private:
    /**
     * \brief シードエンジン生成結果の型
     */
    using Seed = Seed_;

public:
    /**
     * \brief シードエンジンを生成
     * \param param シードエンジンパラメータ
     * \return シートエンジン
     */
    static std::shared_ptr<AbstractSeedEngine<Seed>> create(const SeedEngineParameter<Seed>& param = {})
    {
        switch (param.id) {
            case SeedEngineID::StdRandomDevice:
                return std::make_shared<StdRandomDeviceSeedEngine<Seed>>();
            case SeedEngineID::CurrentTime:
                return std::make_shared <CurrentTimeSeedEngine<Seed>>();
            case SeedEngineID::Custom:
                if (!param.generator) {
                    return nullptr;
                }
                return std::make_shared<CustomSeedEngine<Seed>>(param.generator);
            default:
                return nullptr;
        }
    }
};
} // namespace random_number_generator
