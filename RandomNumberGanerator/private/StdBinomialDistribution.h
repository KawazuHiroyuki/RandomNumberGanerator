/*****************************************************************//**
 * \file   StdBinomialDistribution.h
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
 * \brief �������z - std::binomial_distribution
 * \tparam DistributionResultType_ �������z �������ʂ̌^
 */
template <
    typename DistributionResultType_ = int
>
class StdBinomialDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdBinomialDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdBinomialDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdBinomialDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param t ���s��
     * \param p �m��
     */
    StdBinomialDistribution(DistributionResultType_ t, double p)
        : Base(RandomNumberDistributionID::StdBinomial, Distribution(t, p))
    {
    }
};
} // namespace random_number_generator
