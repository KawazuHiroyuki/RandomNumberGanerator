/*****************************************************************//**
 * \file   StdMinStdRand0BaseEngine.h
 * \brief  最小標準MINSTD擬似乱数生成器の乱数ベースエンジン
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
 * \brief 最小標準MINSTD擬似乱数生成器の乱数ベースエンジン
 * \note std::minstd_rand0
 */
struct StdMinStdRand0BaseEngine
{
    using BaseEngine = std::minstd_rand0;
    using BaseEngineResultType = BaseEngine::result_type;
    using DefaultSeedEngineResultType = BaseEngine::result_type;

    static constexpr RandomNumberEngineID ID = RandomNumberEngineID::StdMinStdRand0;
};
} // namespace random_number_generator
