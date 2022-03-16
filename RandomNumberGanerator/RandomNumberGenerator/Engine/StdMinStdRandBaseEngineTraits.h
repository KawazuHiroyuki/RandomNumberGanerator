/*****************************************************************//**
 * \file   StdMinStdRandBaseEngineTraits.h
 * \brief  最小標準MINSTDのパラメータ改良版擬似乱数生成器の乱数ベースエンジン特性
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
 * \brief 最小標準MINSTDのパラメータ改良版擬似乱数生成器の乱数ベースエンジン特性
 * \note std::minstd_rand
 */
using StdMinStdRandBaseEngineTraits = AbstractBaseEngineTraits<std::minstd_rand, RandomNumberEngineID::StdMinStdRand>;
} // namespace random_number_generator
