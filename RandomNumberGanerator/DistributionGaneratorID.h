/*****************************************************************//**
 * \file   DistributionGaneratorID.h
 * \brief  ���z������ID
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once
namespace random_number_ganerator
{
    /**
     * \brief ���z������ID
     */
    enum class DistributionGaneratorID {
        NoAdjustment = 0, //!< ������
        // C++�W��:��l���z
        StdUniform, //!< ��l���z
        // C++�W��:�x���k�[�C���z
        StdBernoulli, //!< �x���k�[�C���z
        StdBinomial, //!< �񍀕��z
        StdGeometric, //!< �􉽕��z
        StdNegaivaBinomial, //!< ���̓񍀕��z
        // C++�W��:�|���\�����z
        StdPoisson, //!< �|���\�����z
        StdExponetial, //!< �w�����z
        StdGamma, //!< �K���}���z
        StdWeibull, //!< ���C�u�����z
        StdExtreme, //!< �ɒl���z
        // C++�W��:���K���z
        StdNormal, //!< ���K���z
        StdLognomarl, //!< �ΐ����K���z
        StdChiSquared, //!< �J�C��敪�z
        StdCauchy, //!< �R�[�V�[���z
        StdFisherF, //!< �t�B�b�V���[F���z
        StdStudentT, //!< �X�`���[�f���gT���z
        // C++�W��:�W�{���z
        StdDiscrete, //!< �����C���f�b�N�X���Ƃɗ��U�����m�����z
        StdPiecewiseConstant, //!< ��Ԃ��Ƃ̏d�ݕt����ᐔ�l�Ƃ������z
        StdPiecewiseLinear, //!< ��Ԃ��Ƃ̏d�݂Â�����`�ɐڑ��������z
    };
} // namespace random_number_ganerator
