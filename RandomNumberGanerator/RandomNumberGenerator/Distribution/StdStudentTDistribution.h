/*****************************************************************//**
 * \file   StdStudentTDistribution.h
 * \brief  スチューデントのt分布
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// My
#include "PrimaryRandomNumberDistribution.h"
#include "RandomNumberBaseDistribution.h"

namespace random_number_generator
{
/**
 * \brief 	スチューデントのt分布
 * \note std::student_t_distribution
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
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
     * \brief コンストラクタ
     * \param n スチューデントのt分布の自由度
     */
    StdStudentTDistribution(DistributionResultType_ n)
        : Base(RandomNumberDistributionID::StdStudentT, Distribution(n))
    {
    }
};
} // namespace random_number_generator
