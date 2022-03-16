/*****************************************************************//**
 * \file   StdDefaultRandomEngineBaseEngineTraits.h
 * \brief  非専門用途でデフォルト使用する擬似乱数生成器の乱数ベースエンジン特性
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
 * \brief 非専門用途でデフォルト使用する擬似乱数生成器の乱数ベースエンジン特性
 * \note std::default_random_engine
 */
using StdDefaultRandomEngineBaseEngineTraits = AbstractBaseEngineTraits<std::default_random_engine, RandomNumberEngineID::StdDefaultRandomEngine>;
} // namespace random_number_generator
