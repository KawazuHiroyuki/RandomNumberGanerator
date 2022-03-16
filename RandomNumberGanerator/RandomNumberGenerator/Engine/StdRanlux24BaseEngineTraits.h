/*****************************************************************//**
 * \file   StdMinStdRand0BaseEngineTraits.h
 * \brief  RANLUX法のレベル3擬似乱数生成器の乱数ベースエンジン特性
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
 * \brief RANLUX法のレベル3擬似乱数生成器の乱数ベースエンジン特性
 * \note std::ranlux24
 */
using StdRanlux24BaseEngineTraits = AbstractBaseEngineTraits<std::ranlux24, RandomNumberEngineID::StdRanlux24>;
} // namespace random_number_generator
