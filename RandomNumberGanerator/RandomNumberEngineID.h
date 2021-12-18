/*****************************************************************//**
 * \file   RandomNumberEngineID.h
 * \brief  乱数エンジンID
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/
#pragma once
namespace random_number_ganerator
{
    /**
     * \brief 乱数エンジンID
     */
    enum class RandomNumberEngineID {
        // C++標準:真乱数生成器
        StdRandomDevice, //!< 予測不能な乱数生成器
        // C++標準:疑似乱数生成器
        StdLiearCongruential, //!< 線形合同形法
        StdMersenneTwister, //!< メルセンヌツイスター法
        StdSubtractWithCarry, //!< キャリー付き減算法
        // C++標準:パラメータ定義済み疑似乱数生成器
        StdMinStdRand0, //!< 最小標準MINSTD (線形合同形法)
        StdMinStdRand, //!< 最小標準MINSTDのパラメータ改良版 (線形合同形法)
        StdMt199937_32Bit, //!< メルセンヌツイスター32bit版 (メルセンヌツイスター法)
        StdMt199937_64Bit, //!< メルセンヌツイスター64bit版 (メルセンヌツイスター法)
        StdRanlux24, //!< RANLUX法 贅沢さレベル3 (キャリー付き減算法)
        StdRanlux48, //!< RANLUX法 贅沢さレベル4 (キャリー付き減算法)
        StdKnuth, //!< Knuthリオーダーアルゴリズム
        StdDefaultRandomEngine, //!< 非専門用途でデフォルト使用する疑似乱数エンジン (使用するエンジンは実装依存)
    };
} // namespace random_number_ganerator
