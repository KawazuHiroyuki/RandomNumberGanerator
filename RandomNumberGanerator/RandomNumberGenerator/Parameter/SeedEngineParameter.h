/*****************************************************************//**
 * \file   SeedEngineParameter.h
 * \brief  シードエンジンパラメータ
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <functional>

#include "ID/SeedEngineID.h"

namespace random_number_generator
{
/**
 * \brief シードエンジンパラメータ
 * \tparam Seed_ シードの型
 */
template <typename Seed_ = void>
struct SeedEngineParameter
{
    /**
     * \brief シードの型
     */
    using Seed = Seed_;

    /**
     * \brief シードエンジン関数の型
     */
    template <typename Seed_>
    using Engine = std::function<Seed_()>;

    /**
     * \brief コンストラクタ
     * \param id_ シードエンジンID
     * \param engine_ シードエンジン関数
     */
    SeedEngineParameter(SeedEngineID id_ = DEFAULT_SEED_ENGINE_ID, Engine<Seed> engine_ = {})
        : id(id_)
        , engine(engine_)
    {
    }

    /**
     * \brief シードエンジンID
     */
    SeedEngineID id = DEFAULT_SEED_ENGINE_ID;

    /**
     * \brief シードエンジン関数
     */
    Engine<Seed> engine = {};
};
} // namespace random_number_generator
