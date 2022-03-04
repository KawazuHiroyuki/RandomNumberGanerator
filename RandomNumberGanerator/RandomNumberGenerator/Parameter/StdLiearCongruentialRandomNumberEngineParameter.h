/*****************************************************************//**
 * \file   StdLiearCongruentialRandomNumberEngineParameter.h
 * \brief  乱数エンジンパラメータ - std::linear_congruential_engine
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include "RandomNumberEngineID.h"

namespace random_number_generator
{
/**
 * \brief 乱数エンジンパラメータ - std::linear_congruential_engine
 * \tparam EngineResultType_ 生成する符号なし整数の型
 * \tparam Multiplier_ 乗数
 * \tparam Increment_ 増分
 * \tparam Modulus_ 法
 */
template <
    typename EngineResultType_,
    EngineResultType_ Multiplier_,
    EngineResultType_ Increment_,
    EngineResultType_ Modulus_
>
struct StdLiearCongruentialRandomNumberEngineParameter
{
    /**
     * \brief 生成する符号なし整数の型
     */
    using EngineResultType = EngineResultType_;

    /**
     * \brief 乗数(a)
     * \note  m が非 0 の場合 a < m でなければならない
     */
    static constexpr EngineResultType Multiplier = Multiplier_;

    /**
     * \brief 増分(c)
     * \note m が非 0 の場合 c < m でなければならない
     */
    static constexpr EngineResultType Increment = Increment_;

    /**
     * \brief 法(m)
     * \note 0 の場合 std::numeric_limits<EngineResultType_>::max()
     */
    static constexpr EngineResultType Modulus = Modulus_;

    /**
     * \brief 乱数エンジンID
     */
    static constexpr RandomNumberEngineID ID = RandomNumberEngineID::StdLiearCongruential;
};
} // namespace random_number_generator
