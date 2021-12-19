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
template <typename EngineResultType_,
    EngineResultType_ A, EngineResultType_ C, EngineResultType_ M
>
struct StdSubtractWithCarryRandomNumberEngineParameter
{
    /**
     * \brief 乱数エンジンが生成する乱数の型
     */
    using EngineResultType = EngineResultType_;


};
} // namespace random_number_generator
