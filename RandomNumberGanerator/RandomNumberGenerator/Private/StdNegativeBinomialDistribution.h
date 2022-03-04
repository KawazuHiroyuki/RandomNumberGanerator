/*****************************************************************//**
 * \file   StdNegativeBinomialDistribution.h
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
 * \brief �������z - std::negative_binomial_distribution
 * \tparam DistributionResultType_ �������z �������ʂ̌^
 */
template <
    typename DistributionResultType_ = int
>
class StdNegativeBinomialDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdNegativeBinomialDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdNegativeBinomialDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdNegativeBinomialDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param k ������
     * \param p �m��
     */
    StdNegativeBinomialDistribution(DistributionResultType_ k, double p)
        : Base(RandomNumberDistributionID::StdNegaivaBinomial, Distribution(k, p))
    {
    }
};
} // namespace random_number_generator
