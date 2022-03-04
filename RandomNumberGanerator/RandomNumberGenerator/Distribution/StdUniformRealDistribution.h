/*****************************************************************//**
 * \file   StdUniformRealDistribution.h
 * \brief  �͈͓��Ɉ�l�ɕ��z���������l
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
 * \brief �͈͓��Ɉ�l�ɕ��z���������l
 * \note std::uniform_real_distribution
 * \tparam DistributionResultType_ �������z �������ʂ̌^
 */
template <
    typename DistributionResultType_ = double
>
class StdUniformRealDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdUniformRealDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdUniformRealDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdUniformRealDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param low �����l
     * \param high ����l
     */
    StdUniformRealDistribution(DistributionResultType_ low, DistributionResultType_ high)
        : Base(RandomNumberDistributionID::StdRealUniform, Distribution(low, high))
    {
    }
};
} // namespace random_number_generator
