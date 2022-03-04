/*****************************************************************//**
 * \file   StdPoissonDistribution.h
 * \brief  �|�A�\�����z
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
 * \brief �|�A�\�����z
 * \note std::poisson_distribution
 * \tparam DistributionResultType_ �������z �������ʂ̌^
 */
template <
    typename DistributionResultType_ = int
>
class StdPoissonDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdPoissonDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdPoissonDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdPoissonDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param mean �|���\�����z�̕��ϒl
     */
    StdPoissonDistribution(double mean)
        : Base(RandomNumberDistributionID::StdPoisson, Distribution(mean))
    {
    }
};
} // namespace random_number_generator
