/*****************************************************************//**
 * \file   StdKnuthRandomNumberEngine.h
 * \brief  �����G���W�� - std::knuth_b
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
 * \brief �����G���W�� - std::knuth_b
 */
class StdKnuthRandomNumberEngine : public RandomNumberEngine<EngineResultType<StdKnuthRandomNumberEngine>>
{
    using Base = RandomNumberEngine<EngineResultType>;

    using Engine = BaseEngine<StdKnuthRandomNumberEngine>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param seed �V�[�h�G���W��
     */
    StdKnuthRandomNumberEngine(std::shared_ptr<SeedEngine<Seed>> seed)
        : Base(RandomNumberEngineID::StdKnuth, seed)
        , m_engine(getSeed())
    {
    }

    /**
     * \brief �����𐶐�
     * \return ����
     */
    EngineResultType operator()(void) override
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
    static constexpr EngineResultType getMin(void)
    {
        return Engine::min();
    }

    /**
     * \brief ��������l�̍ő�l���擾
     * \return �ő�l
     */
    static constexpr EngineResultType getMax(void)
    {
        return Engine::max();
    }

private:
    /**
     * \brief Knuth�̃��I�[�_�[�A���S���Y��B
     */
    Engine m_engine;
};
} // namespace random_number_generator
