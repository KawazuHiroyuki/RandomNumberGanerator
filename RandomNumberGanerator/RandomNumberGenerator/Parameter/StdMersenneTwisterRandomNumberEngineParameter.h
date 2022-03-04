/*****************************************************************//**
 * \file   StdMersenneTwisterRandomNumberEngineParameter.h
 * \brief  �����G���W���p�����[�^ - std::mersenne_twister_engine
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <cstddef>

#include "RandomNumberEngineID.h"

namespace random_number_generator
{
/**
 * \brief �����G���W���p�����[�^ - std::mersenne_twister_engine
 * \tparam EngineResultType_ �������镄���Ȃ������̌^
 * \tparam WordSize_ ���[�h�T�C�Y
 * \tparam StateSize_ ��Ԃ̃T�C�Y
 * \tparam ShiftSize_ �V�t�g�T�C�Y
 * \tparam MaskBits_ �}�X�N�̃r�b�g�T�C�Y
 * \tparam XorMask_ XOR�̃}�X�N
 * \tparam TemperingU_ �����V�t�g��1st�p�����[�^
 * \tparam TemperingD_ �����r�b�g�}�X�N��2nd�p�����[�^
 * \tparam TemperingS_ �����V�t�g��3rd�p�����[�^
 * \tparam TemperingB_ �����r�b�g�}�X�N��4th�p�����[�^
 * \tparam TemperingT_ �����V�t�g��5th�p�����[�^
 * \tparam TemperingC_ �����r�b�g�}�X�N��6th�p�����[�^
 * \tparam TemperingL_ �����V�t�g��7th�p�����[�^
 * \tparam InitializationMultiplier_ �������̏搔
 */
template <
    typename EngineResultType_,
    std::size_t WordSize_,
    std::size_t StateSize_,
    std::size_t ShiftSize_,
    std::size_t MaskBits_,
    EngineResultType_ XorMask_,
    std::size_t TemperingU_,
    EngineResultType_ TemperingD_,
    std::size_t TemperingS_,
    EngineResultType_ TemperingB_,
    std::size_t TemperingT_,
    EngineResultType_ TemperingC_,
    std::size_t TemperingL_,
    EngineResultType_ InitializationMultiplier_
>
struct StdMersenneTwisterRandomNumberEngineParameter
{
    /**
     * \brief �����G���W�����������闐���̌^
     */
    using EngineResultType = EngineResultType_;

    /**
     * \brief ���[�h�T�C�Y (w)
     * \note ��ԃV�[�P���X���ł̊e���[�h�̃r�b�g���Bnumeric_limits<UIntType>::digits�ȉ��ɂ���̂��悢�B
     */
    static constexpr std::size_t WordSize = WordSize_;

    /**
     * \brief ��Ԃ̃T�C�Y (n)
     * \note ��ԃV�[�P���X�̗v�f���B���������l���Ĕ�������x�𒲐����邽�߂̒l�B
     */
    static constexpr std::size_t StateSize = StateSize_;

    /**
     * \brief �V�t�g�T�C�Y (m)
     * \note �e�Ђ˂�(twist)���ɃV�[�P���X����I�����鑼�̒l���Am�v�f�����悤�ɂ���Bn��菬��������̂��悢�B
     */
    static constexpr std::size_t ShiftSize = ShiftSize_;

    /**
     * \brief �}�X�N�̃r�b�g�T�C�Y (r)
     * \note �e�Ђ˂�ɑ΂��镪���|�C���g�̃}�X�N�T�C�Y�Bw��������������̂��悢�B
     */
    static constexpr std::size_t MaskBits = MaskBits_;

    /**
     * \brief XOR�̃}�X�N (a / p)
     * \note �e�Ђ˂�ɑ΂��镪���|�C���g�̃}�X�N�T�C�Y�Bw��������������̂��悢�B
     */
    static constexpr EngineResultType XorMask = XorMask_;

    /**
     * \brief �����V�t�g��1st�p�����[�^ (u)
     * \note �����A���S���Y���ɂ���Ďg�p�����A�����፬�������̃V�t�g�l�Bw��������������̂��悢�B
     */
    static constexpr std::size_t TemperingU = TemperingU_;

    /**
     * \brief �����r�b�g�}�X�N��2nd�p�����[�^ (d)
     * \note �����A���S���Y���ɂ���Ďg�p�����A�����፬�������̃r�b�g�}�X�N�l�B1u << w�ȉ��ɂ���̂��悢�B
     */
    static constexpr EngineResultType TemperingD = TemperingD_;

    /**
     * \brief �����V�t�g��3rd�p�����[�^ (s)
     * \note �����A���S���Y���ɂ���Ďg�p�����A�����፬�������̃V�t�g�l�Bw��������������̂��悢�B
     */
    static constexpr std::size_t TemperingS = TemperingS_;

    /**
     * \brief �����r�b�g�}�X�N��4th�p�����[�^ (b)
     * \note �����A���S���Y���ɂ���Ďg�p�����A�����፬�������̃r�b�g�}�X�N�l�B1u << w�ȉ��ɂ���̂��悢�B
     */
    static constexpr EngineResultType TemperingB = TemperingB_;

    /**
     * \brief �����V�t�g��5th�p�����[�^ (t)
     * \note �����A���S���Y���ɂ���Ďg�p�����A�����፬�������̃V�t�g�l�Bw��������������̂��悢�B
     */
    static constexpr std::size_t TemperingT = TemperingT_;

    /**
     * \brief �����r�b�g�}�X�N��6th�p�����[�^ (c)
     * \note �����A���S���Y���ɂ���Ďg�p�����A�����፬�������̃r�b�g�}�X�N�l�B1u << w�ȉ��ɂ���̂��悢�B
     */
    static constexpr EngineResultType TemperingC = TemperingC_;

    /**
     * \brief �����V�t�g��7th�p�����[�^ (l)
     * \note �����A���S���Y���ɂ���Ďg�p�����A�����፬�������̃V�t�g�l�Bw��������������̂��悢�B
     */
    static constexpr std::size_t TemperingL = TemperingL_;

    /**
     * \brief �������̏搔 (f)
     * \note �ЂƂ̒l���V�[�h�Ƃ���ۂ́A��ԃV�[�P���X�̃V�[�h�Ƃ��Ďg�p���鏉�����搔�B
     */
    static constexpr EngineResultType InitializationMultiplier = InitializationMultiplier_;

    /**
     * \brief �����G���W��ID
     */
    static constexpr RandomNumberEngineID ID = RandomNumberEngineID::StdMersenneTwister;
};
} // namespace random_number_generator
