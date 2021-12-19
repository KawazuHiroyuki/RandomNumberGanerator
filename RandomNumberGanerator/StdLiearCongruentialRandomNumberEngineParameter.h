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
template <typename EngineResultType_,
    EngineResultType_ A, EngineResultType_ C, EngineResultType_ M
>
struct StdLiearCongruentialRandomNumberEngineParameter
{
    /**
     * \brief 乱数エンジンが生成する乱数の型
     */
    using EngineResultType = EngineResultType_;

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
