/*****************************************************************//**
 * \file   PrimaryTrueRandomNumberEngine.h
 * \brief  プライマリ真性乱数エンジン
 * 
 * \author japan
 * \date   March 2022
 *********************************************************************/

#pragma once

// C++
#include <memory>
// My
#include "AbstractTrueRandomNumberEngine.h"
#include "RandomNumberEngineParameter.h"

namespace random_number_generator
{
/**
 * \brief プライマリ真性乱数エンジン
 * \tparam BaseEngine_ ベース乱数エンジンの型
 * \tparam BaseEngineResultType_ ベース乱数エンジン生成結果の型
 */
template <
    typename BaseEngine_,
    typename BaseEngineResultType_
>
class PrimaryTrueRandomNumberEngine : public AbstractTrueRandomNumberEngine<BaseEngineResultType_>
{
public:
    /**
     * \brief ベース乱数エンジンの型
     */
    using BaseEngine = BaseEngine_;

public:
    /**
     * \brief コンストラクタ
     */
    PrimaryTrueRandomNumberEngine(const RandomNumberEngineParameter& param)
        : m_param(param)
        , m_baseEngine()
    {
    }

    /**
     * \brief デストラクタ
     */
    virtual ~PrimaryTrueRandomNumberEngine(void) = default;

    /**
     * \brief 乱数を生成
     * \return 乱数
     */
    virtual BaseEngineResultType_ operator()(void) override
    {
        return m_baseEngine();
    }

    /**
     * \brief エントロピー(乱数の乱雑さの度合い)を取得
     * \return エントロピー
     */
    double getEntropy(void) const noexcept override
    {
        return m_baseEngine.entropy();
    }

    /**
     * \brief 生成する値の最小値を取得
     * \return 最小値
     */
    virtual BaseEngineResultType_ getMin(void) const override
    {
        return BaseEngine::min();
    }

    /**
     * \brief 生成する値の最大値を取得
     * \return 最大値
     */
    virtual BaseEngineResultType_ getMax(void) const override
    {
        return BaseEngine::max();
    }

    /**
     * \brief 乱数エンジンIDを取得
     * \return 乱数エンジンID
     */
    RandomNumberEngineID getRandomNumberEngineID(void) const override
    {
        return m_param.id;
    }

protected:
    /**
     * \brief 乱数エンジンパラメータ
     */
    RandomNumberEngineParameter m_param;

    /**
     * \brief ベース乱数エンジン
     */
    BaseEngine m_baseEngine;
};
} // namespace random_number_generator