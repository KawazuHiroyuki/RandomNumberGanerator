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
#include "RandomNumberEngineID.h"

namespace random_number_generator
{
/**
 * \brief 非専門用途でデフォルト使用する擬似乱数生成器の乱数ベースエンジン特性
 * \note std::default_random_engine
 */
struct StdDefaultRandomEngineBaseEngineTraits
{
    /**
     * \brief ベースエンジン
     */
    using BaseEngine = std::default_random_engine;

    /**
     * \brief ベースエンジン生成結果の型
     */
    using BaseEngineResultType = BaseEngine::result_type;

    /**
     * \brief デフォルトのシードエンジン生成結果の型
     */
    using DefaultSeedEngineResultType = BaseEngine::result_type;

    /**
     * \brief 乱数エンジンID
     */
    static constexpr RandomNumberEngineID ID = RandomNumberEngineID::StdDefaultRandomEngine;
};
} // namespace random_number_generator
