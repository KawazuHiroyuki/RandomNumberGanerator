/*****************************************************************//**
 * \file   AbstractBaseRandomNumberGenerator.h
 * \brief  抽象ベース乱数生成器
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <cstdint>
// My
#include "AbstractRandomNumberGenerator.h"

namespace random_number_generator
{
/**
 * \brief 抽象ベース乱数生成器
 */
 //template <typename ResultType_>
class AbstractBaseRandomNumberGenerator : public AbstractRandomNumberGenerator
{
public:
    /**
     * \brief 乱数の型
     */
    //using ResultType = ResultType_;

public:
#if 0
    /**
     * \brief 乱数を生成
     * \tparam ResultType 乱数の型
     * \return 乱数
     */
    template <typename ResultType>
    ResultType operator()(void) = 0;

    /**
     * \brief 指定した回数だけ疑似乱数を生成し、内部状態を進める
     * \param skip 指定回数
     */
    virtual void discard(std::uint64_t skip) = 0;

    /**
     * \brief エントロピー(乱数の乱雑さの度合い)を取得
     * \return エントロピー
     */
    virtual double getEntropy(void) const noexcept = 0;

    /**
     * \brief 生成する値の最小値を取得
     * \return 最小値
     */
    template <typename ResultType>
    constexpr ResultType getMin(void) noexcept = 0;

    /**
     * \brief 生成する値の最大値を取得
     * \return 最大値
     */
    template <typename ResultType>
    constexpr ResultType getMax(void) noexcept = 0;
#endif
};
} // namespace random_number_generator
