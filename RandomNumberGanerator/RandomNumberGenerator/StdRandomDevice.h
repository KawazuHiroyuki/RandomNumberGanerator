/*****************************************************************//**
 * \file   StdRandomDevice.h
 * \brief  予測不能な乱数生成器
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// My
#include "Engine/RandomNumberBaseEngineFactory.h"
#include "AbstractTrueRandomNumberGenerator.h"

namespace random_number_generator
{
/**
 * \brief 予測不能な乱数生成器
 * \note std::random_device
 */
class StdRandomDevice : public AbstractTrueRandomNumberGenerator<StdRandomDeviceBaseEngineFactory>
{
private:
    /**
     * \brief 基底クラス
     */
    using Base = AbstractTrueRandomNumberGenerator<StdRandomDeviceBaseEngineFactory>;

public:
    /**
     * \brief コンストラクタ
     */
    StdRandomDevice(void)
        : Base()
    {}
};
} // namespace random_number_generator
