/*****************************************************************//**
 * \file   StdMinStdRand0BaseEngineTraits.h
 * \brief  KnuthのリオーダーアルゴリズムB擬似乱数生成器の乱数ベースエンジン特性
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
 * \brief KnuthのリオーダーアルゴリズムB擬似乱数生成器の乱数ベースエンジン特性
 * \note std::knuth_b
 */
using StdKnuthBaseEngineTraits = AbstractBaseEngineTraits<std::knuth_b, RandomNumberEngineID::StdKnuth>;
} // namespace random_number_generator
