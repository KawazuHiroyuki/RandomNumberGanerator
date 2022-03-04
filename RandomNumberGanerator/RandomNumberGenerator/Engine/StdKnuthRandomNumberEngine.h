/*****************************************************************//**
 * \file   StdKnuthRandomNumberEngine.h
 * \brief  Knuth�̃��I�[�_�[�A���S���Y��B ����������
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
 * \brief Knuth�̃��I�[�_�[�A���S���Y��B ����������
 * \note std::knuth_b
 * \tparam Seed_ �V�[�h�̌^
 */
template <typename Seed_ = std::uint32_t>
class StdKnuthRandomNumberEngine : public PrimaryPseudoRandomNumberEngine<BaseEngine<StdKnuthRandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdKnuthRandomNumberEngine<Seed_>, Seed_>, Seed_>
{
private:
    using Base = PrimaryPseudoRandomNumberEngine<BaseEngine<StdKnuthRandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdKnuthRandomNumberEngine<Seed_>, Seed_>, Seed_>;
    using Engine = BaseEngine<StdKnuthRandomNumberEngine<Seed_>, Seed_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param seed �V�[�h�G���W��
     */
    StdKnuthRandomNumberEngine(std::shared_ptr<SeedEngine<Seed_>> seed)
        : Base(RandomNumberEngineID::StdKnuth, Engine(seed->operator()()), seed)
    {
    }
};
} // namespace random_number_generator
