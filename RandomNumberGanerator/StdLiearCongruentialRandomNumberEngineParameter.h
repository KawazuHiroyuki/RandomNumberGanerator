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
template <typename T1, typename T2, 
    T2 A, T2 C, T2 M
>
struct StdLiearCongruentialRandomNumberEngineParameter
{
    /**
     * \brief 生成する乱数の型
     */
    using ResultType = T1;

    /**
     * \brief 乱数エンジンが生成する乱数の型
     */
    using EngineResultType = T2;

    /**
     * \brief テンプレートパラメータ a 乗数
     */
    static constexpr EngineResultType Multiplier = A;

    /**
     * \brief テンプレートパラメータ c 増分
     */
    static constexpr EngineResultType Increment = C;

    /**
     * \brief テンプレートパラメータ m 法
     */
    static constexpr EngineResultType Modulus = M;
};
} // namespace random_number_generator
