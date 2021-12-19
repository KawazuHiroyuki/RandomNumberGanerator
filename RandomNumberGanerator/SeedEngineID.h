﻿/*****************************************************************//**
 * \file   SeedEngineID.h
 * \brief  シードエンジンID
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

namespace random_number_generator
{
/**
 * \brief シードエンジンID
 */
enum class SeedEngineID {
    // C++標準
    StdRandomDevice = 0, //!< 予測不能な乱数生成器
    // 固有
    CurrentTime, //!< 現在時刻 (非推奨)
    // Custom
    Custom, //!< カスタム
};

constexpr SeedEngineID DEFAULT_SEED_ENGINE_ID = SeedEngineID::StdRandomDevice;
} // namespace random_number_generator