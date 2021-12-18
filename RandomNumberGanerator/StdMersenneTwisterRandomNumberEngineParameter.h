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
template <typename T1, typename T2,
    std::size_t W, std::size_t N, std::size_t M, std::size_t R,
    T2 A, std::size_t U, T2 D, std::size_t S,
    T2 B, std::size_t T,
    T2 C, std::size_t L, T2 F
>
struct StdMersenneTwisterRandomNumberEngineParameter
{
    /**
     * \brief �������闐���̌^
     */
    using ResultType = T1;

    /**
     * \brief �����G���W�����������闐���̌^
     */
    using EngineResultType = T2;


};
} // namespace random_number_generator
