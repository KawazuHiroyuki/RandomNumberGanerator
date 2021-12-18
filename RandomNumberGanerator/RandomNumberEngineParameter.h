/*****************************************************************//**
 * \file   RandomNumberEngineParameter.h
 * \brief  乱数エンジンパラメータ
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include "RandomNumberEngineID.h"

namespace random_number_generator
{
/**
 * \brief 乱数エンジンパラメータ
 */
template <typename T1, typename T2>
struct RandomNumberEngineParameter
{
    /**
     * \brief 生成する乱数の型
     */
    using ResultType = T1;

    /**
     * \brief 乱数エンジンが生成する乱数の型
     */
    using EngineResultType = T2;

    /**
     * \brief 乱数エンジンID
     */
    RandomNumberEngineID id = DEFAULT_RANDOM_NUMBER_ENGINE_ID;
};
} // namespace random_number_generator
