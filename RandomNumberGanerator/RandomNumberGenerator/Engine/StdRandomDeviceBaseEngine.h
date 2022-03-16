/*****************************************************************//**
 * \file   StdRandomDeviceBaseEngine.h
 * \brief  予測不能な乱数生成器の乱数ベースエンジン特性
 * 
 * \author japan
 * \date   March 2022
 *********************************************************************/

#pragma once

// My
#include "RandomNumberEngineID.h"

namespace random_number_generator
{
/**
 * \brief 予測不能な乱数生成器の乱数ベースエンジン特性
 * \note std::random_device
 */
struct StdRandomDeviceBaseEngine // Traits
{
    using BaseEngine = std::random_device;
    using BaseEngineResultType = BaseEngine::result_type;

    static constexpr RandomNumberEngineID ID = RandomNumberEngineID::StdRandomDevice;
};
} // namespace random_number_generator
