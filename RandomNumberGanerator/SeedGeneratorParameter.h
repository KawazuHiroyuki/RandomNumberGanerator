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
template <typename T>
struct SeedGeneratorParameter
{
    /**
     * \brief シードの型
     */
    using Seed = T;

    /**
     * \brief シード生成関数の型
     */
    template <typename T>
    using Generator = std::function<T()>;

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
