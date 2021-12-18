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
template <typename T1, typename T2,
    T2 A, T2 C, T2 M
>
struct StdSubtractWithCarryRandomNumberEngineParameter
{
    /**
     * \brief 生成する乱数の型
     */
    using ResultType = T1;

    /**
     * \brief 乱数エンジンが生成する乱数の型
     */
    using EngineResultType = T2;


};
} // namespace random_number_generator
