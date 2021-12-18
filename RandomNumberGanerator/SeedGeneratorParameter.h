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
    template <typename Type>
    struct SeedGeneratorParameter
    {
        template <typename Type>
        using Generator = std::function<Type()>;

        /**
         * \brief シード生成器ID
         */
        SeedGeneratorID id = DEFAULT_SEED_GENERATOR_ID;

        /**
         * \brief シード生成関数
         */
        Generator<Type> generator = {};
    };
} // namespace random_number_generator
