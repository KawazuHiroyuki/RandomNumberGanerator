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
#include "RandomNumberEngineID.h"

namespace random_number_generator
{
/**
 * \brief 最小標準MINSTDのパラメータ改良版擬似乱数生成器の乱数ベースエンジン特性
 * \note std::minstd_rand
 */
struct StdMinStdRandBaseEngineTraits
{
    /**
     * \brief ベースエンジン
     */
    using BaseEngine = std::minstd_rand;

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
    static constexpr RandomNumberEngineID ID = RandomNumberEngineID::StdMinStdRand;
};
} // namespace random_number_generator
