/*****************************************************************//**
 * \file   DefaultSeedEngine.h
 * \brief  デフォルトシードエンジン
 * 
 * \author japan
 * \date   March 2022
 *********************************************************************/

#pragma once

// My
#include "StdRandomDeviceSeedEngine.h"

namespace random_number_generator
{
/**
 * \brief デフォルトシードエンジン
 * \tparam SeedEngineResultType_ シードエンジン生成結果の型
 */
template <typename SeedEngineResultType_>
using DefaultSeedEngine = StdRandomDeviceSeedEngine<SeedEngineResultType_>;
} // namespace random_number_generator
