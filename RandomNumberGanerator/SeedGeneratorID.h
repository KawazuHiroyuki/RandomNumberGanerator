/*****************************************************************//**
 * \file   SeedGeneratorID.h
 * \brief  �V�[�h������ID
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/
#pragma once
namespace random_number_generator
{
    /**
     * \brief �V�[�h������ID
     */
    enum class SeedGeneratorID {
        // C++�W��
        StdRandomDevice = 0, //!< �\���s�\�ȗ���������
        // �ŗL
        CurrentTime, //!< ���ݎ��� (�񐄏�)
        // Custom
        Custom, //!< �J�X�^��
    };
} // namespace random_number_generator
