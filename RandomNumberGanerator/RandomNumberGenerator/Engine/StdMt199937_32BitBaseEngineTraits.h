/*****************************************************************//**
 * \file   StdMinStdRand0BaseEngineTraits.h
 * \brief  メルセンヌツイスターの32ビット版擬似乱数生成器の乱数ベースエンジン特性
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
 * \brief メルセンヌツイスターの32ビット版擬似乱数生成器の乱数ベースエンジン特性
 * \note std::mt19937
 */
using StdMt199937_32BitBaseEngineTraits = AbstractBaseEngineTraits<std::mt19937, RandomNumberEngineID::StdMt199937_32Bit>;
} // namespace random_number_generator
