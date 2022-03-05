/*****************************************************************//**
 * \file   StdDefaultRandomEngineBaseEngine.h
 * \brief  非専門用途でデフォルト使用する擬似乱数生成器の乱数ベースエンジン
 *
 * \author japan
 * \date   March 2022
 *********************************************************************/

#pragma once

// C++
#include <cstdint>
#include <random>
// My
#include "RandomNumberEngineID.h"

namespace random_number_generator
{
/**
 * \brief 非専門用途でデフォルト使用する擬似乱数生成器の乱数ベースエンジン
 * \note std::default_random_engine
 */
class StdDefaultRandomEngineBaseEngine
{
public:
    using BaseEngine = std::default_random_engine;
    using BaseEngineResultType = BaseEngine::result_type;
    using DefaultSeedEngineResultType = std::uint32_t;

public:
    static constexpr RandomNumberEngineID ID = RandomNumberEngineID::StdDefaultRandomEngine;
};
} // namespace random_number_generator
