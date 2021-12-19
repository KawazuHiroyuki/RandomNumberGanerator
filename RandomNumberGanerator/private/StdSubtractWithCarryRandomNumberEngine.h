/*****************************************************************//**
 * \file   StdSubtractWithCarryRandomNumberEngine.h
 * \brief  �����G���W�� - std::subtract_with_carry_engine
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
 * \brief �����G���W�� - std::subtract_with_carry_engine
 * \tparam EngineResultType_ �������镄���Ȃ������̌^
 */
template <typename EngineResultType_,
    std::size_t W, std::size_t S, std::size_t R
>
class StdSubtractWithCarryRandomNumberEngine : public RandomNumberEngine<EngineResultType_>
{
    using Base = RandomNumberEngine<EngineResultType_>;

    using Engine = std::subtract_with_carry_engine<Base::EngineResultType, W, S, R>;

    static_assert(std::is_same<Engine::result_type, Base::EngineResultType>::value, "");

public:
    /**
     * \brief �R���X�g���N�^
     * \param seed �V�[�h�G���W��
     */
    StdSubtractWithCarryRandomNumberEngine(std::shared_ptr<SeedEngine<Base::Seed>> seed)
        : Base(RandomNumberEngineID::StdSubtractWithCarry, seed)
        , m_engine(Base::getSeed())
    {
    }

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
    constexpr Base::EngineResultType getMin(void) const override
    {
        return m_engine.min();
    }

    /**
     * \brief ��������l�̍ő�l���擾
     * \return �ő�l
     */
    constexpr Base::EngineResultType getMax(void) const override
    {
        return m_engine.max();
    }

private:
    /**
     * \brief �L�����[�t�����Z�@
     */
    Engine m_engine;
};
} // namespace random_number_generator
