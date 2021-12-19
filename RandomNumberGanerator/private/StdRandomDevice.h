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

namespace random_number_generator
{
/**
 * \brief �����G���W�� - std::random_device
 */
template <typename ResultType_, typename EngineResultType_>
class StdRandomDevice : public RandomNumberEngine<ResultType_, EngineResultType_>
{
    using RandomNumberEngine<ResultType_, EngineResultType_>::ResultType;

    using RandomNumberEngine<ResultType_, EngineResultType_>::EngineResultType;

    using RandomNumberEngine<ResultType_, EngineResultType_>::Seed;

    using RandomNumberEngine<ResultType_, EngineResultType_>::getSeed;

    using Engine = std::random_device;

    static_assert(std::is_same<Engine::result_type, EngineResultType>::value, "");

public:
    /**
     * \brief �R���X�g���N�^
     * \param param �����G���W���p�����[�^
     * \param seed �V�[�h������
     */
    StdRandomDevice(std::shared_ptr<RandomNumberEngineParameter<ResultType, EngineResultType>> param, std::shared_ptr<SeedEngine<Seed>> seed)
        : RandomNumberEngine<ResultType, EngineResultType>(param, seed)
        , m_engine()
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
    constexpr EngineResultType getMin(void) const override
    {
        return m_engine.min();
    }

    /**
     * \brief ��������l�̍ő�l���擾
     * \return �ő�l
     */
    constexpr EngineResultType getMax(void) const override
    {
        return m_engine.max();
    }

private:
    /**
     * \brief �\���s�\�ȗ���������
     */
    Engine m_engine;
};
} // namespace random_number_generator