/*****************************************************************//**
 * \file   StdMt199937_64BitRandomNumberEngine.h
 * \brief  �����Z���k�c�C�X�^�[��64�r�b�g�� ����������
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <random>
// My
#include "PrimaryPseudoRandomNumberEngine.h"
#include "RandomNumberEngineUtility.h"

namespace random_number_generator
{
/**
 * \brief �����Z���k�c�C�X�^�[��64�r�b�g�� ����������
 * \note std::mt19937_64
 * \tparam Seed_ �V�[�h�̌^
 */
template <typename Seed_ = std::uint32_t>
class StdMt199937_64BitRandomNumberEngine : public PrimaryPseudoRandomNumberEngine<BaseEngine<StdMt199937_64BitRandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdMt199937_64BitRandomNumberEngine<Seed_>, Seed_>, Seed_>
{
private:
    using Base = PrimaryPseudoRandomNumberEngine<BaseEngine<StdMt199937_64BitRandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdMt199937_64BitRandomNumberEngine<Seed_>, Seed_>, Seed_>;
    using Engine = BaseEngine<StdMt199937_64BitRandomNumberEngine<Seed_>, Seed_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param seed �V�[�h�G���W��
     */
    StdMt199937_64BitRandomNumberEngine(std::shared_ptr<PrimarySeedEngine<Seed_>> seed)
        : Base(RandomNumberEngineID::StdMt199937_64Bit, Engine(seed->operator()()), seed)
    {
    }
};
} // namespace random_number_generator
