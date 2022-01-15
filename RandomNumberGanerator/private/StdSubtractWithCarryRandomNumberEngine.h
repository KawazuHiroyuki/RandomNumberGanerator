/*****************************************************************//**
 * \file   StdSubtractWithCarryRandomNumberEngine.h
 * \brief  �����G���W�� - �L�����[�t�����Z�@
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <random>

#include "PseudoRandomNumberEngine.h"
#include "RandomNumberEngineUtility.h"

namespace random_number_generator
{
/**
 * \brief �����G���W�� - �L�����[�t�����Z�@
 * \tparam EngineResultType_ �������镄���Ȃ������̌^
 */
template <typename EngineResultType_,
    std::size_t W, std::size_t S, std::size_t R,
    typename Seed_
>
class StdSubtractWithCarryRandomNumberEngine : public PseudoRandomNumberEngine<std::subtract_with_carry_engine<EngineResultType_, W, S, R>, EngineResultType_, Seed_>
{
private:
    using Base = PseudoRandomNumberEngine<std::subtract_with_carry_engine<EngineResultType_, W, S, R>, EngineResultType_, Seed_>;
    using Engine = Base::Engine;

    //static_assert(std::is_same<Engine::result_type, Base::EngineResultType>::value, "");

public:
    /**
     * \brief �R���X�g���N�^
     * \param seed �V�[�h�G���W��
     */
    StdSubtractWithCarryRandomNumberEngine(std::shared_ptr<SeedEngine<Seed_>> seed)
        : Base(RandomNumberEngineID::StdSubtractWithCarry, Engine(seed->operator()()), seed)
    {
    }
};
} // namespace random_number_generator
