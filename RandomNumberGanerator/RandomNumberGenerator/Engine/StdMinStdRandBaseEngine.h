/*****************************************************************//**
 * \file   StdMinStdRandBaseEngine.h
 * \brief  最小標準MINSTDのパラメータ改良版擬似乱数生成器の乱数ベースエンジン
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
 * \brief 最小標準MINSTDのパラメータ改良版擬似乱数生成器の乱数ベースエンジン
 * \note std::minstd_rand
 */
struct StdMinStdRandBaseEngine
{
    using BaseEngine = std::minstd_rand;
    using BaseEngineResultType = BaseEngine::result_type;
    using DefaultSeedEngineResultType = BaseEngine::result_type;

    static constexpr RandomNumberEngineID ID = RandomNumberEngineID::StdMinStdRand;
};
} // namespace random_number_generator
