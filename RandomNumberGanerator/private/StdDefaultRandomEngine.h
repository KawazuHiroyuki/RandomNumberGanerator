/*****************************************************************//**
 * \file   StdDefaultRandomEngine.h
 * \brief  �����G���W�� - ����p�r�Ńf�t�H���g�g�p����[������������
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
 * \brief �����G���W�� - ����p�r�Ńf�t�H���g�g�p����[������������
 * \tparam Seed_ �V�[�h�̌^
 */
template <typename Seed_ = std::uint32_t>
class StdDefaultRandomEngine : public PrimaryPseudoRandomNumberEngine<BaseEngine<StdDefaultRandomEngine<Seed_>, Seed_>, EngineResultType<StdDefaultRandomEngine<Seed_>, Seed_>, Seed_>
{
private:
    using Base = PrimaryPseudoRandomNumberEngine<BaseEngine<StdDefaultRandomEngine<Seed_>, Seed_>, EngineResultType<StdDefaultRandomEngine<Seed_>, Seed_>, Seed_>;
    using Engine = BaseEngine<StdDefaultRandomEngine<Seed_>, Seed_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param seed �V�[�h�G���W��
     */
    StdDefaultRandomEngine(std::shared_ptr<SeedEngine<Seed_>> seed)
        : Base(RandomNumberEngineID::StdDefaultRandomEngine, Engine(seed->operator()()), seed)
    {
    }
};
} // namespace random_number_generator
