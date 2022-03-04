/*****************************************************************//**
 * \file   StdCauchyDistribution.h
 * \brief  �R�[�V�[���z
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// My
#include "PrimaryRandomNumberDistribution.h"
#include "RandomNumberDistributionUtility.h"

namespace random_number_generator
{
/**
 * \brief �R�[�V�[���z
 * \note std::cauchy_distribution
 * \tparam DistributionResultType_ �����������ʂ̌^(����)
 */
template <
    typename DistributionResultType_ = double
>
class StdCauchyDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdCauchyDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdCauchyDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdCauchyDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param a �R�[�V�[���z�̈ʒu�ꐔ
     * \param b �R�[�V�[���z�̎ړx�ꐔ
     */
    StdCauchyDistribution(DistributionResultType_ a, DistributionResultType_ b)
        : Base(RandomNumberDistributionID::StdCauchy, Distribution(a, b))
    {
    }
};
} // namespace random_number_generator