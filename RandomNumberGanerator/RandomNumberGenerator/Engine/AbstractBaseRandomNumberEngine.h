/*****************************************************************//**
 * \file   AbstractBaseRandomNumberEngine.h
 * \brief  抽象ベース乱数エンジン
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

 // C++
 //#include <cstdint>
 // My
#include "AbstractRandomNumberEngine.h"
#include "RandomNumberEngineID.h"

namespace random_number_generator
{
/**
 * \brief 抽象ベース乱数エンジン
 * \tparam EngineResultType_ 乱数エンジン生成結果の型
 */
template <typename EngineResultType_>
class AbstractBaseRandomNumberEngine : public AbstractRandomNumberEngine
{
public:
    /**
     * \brief 乱数エンジン生成結果の型
     */
    using EngineResultType = EngineResultType_;

public:
    /**
     * \brief 乱数を生成
     * \return 乱数
     */
    virtual EngineResultType operator()(void) = 0;

     /**
      * \brief エントロピー(乱数の乱雑さの度合い)を取得
      * \return エントロピー
      */
    virtual double getEntropy(void) const noexcept = 0;

    /**
     * \brief 生成する値の最小値を取得
     * \return 最小値
     */
    virtual EngineResultType getMin(void) const = 0;

    /**
     * \brief 生成する値の最大値を取得
     * \return 最大値
     */
    virtual EngineResultType getMax(void) const = 0;

    /**
     * \brief 乱数エンジンIDを取得
     * \return 乱数エンジンID
     */
    virtual RandomNumberEngineID getRandomNumberEngineID(void) const = 0;
};
} // namespace random_number_generator
