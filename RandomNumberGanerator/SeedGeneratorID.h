/*****************************************************************//**
 * \file   SeedGeneratorID.h
 * \brief  シード生成器ID
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/
#pragma once
namespace random_number_generator
{
    /**
     * \brief シード生成器ID
     */
    enum class SeedGeneratorID {
        // C++標準
        StdRandomDevice = 0, //!< 予測不能な乱数生成器
        // 固有
        CurrentTime, //!< 現在時刻 (非推奨)
        // Custom
        Custom, //!< カスタム
    };
} // namespace random_number_generator
