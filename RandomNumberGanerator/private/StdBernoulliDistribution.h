/*****************************************************************//**
 * \file   StdBernoulliDistribution.h
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
 * \brief �������z - std::bernoulli_distribution
 * \tparam DistributionResultType_ �������z �������ʂ̌^
 */
template <
    typename DistributionResultType_ = int
>
class StdBernoulliDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdBernoulliDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdBernoulliDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdBernoulliDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param p �m��
     */
    StdBernoulliDistribution(double p)
        : Base(RandomNumberDistributionID::StdBernoulli, Distribution(p))
    {
    }
};
} // namespace random_number_generator
