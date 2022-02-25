/*****************************************************************//**
 * \file   StdDiscreteDistribution.h
 * \brief  �������z
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <initializer_list>
// MyProject
#include "PrimaryRandomNumberDistribution.h"
#include "RandomNumberDistributionUtility.h"

namespace random_number_generator
{
/**
 * \brief �������z - std::discrete_distribution
 * \tparam DistributionResultType_ �������z �������ʂ̌^
 */
template <
    typename DistributionResultType_ = int
>
class StdDiscreteDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdDiscreteDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdDiscreteDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdDiscreteDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param wl �m���񃊃X�g
     */
    StdDiscreteDistribution(std::initializer_list<double> wl)
        : Base(RandomNumberDistributionID::StdDiscrete, Distribution(wl))
    {
    }

    /**
     * \brief �R���X�g���N�^
     * \tparam UnaryOperation �P���֐��I�u�W�F�N�g
     * \param nw �m����̗v�f��
     * \param xmin �ŏ��m��
     * \param xmax �ő�m��
     * \param fw �m���l�����߂�P���֐�
     */
    template <typename UnaryOperation>
    StdDiscreteDistribution(std::size_t nw, double xmin, double xmax, UnaryOperation fw)
        : Base(RandomNumberDistributionID::StdDiscrete, Distribution(nw, xmin, xmax, fw))
    {
    }
};
} // namespace random_number_generator
