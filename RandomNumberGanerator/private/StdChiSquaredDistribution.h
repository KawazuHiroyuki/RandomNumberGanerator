/*****************************************************************//**
 * \file   StdChiSquaredDistribution.h
 * \brief  �������z - std::chi_squared_distribution
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
 * \brief �������z - std::chi_squared_distribution
 * \tparam DistributionResultType_ �����������ʂ̌^(����)
 */
template <
    typename DistributionResultType_ = double
>
class StdChiSquaredDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdChiSquaredDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdChiSquaredDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdChiSquaredDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param n �J�C��敪�z�̎��R�x
     */
    StdChiSquaredDistribution(DistributionResultType_ n)
        : Base(RandomNumberDistributionID::StdChiSquared, Distribution(n))
    {
    }
};
} // namespace random_number_generator
