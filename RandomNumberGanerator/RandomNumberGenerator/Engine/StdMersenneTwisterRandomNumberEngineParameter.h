/*****************************************************************//**
 * \file   StdMersenneTwisterRandomNumberEngineParameter.h
 * \brief  メルセンヌツイスター法 乱数エンジンパラメータ
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <cstddef>
// My
#include "RandomNumberEngineID.h"

namespace random_number_generator
{
/**
 * \brief メルセンヌツイスター法
 * \note std::mersenne_twister_engine
 * \tparam EngineResultType_ 乱数エンジン生成結果の型(符号なし整数)
 * \tparam WordSize_ ワードサイズ
 * \tparam StateSize_ 状態のサイズ
 * \tparam ShiftSize_ シフトサイズ
 * \tparam MaskBits_ マスクのビットサイズ
 * \tparam XorMask_ XORのマスク
 * \tparam TemperingU_ 調律シフトの1stパラメータ
 * \tparam TemperingD_ 調律ビットマスクの2ndパラメータ
 * \tparam TemperingS_ 調律シフトの3rdパラメータ
 * \tparam TemperingB_ 調律ビットマスクの4thパラメータ
 * \tparam TemperingT_ 調律シフトの5thパラメータ
 * \tparam TemperingC_ 調律ビットマスクの6thパラメータ
 * \tparam TemperingL_ 調律シフトの7thパラメータ
 * \tparam InitializationMultiplier_ 初期化の乗数
 */
template <
    typename EngineResultType_,
    std::size_t WordSize_,
    std::size_t StateSize_,
    std::size_t ShiftSize_,
    std::size_t MaskBits_,
    EngineResultType_ XorMask_,
    std::size_t TemperingU_,
    EngineResultType_ TemperingD_,
    std::size_t TemperingS_,
    EngineResultType_ TemperingB_,
    std::size_t TemperingT_,
    EngineResultType_ TemperingC_,
    std::size_t TemperingL_,
    EngineResultType_ InitializationMultiplier_
>
struct StdMersenneTwisterRandomNumberEngineParameter
{
    /**
     * \brief 乱数エンジン生成結果の型(符号なし整数)
     */
    using EngineResultType = EngineResultType_;

    /**
     * \brief ワードサイズ (w)
     * \note 状態シーケンス内での各ワードのビット数。numeric_limits<UIntType>::digits以下にするのがよい。
     */
    static constexpr std::size_t WordSize = WordSize_;

    /**
     * \brief 状態のサイズ (n)
     * \note 状態シーケンスの要素数。生成される値が再発する程度を調整するための値。
     */
    static constexpr std::size_t StateSize = StateSize_;

    /**
     * \brief シフトサイズ (m)
     * \note 各ひねり(twist)時にシーケンスから選択する他の値が、m要素離れるようにする。nより小さくするのがよい。
     */
    static constexpr std::size_t ShiftSize = ShiftSize_;

    /**
     * \brief マスクのビットサイズ (r)
     * \note 各ひねりに対する分離ポイントのマスクサイズ。wよりも小さくするのがよい。
     */
    static constexpr std::size_t MaskBits = MaskBits_;

    /**
     * \brief XORのマスク (a / p)
     * \note 各ひねりに対する分離ポイントのマスクサイズ。wよりも小さくするのがよい。
     */
    static constexpr EngineResultType XorMask = XorMask_;

    /**
     * \brief 調律シフトの1stパラメータ (u)
     * \note 生成アルゴリズムによって使用される、ごちゃ混ぜ処理のシフト値。wよりも小さくするのがよい。
     */
    static constexpr std::size_t TemperingU = TemperingU_;

    /**
     * \brief 調律ビットマスクの2ndパラメータ (d)
     * \note 生成アルゴリズムによって使用される、ごちゃ混ぜ処理のビットマスク値。1u << w以下にするのがよい。
     */
    static constexpr EngineResultType TemperingD = TemperingD_;

    /**
     * \brief 調律シフトの3rdパラメータ (s)
     * \note 生成アルゴリズムによって使用される、ごちゃ混ぜ処理のシフト値。wよりも小さくするのがよい。
     */
    static constexpr std::size_t TemperingS = TemperingS_;

    /**
     * \brief 調律ビットマスクの4thパラメータ (b)
     * \note 生成アルゴリズムによって使用される、ごちゃ混ぜ処理のビットマスク値。1u << w以下にするのがよい。
     */
    static constexpr EngineResultType TemperingB = TemperingB_;

    /**
     * \brief 調律シフトの5thパラメータ (t)
     * \note 生成アルゴリズムによって使用される、ごちゃ混ぜ処理のシフト値。wよりも小さくするのがよい。
     */
    static constexpr std::size_t TemperingT = TemperingT_;

    /**
     * \brief 調律ビットマスクの6thパラメータ (c)
     * \note 生成アルゴリズムによって使用される、ごちゃ混ぜ処理のビットマスク値。1u << w以下にするのがよい。
     */
    static constexpr EngineResultType TemperingC = TemperingC_;

    /**
     * \brief 調律シフトの7thパラメータ (l)
     * \note 生成アルゴリズムによって使用される、ごちゃ混ぜ処理のシフト値。wよりも小さくするのがよい。
     */
    static constexpr std::size_t TemperingL = TemperingL_;

    /**
     * \brief 初期化の乗数 (f)
     * \note ひとつの値をシードとする際の、状態シーケンスのシードとして使用する初期化乗数。
     */
    static constexpr EngineResultType InitializationMultiplier = InitializationMultiplier_;

    /**
     * \brief 乱数エンジンID
     */
    static constexpr RandomNumberEngineID ID = RandomNumberEngineID::StdMersenneTwister;
};
} // namespace random_number_generator
