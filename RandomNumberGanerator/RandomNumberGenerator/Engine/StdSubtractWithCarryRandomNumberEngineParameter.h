/*****************************************************************//**
 * \file   StdSubtractWithCarryRandomNumberEngineParameter.h
 * \brief  キャリー付き減算法 乱数エンジンパラメータ
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
 * \brief キャリー付き減算法
 * \note std::subtract_with_carry_engine
 * \tparam EngineResultType_ エンジン生成結果の型(符号なし整数)
 * \tparam WordSize_ ワードサイズ
 * \tparam ShortLag_ 短いラグ
 * \tparam LongLag_ 長いラグ
 */
template <
    typename EngineResultType_,
    std::size_t WordSize_,
    std::size_t ShortLag_,
    std::size_t LongLag_
>
struct StdSubtractWithCarryRandomNumberEngineParameter
{
    /**
     * \brief エンジン生成結果の型(符号なし整数)
     */
    using EngineResultType = EngineResultType_;

    /**
     * \brief ワードサイズ (w)
     * \note 0 < w <=std::numeric_limits<EngineResultType_>::digits でなければならない
     */
    static constexpr std::size_t WordSize = WordSize_;

    /**
     * \brief 短いラグ (s)
     * \note 0 < s < r でなければならない
     */
    static constexpr std::size_t ShortLag = ShortLag_;

    /**
     * \brief 長いラグ (r)
     * \note 0 < s < r でなければならない
     */
    static constexpr std::size_t LongLag = LongLag_;

    /**
     * \brief 乱数エンジンID
     */
    static constexpr RandomNumberEngineID ID = RandomNumberEngineID::StdSubtractWithCarry;
};
} // namespace random_number_generator
