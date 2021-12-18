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
template <typename Type, typename EngineType>
class StdRanlux24RandomNumberEngine : public RandomNumberEngine<Type, EngineType>
{
    static_assert(std::is_same<std::ranlux24::result_type, EngineType>::value, "");

public:
    /**
     * \brief �R���X�g���N�^
     * \param param �����G���W���p�����[�^
     * \param seed �V�[�h������
     */
    StdRanlux24RandomNumberEngine(std::shared_ptr<RandomNumberEngineParameter<Type, EngineType>> param, std::shared_ptr<SeedGenerator<EngineType>> seed)
        : RandomNumberEngine<Type, EngineType>(param, seed)
        , m_engine(RandomNumberEngine<Type, EngineType>::getSeed())
    {
    }

    /**
     * \brief �����𐶐�
     * \return ����
     */
    typename StdRanlux24RandomNumberEngine::EngineRandom operator()(void) override
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
    constexpr typename StdRanlux24RandomNumberEngine::EngineRandom getMin(void) const override
    {
        return m_engine.min();
    }

    /**
     * \brief ��������l�̍ő�l���擾
     * \return �ő�l
     */
    constexpr typename StdRanlux24RandomNumberEngine::EngineRandom getMax(void) const override
    {
        return m_engine.max();
    }

private:
    /**
     * \brief RANLUX�@�̃��x��3
     */
    std::ranlux24 m_engine;
};
} // namespace random_number_generator
