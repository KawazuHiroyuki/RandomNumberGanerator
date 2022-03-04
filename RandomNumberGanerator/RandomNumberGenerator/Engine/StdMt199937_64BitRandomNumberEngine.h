/*****************************************************************//**
 * \file   StdMt199937_64BitRandomNumberEngine.h
 * \brief  �����G���W�� - �����Z���k�c�C�X�^�[��64�r�b�g��
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <random>

#include "PrimaryPseudoRandomNumberEngine.h"
#include "RandomNumberEngineUtility.h"

namespace random_number_generator
{
/**
 * \brief �����G���W�� - �����Z���k�c�C�X�^�[��64�r�b�g��
 * \tparam Seed_ �V�[�h�̌^
 */
template <typename Seed_ = std::uint32_t>
class StdMt199937_64BitRandomNumberEngine : public PrimaryPseudoRandomNumberEngine<BaseEngine<StdMt199937_64BitRandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdMt199937_64BitRandomNumberEngine<Seed_>, Seed_>, Seed_>
{
public:
    /**
     * \brief �G���W���̌^
     */

private:
    using Base = PrimaryPseudoRandomNumberEngine<BaseEngine<StdMt199937_64BitRandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdMt199937_64BitRandomNumberEngine<Seed_>, Seed_>, Seed_>;
    using Engine = BaseEngine<StdMt199937_64BitRandomNumberEngine<Seed_>, Seed_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param seed �V�[�h�G���W��
     */
    StdMt199937_64BitRandomNumberEngine(std::shared_ptr<SeedEngine<Seed_>> seed)
        : Base(RandomNumberEngineID::StdMt199937_64Bit, Engine(seed->operator()()), seed)
    {
    }
};
} // namespace random_number_generator