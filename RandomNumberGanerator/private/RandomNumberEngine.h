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
#include "AbstractRandomNumberEngine.h"
#include "SeedEngine.h"

namespace random_number_generator
{
/**
 * \brief 乱数エンジン
 * \tparam EngineResultType_ 生成する符号なし整数の型
 * \tparam Seed_ シードの型
 */
template <
    typename EngineResultType_,
    typename Seed_ = void
>
class RandomNumberEngine : public AbstractRandomNumberEngine
{
public:
    /**
     * \brief 乱数エンジンが生成する乱数の型
     */
    using EngineResultType = EngineResultType_;

    /**
     * \brief シードの型
     */
    using Seed = Seed_;

public:
    /**
     * \brief コンストラクタ
     * \param param 乱数エンジンパラメータ
     * \param seed シード生成器
     */
    RandomNumberEngine(const RandomNumberEngineParameter& param, std::shared_ptr<SeedEngine<Seed>> seed)
        : m_param(param)
        , m_seed(seed)
    {
    }

    virtual ~RandomNumberEngine(void) = default;

    /**
     * \brief 乱数を生成
     * \return 乱数
     */
    virtual EngineResultType operator()(void) = 0;



    RandomNumberEngineID getRandomNumberEngineID(void) const override
    {
        return m_param.id;
    }

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
    RandomNumberEngineParameter m_param;

    /**
     * \brief シードエンジン
     */
    std::shared_ptr<SeedEngine<Seed>> m_seed;
};
} // namespace random_number_generator
