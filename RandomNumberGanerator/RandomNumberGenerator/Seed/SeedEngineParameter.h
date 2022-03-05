/*****************************************************************//**
 * \file   SeedEngineParameter.h
 * \brief  シードエンジンパラメータ
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <functional>
// My
#include "SeedEngineID.h"

namespace random_number_generator
{
/**
 * \brief シードエンジンパラメータ
 * \tparam Seed_ シードエンジン生成結果の型
 */
template <typename Seed_>
struct SeedEngineParameter
{
    /**
     * \brief シードエンジン生成結果の型
     */
    using Seed = Seed_;

    /**
     * \brief シード生成関数
     */
    template <typename Seed_>
    using Generator = std::function<Seed_()>;

    /**
     * \brief コンストラクタ
     * \param id_ シードエンジンID
     * \param engine_ シード生成関数
     */
    SeedEngineParameter(SeedEngineID id_ = DEFAULT_SEED_ENGINE_ID, Generator<Seed> generator_ = {})
        : id(id_)
        , generator(generator_)
    {
    }

    /**
     * \brief シードエンジンID
     */
    SeedEngineID id = DEFAULT_SEED_ENGINE_ID;

    /**
     * \brief シード生成関数
     */
    Generator<Seed> generator = {};
};
} // namespace random_number_generator
