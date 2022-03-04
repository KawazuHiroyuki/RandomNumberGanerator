/*****************************************************************//**
 * \file   StdRanlux24RandomNumberEngine.h
 * \brief  RANLUX�@�̃��x��3 ����������
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <random>
// My
#include "PrimaryPseudoRandomNumberEngine.h"

namespace random_number_generator
{
/**
 * \brief RANLUX�@�̃��x��3 ����������
 * \note std::ranlux24
 * \tparam Seed_ �V�[�h�̌^
 */
template <typename Seed_ = std::uint32_t>
class StdRanlux24RandomNumberEngine : public PrimaryPseudoRandomNumberEngine<BaseEngine<StdRanlux24RandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdRanlux24RandomNumberEngine<Seed_>, Seed_>, Seed_>
{
private:
    using Base = PrimaryPseudoRandomNumberEngine<BaseEngine<StdRanlux24RandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdRanlux24RandomNumberEngine<Seed_>, Seed_>, Seed_>;
    using Engine = BaseEngine<StdRanlux24RandomNumberEngine<Seed_>, Seed_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param seed �V�[�h�G���W��
     */
    StdRanlux24RandomNumberEngine(std::shared_ptr<SeedEngine<Seed_>> seed)
        : Base(RandomNumberEngineID::StdRanlux24, Engine(seed->operator()()), seed)
    {
    }
};
} // namespace random_number_generator
