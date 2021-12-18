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
template <typename Type, typename EngineType,
    std::size_t W, std::size_t N, std::size_t M, std::size_t R,
    EngineType A, std::size_t U, EngineType D, std::size_t S,
    EngineType B, std::size_t T,
    EngineType C, std::size_t L, EngineType F
>
class StdMersenneTwisterRandomNumberEngine : public RandomNumberEngine<Type, EngineType>
{
    static_assert(std::is_same<std::mersenne_twister_engine<EngineType, W, N, M, R, A, U, D, S, B, T, C, L, F>::result_type, EngineType>::value, "");

public:
    /**
     * \brief �R���X�g���N�^
     * \param param �����G���W���p�����[�^
     * \param seed �V�[�h������
     */
    StdMersenneTwisterRandomNumberEngine(std::shared_ptr<RandomNumberEngineParameter<Type, EngineType>> param, std::shared_ptr<SeedGenerator<EngineType>> seed)
        : RandomNumberEngine<Type, EngineType>(param, seed)
        , m_engine(RandomNumberEngine<Type, EngineType>::getSeed())
    {
    }

    /**
     * \brief �����𐶐�
     * \return ����
     */
    typename StdMersenneTwisterRandomNumberEngine::EngineRandom operator()(void) override
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
    constexpr typename StdMersenneTwisterRandomNumberEngine::EngineRandom getMin(void) const override
    {
        return m_engine.min();
    }

    /**
     * \brief ��������l�̍ő�l���擾
     * \return �ő�l
     */
    constexpr typename StdMersenneTwisterRandomNumberEngine::EngineRandom getMax(void) const override
    {
        return m_engine.max();
    }

private:
    /**
     * \brief �����Z���k�c�C�X�^�[�@
     */
    std::mersenne_twister_engine<EngineType, W, N, M, R, A, U, D, S, B, T, C, L, F> m_engine;
};
} // namespace random_number_generator
