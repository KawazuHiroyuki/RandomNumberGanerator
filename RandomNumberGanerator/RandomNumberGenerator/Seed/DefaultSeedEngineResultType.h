/*****************************************************************//**
 * \file   DefaultSeedEngineResultType.h
 * \brief  デフォルトシードエンジン生成結果の型
 * 
 * \author japan
 * \date   March 2022
 *********************************************************************/

#pragma once

// My
#include "Engine/RandomNumberBaseEngine.h"

namespace random_number_generator
{
/**
 * \brief デフォルトシードエンジン生成結果の型
 * \tparam Engine 乱数エンジン
 */
template <typename Engine>
using DefaultSeedEngineResultType = typename BaseEngineResultType<Engine, Seed>;
} // namespace random_number_generator
