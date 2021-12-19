/*****************************************************************//**
 * \file   StdMt199937_32BitRandomNumberEngine.h
 * \brief  �����G���W�� - std::mt19937
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
 * \brief �����G���W�� - std::mt19937
 * \tparam EngineResultType_ �������镄���Ȃ������̌^
 */
class StdMt199937_32BitRandomNumberEngine : public RandomNumberEngine<EngineResultType<StdMt199937_32BitRandomNumberEngine>>
{
    using Base = RandomNumberEngine<EngineResultType>;

    using Engine = BaseEngine<StdMt199937_32BitRandomNumberEngine>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param seed �V�[�h�G���W��
     */
    StdMt199937_32BitRandomNumberEngine(std::shared_ptr<SeedEngine<Seed>> seed)
        : Base(makeRandomNumberEngineParameter<EngineResultType>(RandomNumberEngineID::StdMt199937_32Bit), seed)
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
    EngineResultType getMin(void) const override
    {
        return m_engine.min();
    }

    /**
     * \brief ��������l�̍ő�l���擾
     * \return �ő�l
     */
    EngineResultType getMax(void) const override
    {
        return m_engine.max();
    }

private:
    /**
     * \brief �����Z���k�c�C�X�^�[��32�r�b�g��
     */
    Engine m_engine;
};
} // namespace random_number_generator
