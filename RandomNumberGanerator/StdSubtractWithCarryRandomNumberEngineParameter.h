/*****************************************************************//**
 * \file   StdSubtractWithCarryRandomNumberEngineParameter.h
 * \brief  �����G���W���p�����[�^ - std::subtract_with_carry_engine	
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

 //#include "RandomNumberEngineParameter.h"

namespace random_number_generator
{
/**
 * \brief �����G���W���p�����[�^ - std::subtract_with_carry_engine	
 */
template <typename EngineResultType_,
    EngineResultType_ A, EngineResultType_ C, EngineResultType_ M
>
struct StdSubtractWithCarryRandomNumberEngineParameter
{
    /**
     * \brief �����G���W�����������闐���̌^
     */
    using EngineResultType = EngineResultType_;


};
} // namespace random_number_generator
