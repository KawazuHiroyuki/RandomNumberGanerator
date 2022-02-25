/*****************************************************************//**
 * \file   StdWeibullDistribution.h
 * \brief  �������z
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

 // MyProject
#include "PrimaryRandomNumberDistribution.h"
#include "RandomNumberDistributionUtility.h"

namespace random_number_generator
{
/**
 * \brief �������z - std::weibull_distribution
 * \tparam DistributionResultType_ �������z �������ʂ̌^
 */
template <
    typename DistributionResultType_ = double
>
class StdWeibullDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdWeibullDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdWeibullDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdWeibullDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param a ���C�v�����z�̌`��p�����[�^
     * \param b ���C�v�����z�̎ړx�p�����[�^
     */
    StdWeibullDistribution(DistributionResultType_ a, DistributionResultType_ b)
        : Base(RandomNumberDistributionID::StdWeibull, Distribution(a, b))
    {
    }
};
} // namespace random_number_generator
