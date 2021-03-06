/*****************************************************************//**
 * \file   StdMinStdRand0BaseEngineTraits.h
 * \brief  最小標準MINSTD擬似乱数生成器の乱数ベースエンジン特性
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
 * \brief 最小標準MINSTD擬似乱数生成器の乱数ベースエンジン特性
 * \note std::minstd_rand0
 */
using StdMinStdRand0BaseEngineTraits = AbstractBaseEngineTraits<std::minstd_rand0, RandomNumberEngineID::StdMinStdRand0>;
} // namespace random_number_generator
