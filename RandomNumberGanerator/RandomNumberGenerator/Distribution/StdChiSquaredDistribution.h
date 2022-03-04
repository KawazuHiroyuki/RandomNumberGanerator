/*****************************************************************//**
 * \file   StdChiSquaredDistribution.h
 * \brief  �J�C��敪�z
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
 * \brief �J�C��敪�z
 * \note std::chi_squared_distribution
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
