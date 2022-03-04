/*****************************************************************//**
 * \file   StdMinStdRandRandomNumberEngine.h
 * \brief  �ŏ��W��MINSTD�̃p�����[�^���ǔ� ����������
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <random>
// My
#include "RandomNumberEngineUtility.h"
#include "PrimaryPseudoRandomNumberEngine.h"

namespace random_number_generator
{
/**
 * \brief �ŏ��W��MINSTD�̃p�����[�^���ǔ� ����������
 * \note std::minstd_rand
 * \tparam Seed_ �V�[�h�̌^
 */
template <typename Seed_ = std::uint32_t>
class StdMinStdRandRandomNumberEngine : public PrimaryPseudoRandomNumberEngine<BaseEngine<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>, Seed_>
{
private:
    using Base = PrimaryPseudoRandomNumberEngine<BaseEngine<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>, Seed_>;
    using Engine = BaseEngine<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param seed �V�[�h�G���W��
     */
    StdMinStdRandRandomNumberEngine(std::shared_ptr<AbstractSeedEngine<Seed_>> seed)
        : Base(RandomNumberEngineID::StdMinStdRand, Engine(seed->operator()()), seed)
    {
    }
};
} // namespace random_number_generator
