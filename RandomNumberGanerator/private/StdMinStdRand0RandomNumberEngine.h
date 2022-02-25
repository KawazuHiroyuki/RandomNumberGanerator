/*****************************************************************//**
 * \file   StdMinStdRand0RandomNumberEngine.h
 * \brief  �����G���W�� - �ŏ��W��MINSTD
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
 * \brief �����G���W�� - �ŏ��W��MINSTD
 * \tparam Seed_ �V�[�h�̌^
 */
template <typename Seed_ = std::uint32_t>
class StdMinStdRand0RandomNumberEngine : public AbstractPseudoRandomNumberEngine<BaseEngine<StdMinStdRand0RandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdMinStdRand0RandomNumberEngine<Seed_>, Seed_>, Seed_>
{
private:
    using Base = AbstractPseudoRandomNumberEngine<BaseEngine<StdMinStdRand0RandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdMinStdRand0RandomNumberEngine<Seed_>, Seed_>, Seed_>;
    using Engine = BaseEngine<StdMinStdRand0RandomNumberEngine<Seed_>, Seed_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param seed �V�[�h�G���W��
     */
    StdMinStdRand0RandomNumberEngine(std::shared_ptr<SeedEngine<Seed_>> seed)
        : Base(RandomNumberEngineID::StdMinStdRand0, Engine(seed->operator()()), seed)
    {
    }
};
} // namespace random_number_generator
