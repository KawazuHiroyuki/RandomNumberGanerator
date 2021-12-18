/*****************************************************************//**
 * \file   StdLiearCongruentialRandomNumberEngineParameter.h
 * \brief  乱数エンジンパラメータ - std::linear_congruential_engine
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

//#include "RandomNumberEngineParameter.h"

namespace random_number_generator
{
/**
 * \brief 乱数エンジンパラメータ - std::linear_congruential_engine
 */
template <typename Type, typename EngineType, 
    EngineType A, EngineType C, EngineType M
>
struct StdLiearCongruentialRandomNumberEngineParameter
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
    static constexpr EngineRandom Multiplier = A;

    /**
     * \brief テンプレートパラメータ c 増分
     */
    static constexpr EngineRandom Increment = C;

    /**
     * \brief テンプレートパラメータ m 法
     */
    static constexpr EngineRandom Modulus = M;
};
} // namespace random_number_generator
