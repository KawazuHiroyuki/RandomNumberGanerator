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
template <typename ResultType_, typename EngineResultType_>
class StdRanlux24RandomNumberEngine : public RandomNumberEngine<ResultType_, EngineResultType_>
{
    using RandomNumberEngine<ResultType_, EngineResultType_>::ResultType;

    using RandomNumberEngine<ResultType_, EngineResultType_>::EngineResultType;

    using RandomNumberEngine<ResultType_, EngineResultType_>::Seed;

    using RandomNumberEngine<ResultType_, EngineResultType_>::getSeed;

    using Engine = std::ranlux24;

    static_assert(std::is_same<Engine::result_type, EngineResultType>::value, "");

public:
    /**
     * \brief �R���X�g���N�^
     * \param param �����G���W���p�����[�^
     * \param seed �V�[�h������
     */
    StdRanlux24RandomNumberEngine(std::shared_ptr<RandomNumberEngineParameter<ResultType, EngineResultType>> param, std::shared_ptr<SeedEngine<Seed>> seed)
        : RandomNumberEngine<ResultType, EngineResultType>(param, seed)
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
     * \brief RANLUX�@�̃��x��3
     */
    Engine m_engine;
};
} // namespace random_number_generator