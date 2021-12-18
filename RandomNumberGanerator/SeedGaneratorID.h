/*****************************************************************//**
 * \file   SeedGaneratorID.h
 * \brief  �V�[�h������ID
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/
#pragma once
namespace random_number_ganerator
{
    /**
     * \brief �V�[�h������ID
     */
    enum class SeedGaneratorID {
        // C++�W��
        StdRandomDevice = 0, //!< �\���s�\�ȗ���������
        // �ŗL
        CurrentTime, //!< ���ݎ��� (�񐄏�)
        // Custom
        Custom, //!< �J�X�^��
    };
} // namespace random_number_ganerator
