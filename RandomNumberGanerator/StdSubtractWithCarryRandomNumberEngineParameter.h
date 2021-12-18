/*****************************************************************//**
 * \file   StdSubtractWithCarryRandomNumberEngineParameter.h
 * \brief  乱数エンジンパラメータ - std::subtract_with_carry_engine	
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

 //#include "RandomNumberEngineParameter.h"

namespace random_number_generator
{
/**
 * \brief 乱数エンジンパラメータ - std::subtract_with_carry_engine	
 */
template <typename Type, typename EngineType,
    EngineType A, EngineType C, EngineType M
>
struct StdSubtractWithCarryRandomNumberEngineParameter
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
