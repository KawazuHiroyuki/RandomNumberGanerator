/*****************************************************************//**
 * \file   StdMinStdRand0BaseEngineTraits.h
 * \brief  RANLUX法のレベル4擬似乱数生成器の乱数ベースエンジン特性
 *
 * \author japan
 * \date   March 2022
 *********************************************************************/

#pragma once

// C++
#include <random>
// My
#include "AbstractBaseEngineTraits.h"

namespace random_number_generator
{
/**
 * \brief RANLUX法のレベル4擬似乱数生成器の乱数ベースエンジン特性
 * \note std::ranlux48
 */
using StdRanlux48BaseEngineTraits = AbstractBaseEngineTraits<std::ranlux48, RandomNumberEngineID::StdRanlux48>;
} // namespace random_number_generator
