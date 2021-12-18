/*****************************************************************//**
 * \file   StdMersenneTwisterRandomNumberEngineParameter.h
 * \brief  �����G���W���p�����[�^ - std::mersenne_twister_engine
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
 * \brief �����G���W���p�����[�^ - std::mersenne_twister_engine
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
