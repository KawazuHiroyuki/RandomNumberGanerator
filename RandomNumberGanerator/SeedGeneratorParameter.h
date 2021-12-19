/*****************************************************************//**
 * \file   SeedGeneratorParameter.h
 * \brief  シード生成器パラメータ
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <functional>

#include "SeedGeneratorID.h"

namespace random_number_generator
{
/**
 * \brief シード生成器パラメータ
 */
template <typename Seed_>
struct SeedGeneratorParameter
{
    /**
     * \brief シードの型
     */
    using Seed = Seed_;

    /**
     * \brief シード生成関数の型
     */
    template <typename Seed_>
    using Generator = std::function<Seed_()>;

    /**
     * \brief コンストラクタ
     * \param id_ シード生成器ID
     * \param generator_ シード生成関数
     */
    SeedGeneratorParameter(SeedGeneratorID id_ = DEFAULT_SEED_GENERATOR_ID, Generator<Seed> generator_ = {})
        : id(id_)
        , generator(generator_)
    {
    }

    /**
     * \brief シード生成器ID
     */
    SeedGeneratorID id = DEFAULT_SEED_GENERATOR_ID;

    /**
     * \brief シード生成関数
     */
    Generator<Seed> generator = {};
};
} // namespace random_number_generator
