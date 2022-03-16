/*****************************************************************//**
 * \file   StdMinStdRand0BaseEngineTraits.h
 * \brief  メルセンヌツイスターの64ビット版擬似乱数生成器の乱数ベースエンジン特性
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
 * \brief メルセンヌツイスターの64ビット版擬似乱数生成器の乱数ベースエンジン特性
 * \note std::mt19937_64
 */
using StdMt199937_64BitBaseEngineTraits = AbstractBaseEngineTraits<std::mt19937_64, RandomNumberEngineID::StdMt199937_64Bit>;
} // namespace random_number_generator
