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
template <typename ResultType_, typename EngineResultType_,
    std::size_t W, std::size_t N, std::size_t M, std::size_t R,
    EngineResultType_ A, std::size_t U, EngineResultType_ D, std::size_t S,
    EngineResultType_ B, std::size_t T,
    EngineResultType_ C, std::size_t L, EngineResultType_ F
>
struct StdMersenneTwisterRandomNumberEngineParameter
{
    /**
     * \brief �������闐���̌^
     */
    using ResultType = ResultType_;

    /**
     * \brief �����G���W�����������闐���̌^
     */
    using EngineResultType = EngineResultType_;


};
} // namespace random_number_generator
