/*****************************************************************//**
 * \file   RandomNumberEngineID.h
 * \brief  乱数エンジンID
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <cstddef>

namespace random_number_generator
{
/**
 * \brief 乱数エンジンID
 */
enum class RandomNumberEngineID {
    // C++標準:真乱数生成器
    StdRandomDevice = 0, //!< 予測不能な乱数生成器 (Non-deterministic random numbers)
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
    StdKnuth, //!< KnuthリオーダーアルゴリズムB
    StdDefaultRandomEngine, //!< 非専門用途でデフォルト使用する疑似乱数エンジン (使用するエンジンは実装依存)
};

/**
 * \brief 乱数エンジンID数
 */
constexpr std::size_t RANDOM_NUMBER_ENGINE_ID_SIZE = static_cast<std::size_t>(RandomNumberEngineID::StdDefaultRandomEngine) + 1;

/**
 * \brief デフォルトの乱数エンジンID
 */
constexpr RandomNumberEngineID DEFAULT_RANDOM_NUMBER_ENGINE_ID = RandomNumberEngineID::StdDefaultRandomEngine;

/**
 * \brief 真性乱数エンジンか判定
 * \param id 乱数エンジンID
 * \return true:真性乱数、false:真性乱数でない
 */
constexpr bool isTrueRandomNumberEngine(RandomNumberEngineID id)
{
    return (RandomNumberEngineID::StdRandomDevice == id);
}

/**
 * \brief 疑似乱数エンジンか判定
 * \param id 乱数エンジンID
 * \return true:疑似乱数、false:疑似乱数でない
 */
constexpr bool isPseudoRandomNumberEngine(RandomNumberEngineID id)
{
    switch (id) {
        case RandomNumberEngineID::StdLiearCongruential:
        case RandomNumberEngineID::StdMersenneTwister:
        case RandomNumberEngineID::StdSubtractWithCarry:
        case RandomNumberEngineID::StdMinStdRand0:
        case RandomNumberEngineID::StdMinStdRand:
        case RandomNumberEngineID::StdMt199937_32Bit:
        case RandomNumberEngineID::StdMt199937_64Bit:
        case RandomNumberEngineID::StdRanlux24:
        case RandomNumberEngineID::StdRanlux48:
        case RandomNumberEngineID::StdKnuth:
        case RandomNumberEngineID::StdDefaultRandomEngine:
            return true;
        default:
            return false;
    }
}
} // namespace random_number_generator
