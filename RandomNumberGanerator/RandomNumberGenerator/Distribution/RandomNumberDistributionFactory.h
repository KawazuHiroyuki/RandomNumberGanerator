/*****************************************************************//**
 * \file   RandomNumberDistributionFactory.h
 * \brief  乱数分布ファクトリ
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include "AbstractBaseDistributionTraits.h"

namespace random_number_generator
{
 /**
  * \brief 乱数分布ファクトリ
  * \tparam BaseDistributionTraits_ ベース乱数分布特性
  */
template <typename BaseDistributionTraits_>
class RandomNumberDistributionFactory
{

    using BaseDistributionTraits = BaseDistributionTraits_;

    /**
     * \brief ベース乱数分布
     */
    using BaseDistribution = typename BaseDistributionTraits::BaseDistribution;

    /**
     * \brief デフォルトの乱数分布生成結果の型
     */
    using DefaultDistributionResultType = typename BaseDistributionTraits::DefaultDistributionResultType;

    /**
     * \brief 乱数分布ID
     */
    static constexpr RandomNumberDistributionID ID = BaseDistributionTraits::ID;
};





} // namespace random_number_generator
