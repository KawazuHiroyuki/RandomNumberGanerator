/*****************************************************************//**
 * \file   StdMersenneTwisterRandomNumberEngine.h
 * \brief  �����G���W�� - std::mersenne_twister_engine
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
 * \brief �����G���W�� - std::mersenne_twister_engine
 */
template <typename ResultType_, typename EngineResultType_,
    std::size_t W, std::size_t N, std::size_t M, std::size_t R,
    EngineResultType_ A, std::size_t U, EngineResultType_ D, std::size_t S,
    EngineResultType_ B, std::size_t T,
    EngineResultType_ C, std::size_t L, EngineResultType_ F
>
class StdMersenneTwisterRandomNumberEngine : public RandomNumberEngine<ResultType_, EngineResultType_>
{
    using RandomNumberEngine<ResultType_, EngineResultType_>::ResultType;

    using RandomNumberEngine<ResultType_, EngineResultType_>::EngineResultType;

    using RandomNumberEngine<ResultType_, EngineResultType_>::Seed;

    using RandomNumberEngine<ResultType_, EngineResultType_>::getSeed;

    using Engine = std::mersenne_twister_engine<EngineResultType, W, N, M, R, A, U, D, S, B, T, C, L, F>;

    static_assert(std::is_same<Engine::result_type, EngineResultType>::value, "");

public:
    /**
     * \brief �R���X�g���N�^
     * \param param �����G���W���p�����[�^
     * \param seed �V�[�h������
     */
    StdMersenneTwisterRandomNumberEngine(std::shared_ptr<RandomNumberEngineParameter<ResultType, EngineResultType>> param, std::shared_ptr<SeedGenerator<Seed>> seed)
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
     * \brief �����Z���k�c�C�X�^�[�@
     */
    Engine m_engine;
};
} // namespace random_number_generator
