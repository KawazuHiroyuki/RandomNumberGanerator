/*****************************************************************//**
 * \file   StdFisherFDistribution.h
 * \brief  フィッシャーのF分布
 * 
 * \author japan
 * \date   March 2022
 *********************************************************************/

#pragma once

// My
#include "PrimaryRandomNumberDistribution.h"
#include "RandomNumberBaseDistribution.h"

namespace random_number_generator
{
/**
 * \brief フィッシャーのF分布
 * \note std::fisher_f_distribution
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_ = double
>
class StdFisherFDistribution : public PrimaryRandomNumberDistribution<BaseDistribution<StdFisherFDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>
{
private:
    using Base = PrimaryRandomNumberDistribution<BaseDistribution<StdFisherFDistribution<DistributionResultType_>, DistributionResultType_>, DistributionResultType_>;
    using Distribution = BaseDistribution<StdFisherFDistribution<DistributionResultType_>, DistributionResultType_>;

public:
    /**
     * \brief コンストラクタ
     * \param m フィッシャーのF分布の自由度
     * \param n フィッシャーのF分布の自由度
     */
    StdFisherFDistribution(DistributionResultType_ m, DistributionResultType_ n)
        : Base(RandomNumberDistributionID::StdStudentT, Distribution(m, n))
    {
    }
};
} // namespace random_number_generator