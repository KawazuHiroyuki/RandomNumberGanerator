/*****************************************************************//**
 * \file   AbstractRandomNumberEngine.h
 * \brief  ���ۗ����G���W��
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <cstdint>
// My
#include "ID/RandomNumberEngineID.h"

namespace random_number_generator
{
/**
 * \brief ���ۗ����G���W��
 * \tparam EngineResultType_ �����G���W�� �������ʂ̌^
 * \tparam Seed_ �V�[�h�̌^
 */
template <
    typename EngineResultType_,
    typename Seed_ = void // TODO Seed_��AbstractPseudoRandomNumberEngine�Ɉړ�
>
class AbstractRandomNumberEngine
{
public:
    /**
     * \brief �����G���W�����������闐���̌^
     */
    using EngineResultType = EngineResultType_;

    /**
     * \brief �V�[�h�̌^
     */
    using Seed = Seed_;

public:
#if 0
    /**
     * \brief �V�[�h��ݒ�
     * \param seed �V�[�h
     */
    virtual void setSeed(Seed seed) = 0;
#endif

    /**
     * \brief �����𐶐�
     * \return ����
     */
    virtual EngineResultType operator()(void) = 0;

    /**
     * \brief �w�肵���񐔂����^�������𐶐����A������Ԃ�i�߂�
     * \param skip �w���
     */
    virtual void discard(std::uint64_t skip) = 0;

    /**
     * \brief �G���g���s�[(�����̗��G���̓x����)���擾
     * \return �G���g���s�[
     */
    virtual double getEntropy(void) const noexcept = 0;

    /**
     * \brief ��������l�̍ŏ��l���擾
     * \return �ŏ��l
     */
    virtual EngineResultType getMin(void) const = 0;

    /**
     * \brief ��������l�̍ő�l���擾
     * \return �ő�l
     */
    virtual EngineResultType getMax(void) const = 0;

    /**
     * \brief �����G���W��ID���擾
     * \return �����G���W��ID
     */
    virtual RandomNumberEngineID getRandomNumberEngineID(void) const = 0;

protected:
#if 0
    /**
     * \brief �V�[�h���擾
     * \return �V�[�h
     */
    virtual Seed getSeed(void) const = 0;
#endif
};
} // namespace random_number_generator
