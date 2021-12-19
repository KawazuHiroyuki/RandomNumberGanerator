/*****************************************************************//**
 * \file   RandomNumberEngine.h
 * \brief  乱数エンジン
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <memory>
#include <cstdint>

#include "../RandomNumberEngineParameter.h"
#include "SeedEngine.h"

namespace random_number_generator
{
/**
 * \brief 乱数エンジン
 */
template <typename ResultType_, typename EngineResultType_>
class RandomNumberEngine
{
public:
    /**
     * \brief 生成する乱数の型
     */
    using ResultType = ResultType_;

    /**
     * \brief 乱数エンジンが生成する乱数の型
     */
    using EngineResultType = EngineResultType_;

    /**
     * \brief 乱数エンジンパラメータの型
     */
    using EngineParameter = RandomNumberEngineParameter<ResultType, EngineResultType>;

    /**
     * \brief シードの型
     */
    using Seed = EngineResultType_;

public:
    /**
     * \brief コンストラクタ
     * \param param 乱数エンジンパラメータ
     * \param seed シード生成器
     */
    RandomNumberEngine(std::shared_ptr<EngineParameter> param, std::shared_ptr<SeedEngine<Seed>> seed)
        : m_param(param)
        , m_seed(seed)
    {
    }

    /**
     * \brief 乱数を生成
     * \return 乱数
     */
    virtual EngineResultType operator()(void) = 0;
    
    /**
     * \brief 指定した回数だけ疑似乱数を生成し、内部状態を進める
     * \param times 指定回数
     */
    virtual void discard(std::uint64_t times) = 0;

    /**
     * \brief エントロピー(乱数の乱雑さの度合い)を取得
     * \return エントロピー
     */
    virtual double getEntropy(void) const noexcept = 0;

    /**
     * \brief 生成する値の最小値を取得
     * \return 最小値
     */
    virtual constexpr EngineResultType getMin(void) const = 0;

    /**
     * \brief 生成する値の最大値を取得
     * \return 最大値
     */
    virtual constexpr EngineResultType getMax(void) const = 0;

protected:
    ///**
    // * \brief 乱数エンジンパラメータを取得
    // * \return 乱数エンジンパラメータ 
    // */
    //std::shared_ptr<RandomNumberEngineParameter<Type, EngineType>> getParam(void) const
    //{
    //    return m_param;
    //}

    /**
     * \brief シードを取得
     * \return シード
     */
    Seed getSeed(void) const
    {
        return (*m_seed)();
    }

protected:
    /**
     * \brief 乱数エンジンパラメータ
     */
    std::shared_ptr<EngineParameter> m_param;

    /**
     * \brief シードエンジン
     */
    std::shared_ptr<SeedEngine<Seed>> m_seed;
};
} // namespace random_number_generator
