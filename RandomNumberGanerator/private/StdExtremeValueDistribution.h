/*****************************************************************//**
 * \file   StdExtremeValueDistribution.h
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
 * \brief �������z - std::extreme_value_distribution
 * \tparam DistributionResultType_ �������z �������ʂ̌^
 */
template <
    typename DistributionResultType_ = double
>
class StdExtremeValueDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdExtremeValueDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdExtremeValueDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdExtremeValueDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param a �ɒl���z�̈ʒu�p�����[�^
     * \param b �ɒl���z�̎ړx�p�����[�^
     */
    StdExtremeValueDistribution(DistributionResultType_ a, DistributionResultType_ b)
        : Base(RandomNumberDistributionID::StdExtreme, Distribution(a, b))
    {
    }
};
} // namespace random_number_generator
