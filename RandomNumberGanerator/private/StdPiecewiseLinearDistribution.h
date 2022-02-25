/*****************************************************************//**
 * \file   StdPiecewiseLinearDistribution.h
 * \brief  �������z
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

 // C++
#include <initializer_list>
// MyProject
#include "PrimaryRandomNumberDistribution.h"
#include "RandomNumberDistributionUtility.h"

namespace random_number_generator
{
/**
 * \brief �������z - std::piecewise_linear_distribution
 * \tparam DistributionResultType_ �������z �������ʂ̌^
 */
template <
    typename DistributionResultType_ = double
>
class StdPiecewiseLinearDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdPiecewiseLinearDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdPiecewiseLinearDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdPiecewiseLinearDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \tparam UnaryOperation �P���֐��I�u�W�F�N�g
     * \param bl ��Ԑ���
     * \param fw �d�ݕt�����v�Z����֐�
     */
    template <typename UnaryOperation>
    StdPiecewiseLinearDistribution(std::initializer_list<double> bl, UnaryOperation fw)
        : Base(RandomNumberDistributionID::StdPiecewiseLinear, Distribution(bl))
    {
    }

    /**
     * \brief �R���X�g���N�^
     * \tparam UnaryOperation �P���֐��I�u�W�F�N�g
     * \param nw ��ԗ�̗v�f��
     * \param xmin ��Ԃ̍ŏ��l
     * \param xmax ��Ԃ̍ő�l
     * \param fw ��ԗ񂻂ꂼ��̃C���f�b�N�X�ɑ΂���d�ݒl�����߂邽�߂̊֐�
     */
    template <typename UnaryOperation>
    StdPiecewiseLinearDistribution(std::size_t nw, double xmin, double xmax, UnaryOperation fw)
        : Base(RandomNumberDistributionID::StdPiecewiseLinear, Distribution(nw, xmin, xmax, fw))
    {
    }
};
} // namespace random_number_generator
