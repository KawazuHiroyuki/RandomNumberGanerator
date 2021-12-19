/*****************************************************************//**
 * \file   StdMinStdRandRandomNumberEngine.h
 * \brief  �����G���W�� - std::minstd_rand
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <random>

#include "RandomNumberEngine.h"
#include "RandomNumberEngineUtility.h"

namespace random_number_generator
{
/**
 * \brief �����G���W�� - std::minstd_rand
 */
template <typename Seed_ = std::uint32_t>
class StdMinStdRandRandomNumberEngine : public RandomNumberEngine<EngineResultType<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>, Seed_>
{
    using Base = RandomNumberEngine<EngineResultType<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>, Seed_>;

    using Engine = BaseEngine<StdMinStdRandRandomNumberEngine, Seed_>;

    using Seed = Seed_;

public:
    /**
     * \brief �R���X�g���N�^
     * \param seed �V�[�h�G���W��
     */
    StdMinStdRandRandomNumberEngine(std::shared_ptr<SeedEngine<Seed>> seed)
        : Base(RandomNumberEngineID::StdMinStdRand, seed)
        , m_engine(Base::getSeed())
    {
    }

    /**
     * \brief �����𐶐�
     * \return ����
     */
    Base::EngineResultType operator()(void) override
    {
        return m_engine();
    }

    /**
     * \brief �w�肵���񐔂����^�������𐶐����A������Ԃ�i�߂�
     * \param times �w���
     */
    void discard(std::uint64_t skip) override
    {
        m_engine.discard(skip);
    }

    /**
     * \brief �G���g���s�[(�����̗��G���̓x����)���擾
     * \return �G���g���s�[
     */
    double getEntropy(void) const noexcept override
    {
        return 0.0; // �^�������̓G���g���s�[0
    }

    /**
     * \brief ��������l�̍ŏ��l���擾
     * \return �ŏ��l
     */
    static constexpr Base::EngineResultType getMin(void)
    {
        return Engine::min();
    }

    /**
     * \brief ��������l�̍ő�l���擾
     * \return �ő�l
     */
    static constexpr Base::EngineResultType getMax(void)
    {
        return Engine::max();
    }

private:
    /**
     * \brief �ŏ��W��MINSTD�̃p�����[�^���ǔ�
     */
    Engine m_engine;
};
} // namespace random_number_generator
