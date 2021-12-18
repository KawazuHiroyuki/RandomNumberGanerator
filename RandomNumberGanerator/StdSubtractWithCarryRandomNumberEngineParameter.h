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
template <typename Type, typename EngineType,
    EngineType A, EngineType C, EngineType M
>
struct StdSubtractWithCarryRandomNumberEngineParameter
{
    /**
     * \brief �������闐���̌^
     */
    using Random = Type;

    /**
     * \brief �����G���W�����������闐���̌^
     */
    using EngineRandom = EngineType;

    /**
     * \brief �e���v���[�g�p�����[�^ a �搔
     */
    using Multiplier = A;

    /**
     * \brief �e���v���[�g�p�����[�^ c ����
     */
    using Increment = C;

    /**
     * \brief �e���v���[�g�p�����[�^ m �@
     */
    using Modulus = M;
};
} // namespace random_number_generator
