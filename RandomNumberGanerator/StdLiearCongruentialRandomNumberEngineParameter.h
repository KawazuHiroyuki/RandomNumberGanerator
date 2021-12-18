/*****************************************************************//**
 * \file   StdLiearCongruentialRandomNumberEngineParameter.h
 * \brief  �����G���W���p�����[�^ - std::linear_congruential_engine
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

//#include "RandomNumberEngineParameter.h"

namespace random_number_generator
{
/**
 * \brief �����G���W���p�����[�^ - std::linear_congruential_engine
 */
template <typename Type, typename EngineType, 
    EngineType A, EngineType C, EngineType M
>
struct StdLiearCongruentialRandomNumberEngineParameter
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
    static constexpr EngineRandom Multiplier = A;

    /**
     * \brief �e���v���[�g�p�����[�^ c ����
     */
    static constexpr EngineRandom Increment = C;

    /**
     * \brief �e���v���[�g�p�����[�^ m �@
     */
    static constexpr EngineRandom Modulus = M;
};
} // namespace random_number_generator
