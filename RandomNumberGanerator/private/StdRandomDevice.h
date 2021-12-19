/*****************************************************************//**
 * \file   StdRandomDevice.h
 * \brief  �����G���W�� - std::random_device
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
 * \brief �����G���W�� - std::random_device
 */
class StdRandomDevice : public RandomNumberEngine<EngineResultType<StdRandomDevice>>
{
    using Engine = BaseEngine<StdRandomDevice>;

public:
    /**
     * \brief �R���X�g���N�^
     */
    StdRandomDevice(void)
        : RandomNumberEngine(RandomNumberEngineID::StdRandomDevice, nullptr)
        , m_engine()
    {
    }

    ~StdRandomDevice(void) = default;

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
        // �Ȃ�
    }

    /**
     * \brief �G���g���s�[(�����̗��G���̓x����)���擾
     * \return �G���g���s�[
     */
    double getEntropy(void) const noexcept override
    {
        return m_engine.entropy();
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
     * \brief �\���s�\�ȗ���������
     */
    Engine m_engine;
};
} // namespace random_number_generator
