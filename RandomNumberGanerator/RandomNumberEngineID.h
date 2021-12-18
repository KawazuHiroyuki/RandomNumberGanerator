/*****************************************************************//**
 * \file   RandomNumberEngineID.h
 * \brief  �����G���W��ID
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/
#pragma once
namespace random_number_ganerator
{
    /**
     * \brief �����G���W��ID
     */
    enum class RandomNumberEngineID {
        // C++�W��:�^����������
        StdRandomDevice, //!< �\���s�\�ȗ���������
        // C++�W��:�^������������
        StdLiearCongruential, //!< ���`�����`�@
        StdMersenneTwister, //!< �����Z���k�c�C�X�^�[�@
        StdSubtractWithCarry, //!< �L�����[�t�����Z�@
        // C++�W��:�p�����[�^��`�ς݋^������������
        StdMinStdRand0, //!< �ŏ��W��MINSTD (���`�����`�@)
        StdMinStdRand, //!< �ŏ��W��MINSTD�̃p�����[�^���ǔ� (���`�����`�@)
        StdMt199937_32Bit, //!< �����Z���k�c�C�X�^�[32bit�� (�����Z���k�c�C�X�^�[�@)
        StdMt199937_64Bit, //!< �����Z���k�c�C�X�^�[64bit�� (�����Z���k�c�C�X�^�[�@)
        StdRanlux24, //!< RANLUX�@ �ґ򂳃��x��3 (�L�����[�t�����Z�@)
        StdRanlux48, //!< RANLUX�@ �ґ򂳃��x��4 (�L�����[�t�����Z�@)
        StdKnuth, //!< Knuth���I�[�_�[�A���S���Y��
        StdDefaultRandomEngine, //!< ����p�r�Ńf�t�H���g�g�p����^�������G���W�� (�g�p����G���W���͎����ˑ�)
    };
} // namespace random_number_ganerator
