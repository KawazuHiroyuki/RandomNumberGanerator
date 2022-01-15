/*****************************************************************//**
 * \file   RandomNumberDistribution.h
 * \brief  乱数分布
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// MyProject
#include "AbstractRandomNumberDistribution.h"

namespace random_number_generator
{
/**
 * \brief 乱数分布
 * \tparam DistributionResultType_ 乱数分布 生成結果の型
 */
template <
    typename DistributionResultType_ = void
>
class RandomNumberDistribution
{
public:
    /**
     * \brief 乱数分布 生成結果の型
     */
    using DistributionResultType = DistributionResultType_;
};
} // namespace random_number_generator
