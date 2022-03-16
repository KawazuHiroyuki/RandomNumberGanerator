/*****************************************************************//**
 * \file   StdRandomDeviceBaseEngineTraits.h
 * \brief  予測不能な乱数生成器の乱数ベースエンジン特性
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
 * \brief 予測不能な乱数生成器の乱数ベースエンジン特性
 * \note std::random_device
 */
struct StdRandomDeviceBaseEngineTraits
{
    /**
     * \brief ベースエンジン
     */
    using BaseEngine = std::random_device;

    /**
     * \brief ベースエンジン生成結果の型
     */
    using BaseEngineResultType = BaseEngine::result_type;

    /**
     * \brief 乱数エンジンID
     */
    static constexpr RandomNumberEngineID ID = RandomNumberEngineID::StdRandomDevice;
};
} // namespace random_number_generator
