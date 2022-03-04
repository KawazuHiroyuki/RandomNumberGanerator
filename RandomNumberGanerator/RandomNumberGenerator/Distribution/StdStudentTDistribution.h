/*****************************************************************//**
 * \file   StdStudentTDistribution.h
 * \brief  	�X�`���[�f���g��t���z
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
 * \brief 	�X�`���[�f���g��t���z
 * \note std::student_t_distribution
 * \tparam DistributionResultType_ �������z �������ʂ̌^
 */
template <
    typename DistributionResultType_ = double
>
class StdStudentTDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdStudentTDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdStudentTDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdStudentTDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief �R���X�g���N�^
     * \param n �X�`���[�f���g��t���z�̎��R�x
     */
    StdStudentTDistribution(DistributionResultType_ n)
        : Base(RandomNumberDistributionID::StdStudentT, Distribution(n))
    {
    }
};
} // namespace random_number_generator
