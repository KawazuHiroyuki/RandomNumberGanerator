/*****************************************************************//**
 * \file   StdMersenneTwisterRandomNumberEngineParameter.h
 * \brief  乱数エンジンパラメータ - std::mersenne_twister_engine
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

 //#include "RandomNumberEngineParameter.h"
#include <cstddef>

namespace random_number_generator
{
/**
 * \brief 乱数エンジンパラメータ - std::mersenne_twister_engine
 */
template <typename Type, typename EngineType,
    std::size_t W, std::size_t N, std::size_t M, std::size_t R,
    EngineType A, std::size_t U, EngineType D, std::size_t S,
    EngineType B, std::size_t T,
    EngineType C, std::size_t L, EngineType F
>
struct StdMersenneTwisterRandomNumberEngineParameter
{
    /**
     * \brief 生成する乱数の型
     */
    using Random = Type;

    /**
     * \brief 乱数エンジンが生成する乱数の型
     */
    using EngineRandom = EngineType;

    /**
     * \brief テンプレートパラメータ a 乗数
     */
    using Multiplier = A;

    /**
     * \brief テンプレートパラメータ c 増分
     */
    using Increment = C;

    /**
     * \brief テンプレートパラメータ m 法
     */
    using Modulus = M;
};
} // namespace random_number_generator
