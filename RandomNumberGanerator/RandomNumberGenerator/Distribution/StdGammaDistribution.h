/*****************************************************************//**
 * \file   StdGammaDistribution.h
 * \brief  �K���}���z
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
 * \brief �K���}���z
 * \note std::gamma_distribution
 * \tparam DistributionResultType_ �������z �������ʂ̌^
 */
template <
    typename DistributionResultType_ = double
>
class StdGammaDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdGammaDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdGammaDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdGammaDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param alpha �K���}���z�̌`��ꐔ
     * \param beta �K���}���z�̎ړx�ꐔ
     */
    StdGammaDistribution(DistributionResultType_ alpha, DistributionResultType_ beta)
        : Base(RandomNumberDistributionID::StdGamma, Distribution(alpha, beta))
    {
    }
};
} // namespace random_number_generator
