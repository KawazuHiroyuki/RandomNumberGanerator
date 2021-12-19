/*****************************************************************//**
 * \file   StdRanlux24RandomNumberEngine.h
 * \brief  �����G���W�� - std::ranlux24
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <random>

#include "RandomNumberEngine.h"

namespace random_number_generator
{
/**
 * \brief �����G���W�� - std::ranlux24
 */
class StdRanlux24RandomNumberEngine : public RandomNumberEngine<std::ranlux24::result_type>
{
    using Base = RandomNumberEngine<EngineResultType>;

    using Engine = std::ranlux24;

public:
    /**
     * \brief �R���X�g���N�^
     * \param seed �V�[�h�G���W��
     */
    StdRanlux24RandomNumberEngine(std::shared_ptr<SeedEngine<Seed>> seed)
        : Base(makeRandomNumberEngineParameter<EngineResultType>(RandomNumberEngineID::StdRanlux24), seed)
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
     * \brief RANLUX�@�̃��x��3
     */
    Engine m_engine;
};
} // namespace random_number_generator
