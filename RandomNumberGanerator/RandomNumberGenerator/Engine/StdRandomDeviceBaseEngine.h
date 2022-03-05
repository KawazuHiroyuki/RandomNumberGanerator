/*****************************************************************//**
 * \file   StdRandomDeviceBaseEngine.h
 * \brief  予測不能な乱数生成器の乱数ベースエンジン
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
 * \brief 予測不能な乱数生成器の乱数ベースエンジン
 * \note std::random_device
 */
class StdRandomDeviceBaseEngine
{
public:
    using BaseEngine = std::random_device;
    using BaseEngineResultType = BaseEngine::result_type;

public:
    static constexpr RandomNumberEngineID ID = RandomNumberEngineID::StdRandomDevice;
};
} // namespace random_number_generator
