/*****************************************************************//**
 * \file   RandomNumberDistribution.h
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
 * \brief �������z - std::uniform_real_distribution
 * \tparam DistributionResultType_ �������z �������ʂ̌^
 */
template <
    typename DistributionResultType_ = double
>
class UniformRealDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<UniformRealDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<UniformRealDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<UniformRealDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param low �����l
     * \param high ����l
     */
    UniformRealDistribution(DistributionResultType_ low, DistributionResultType_ high)
        : Base(RandomNumberDistributionID::StdRealUniform, Distribution(low, high))
    {
    }
};
} // namespace random_number_generator
