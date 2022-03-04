/*****************************************************************//**
 * \file   StdNormalDistribution.h
 * \brief  �W�����K(�K�E�X)���z
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
 * \brief �W�����K(�K�E�X)���z
 * \note std::normal_distribution
 * \tparam DistributionResultType_ �������z �������ʂ̌^
 */
template <
    typename DistributionResultType_ = double
>
class StdNormalDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdNormalDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdNormalDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdNormalDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param mean ���K���z�̕��ϒl
     * \param stddev ���K���z�̕W���΍�
     */
    StdNormalDistribution(DistributionResultType_ mean, DistributionResultType_ stddev)
        : Base(RandomNumberDistributionID::StdNormal, Distribution(mean, stddev))
    {
    }
};
} // namespace random_number_generator
