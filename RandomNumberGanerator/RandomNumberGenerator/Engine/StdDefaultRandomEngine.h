/*****************************************************************//**
 * \file   StdDefaultRandomEngine.h
 * \brief  ����p�r�Ńf�t�H���g�g�p����[������������
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
 * \brief ����p�r�Ńf�t�H���g�g�p����[������������
 * \note std::default_random_engine
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
    StdDefaultRandomEngine(std::shared_ptr<AbstractSeedEngine<Seed_>> seed)
        : Base(RandomNumberEngineID::StdDefaultRandomEngine, Engine(seed->operator()()), seed)
    {
    }
};
} // namespace random_number_generator
