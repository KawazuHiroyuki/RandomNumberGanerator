/*****************************************************************//**
 * \file   StdPiecewiseConstantDistribution.h
 * \brief  �w�肳�ꂽ��ԂɈ��ɕ��z
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <initializer_list>
// My
#include "PrimaryRandomNumberDistribution.h"
#include "RandomNumberDistributionUtility.h"

namespace random_number_generator
{
/**
 * \brief �w�肳�ꂽ��ԂɈ��ɕ��z
 * \note std::piecewise_constant_distribution
 * \tparam DistributionResultType_ �������z �������ʂ̌^
 */
template <
    typename DistributionResultType_ = double
>
class StdPiecewiseConstantDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdPiecewiseConstantDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdPiecewiseConstantDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdPiecewiseConstantDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \tparam UnaryOperation �P���֐��I�u�W�F�N�g
     * \param wl ��Ԑ���
     * \param fw �d�ݕt�����v�Z����֐�
     */
    template <typename UnaryOperation>
    StdPiecewiseConstantDistribution(std::initializer_list<DistributionResultType_> wl, UnaryOperation fw)
        : Base(RandomNumberDistributionID::StdPiecewiseConstant, Distribution(wl))
    {
    }

    /**
     * \brief �R���X�g���N�^
     * \tparam UnaryOperation �P���֐��I�u�W�F�N�g
     * \param nw ��ԗ�̗v�f��
     * \param xmin ��Ԃ̍ŏ��l
     * \param xmax ��Ԃ̍ő�l
     * \param fw �e��Ԃɑ΂���d�ݒl�����߂邽�߂̊֐�
     */
    template <typename UnaryOperation>
    StdPiecewiseConstantDistribution(std::size_t nw, DistributionResultType_ xmin, DistributionResultType_ xmax, UnaryOperation fw)
        : Base(RandomNumberDistributionID::StdPiecewiseConstant, Distribution(nw, xmin, xmax, fw))
    {
    }
};
} // namespace random_number_generator
