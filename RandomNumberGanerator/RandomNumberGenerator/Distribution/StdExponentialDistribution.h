/*****************************************************************//**
 * \file   StdExponentialDistribution.h
 * \brief  �w�����z
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
 * \brief �w�����z
 * \note std::exponential_distribution
 * \tparam DistributionResultType_ �������z �������ʂ̌^
 */
template <
    typename DistributionResultType_ = double
>
class StdExponentialDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdExponentialDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdExponentialDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdExponentialDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param lambda �w�����z�̃p�����[�^
     */
    StdExponentialDistribution(double lambda)
        : Base(RandomNumberDistributionID::StdExponetial, Distribution(lambda))
    {
    }
};
} // namespace random_number_generator
