/*****************************************************************//**
 * \file   StdLognormalDistribution.h
 * \brief  �ΐ����K���z
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
 * \brief �ΐ����K���z
 * \note std::lognormal_distribution
 * \tparam DistributionResultType_ �������z �������ʂ̌^
 */
template <
    typename DistributionResultType_ = double
>
class StdLognormalDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdLognormalDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdLognormalDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdLognormalDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param mean �ΐ����K���z�̕��ϒl
     * \param stddev �ΐ����K���z�̕W���΍�
     */
    StdLognormalDistribution(DistributionResultType_ mean, DistributionResultType_ stddev)
        : Base(RandomNumberDistributionID::StdLognomarl, Distribution(mean, stddev))
    {
    }
};
} // namespace random_number_generator
