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
#include "AbstractRandomNumberEngine.h"
#include "RandomNumberEngineParameter.h"

namespace random_number_generator
{
/**
 * \brief プライマリ真性乱数エンジン
 * \tparam Engine_ エンジンの型
 * \tparam EngineResultType_ エンジン生成結果の型
 */
template <
    typename Engine_,
    typename EngineResultType_
>
class PrimaryTrueRandomNumberEngine : public AbstractRandomNumberEngine<EngineResultType_>
{
public:
    /**
     * \brief エンジンの型
     */
    using Engine = Engine_;

public:
    /**
     * \brief コンストラクタ
     */
    PrimaryTrueRandomNumberEngine(void)
        : m_param(RandomNumberEngineID::StdRandomDevice)
        , m_engine()
    {
    }

    virtual ~PrimaryTrueRandomNumberEngine(void) = default;

    /**
     * \brief 乱数を生成
     * \return 乱数
     */
    virtual EngineResultType_ operator()(void) override
    {
        return m_engine();
    }

    /**
     * \brief 指定した回数だけ疑似乱数を生成し、内部状態を進める
     * \param times 指定回数
     */
    void discard(std::uint64_t skip) override
    {
        // なし
    }

    /**
     * \brief エントロピー(乱数の乱雑さの度合い)を取得
     * \return エントロピー
     */
    double getEntropy(void) const noexcept override
    {
        return m_engine.entropy();
    }

    /**
     * \brief 生成する値の最小値を取得
     * \return 最小値
     */
    virtual EngineResultType_ getMin(void) const override
    {
        return Engine::min();
    }

    /**
     * \brief 生成する値の最大値を取得
     * \return 最大値
     */
    virtual EngineResultType_ getMax(void) const override
    {
        return Engine::max();
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
     * \brief 乱数エンジン
     */
    Engine m_engine;
};
} // namespace random_number_generator