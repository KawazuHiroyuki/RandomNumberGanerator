/*****************************************************************//**
 * \file   StdMersenneTwisterRandomNumberEngine.h
 * \brief  �����G���W�� - �����Z���k�c�C�X�^�[�@
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <random>

#include "PseudoRandomNumberEngine.h"

namespace random_number_generator
{
/**
 * \brief �����G���W�� - �����Z���k�c�C�X�^�[�@
 * \tparam EngineResultType_ �������镄���Ȃ������̌^
 */
template <
    typename EngineResultType_,
    std::size_t W, std::size_t N, std::size_t M, std::size_t R,
    EngineResultType_ A, std::size_t U, EngineResultType_ D, std::size_t S,
    EngineResultType_ B, std::size_t T,
    EngineResultType_ C, std::size_t L, EngineResultType_ F,
    typename Seed_
>
class StdMersenneTwisterRandomNumberEngine : public PseudoRandomNumberEngine<std::mersenne_twister_engine<EngineResultType_, W, N, M, R, A, U, D, S, B, T, C, L, F>, EngineResultType_, Seed_>
{
private:
    using Base = PseudoRandomNumberEngine<std::mersenne_twister_engine<EngineResultType_, W, N, M, R, A, U, D, S, B, T, C, L, F>, EngineResultType_, Seed_>;
    using Engine = Base::Engine;

    //static_assert(std::is_same<Engine::result_type, EngineResultType_>::value, "");

public:
    /**
     * \brief �R���X�g���N�^
     * \param seed �V�[�h�G���W��
     */
    StdMersenneTwisterRandomNumberEngine(std::shared_ptr<SeedEngine<Seed_>> seed)
        : Base(RandomNumberEngineID::StdMersenneTwister, Engine(seed->operator()()), seed)
    {
    }
};
} // namespace random_number_generator
