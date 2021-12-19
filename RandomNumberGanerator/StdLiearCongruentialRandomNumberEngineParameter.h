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
template <typename ResultType_, typename EngineResultType_,
    EngineResultType_ A, EngineResultType_ C, EngineResultType_ M
>
struct StdLiearCongruentialRandomNumberEngineParameter
{
    /**
     * \brief �������闐���̌^
     */
    using ResultType = ResultType_;

    /**
     * \brief �����G���W�����������闐���̌^
     */
    using EngineResultType = EngineResultType_;

    /**
     * \brief �e���v���[�g�p�����[�^ a �搔
     */
    static constexpr EngineResultType Multiplier = A;

    /**
     * \brief �e���v���[�g�p�����[�^ c ����
     */
    static constexpr EngineResultType Increment = C;

    /**
     * \brief �e���v���[�g�p�����[�^ m �@
     */
    static constexpr EngineResultType Modulus = M;
};
} // namespace random_number_generator