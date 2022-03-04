/*****************************************************************//**
 * \file   RandomNumberDistributionParameter.h
 * \brief  乱数分布パラメータ
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// My
#include "ID/RandomNumberDistributionID.h"

namespace random_number_generator
{
/**
 * \brief 乱数分布パラメータ
 */
struct RandomNumberDistributionParameter
{
    /**
     * \brief コンストラクタ
     * \param id_ 乱数分布ID
     */
    RandomNumberDistributionParameter(RandomNumberDistributionID id_ = DEFAULT_RANDOM_NUMBER_DISTRIBUTION_ID)
        : id(id_)
    {
    }

    /**
     * \brief 乱数分布ID
     */
    RandomNumberDistributionID id = DEFAULT_RANDOM_NUMBER_DISTRIBUTION_ID;
};
} // namespace random_number_generator
