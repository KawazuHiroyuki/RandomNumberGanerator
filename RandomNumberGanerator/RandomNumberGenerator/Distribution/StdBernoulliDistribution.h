/*****************************************************************//**
 * \file   StdBernoulliDistribution.h
 * \brief  �x���k�[�C���z
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
 * \brief �x���k�[�C���z
 * \note std::bernoulli_distribution
 * \tparam DistributionResultType_ �������z �������ʂ̌^
 */
template <
    typename DistributionResultType_
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
