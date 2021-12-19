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
template <typename Seed_ = std::uint32_t /* Dummy */>
class StdRandomDevice : public RandomNumberEngine<EngineResultType<StdRandomDevice<Seed_>, Seed_>, Seed_>
{
    using Base = RandomNumberEngine<EngineResultType<StdRandomDevice<Seed_>, Seed_>, Seed_>;

    using Engine = BaseEngine<StdRandomDevice, Seed_>;

    using Seed = Seed_;

public:
    /**
     * \brief �R���X�g���N�^
     */
    StdRandomDevice(void)
        : Base(RandomNumberEngineID::StdRandomDevice, nullptr)
        , m_engine()
    {
    }

    ~StdRandomDevice(void) = default;

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
     * \brief �\���s�\�ȗ���������
     */
    Engine m_engine;
};
} // namespace random_number_generator
