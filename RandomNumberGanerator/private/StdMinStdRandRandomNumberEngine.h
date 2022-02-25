/*****************************************************************//**
 * \file   StdMinStdRandRandomNumberEngine.h
 * \brief  �����G���W�� - �ŏ��W��MINSTD�̃p�����[�^���ǔ�
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <random>

#include "AbstractPseudoRandomNumberEngine.h"
#include "RandomNumberEngineUtility.h"

namespace random_number_generator
{
/**
 * \brief �����G���W�� - �ŏ��W��MINSTD�̃p�����[�^���ǔ�
 * \tparam Seed_ �V�[�h�̌^
 */
template <typename Seed_ = std::uint32_t>
class StdMinStdRandRandomNumberEngine : public AbstractPseudoRandomNumberEngine<BaseEngine<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>, Seed_>
{
private:
    using Base = AbstractPseudoRandomNumberEngine<BaseEngine<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>, Seed_>;
    using Engine = BaseEngine<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param seed �V�[�h�G���W��
     */
    StdMinStdRandRandomNumberEngine(std::shared_ptr<SeedEngine<Seed_>> seed)
        : Base(RandomNumberEngineID::StdMinStdRand, Engine(seed->operator()()), seed)
    {
    }
};
} // namespace random_number_generator
