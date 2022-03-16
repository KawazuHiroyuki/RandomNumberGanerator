/*****************************************************************//**
 * \file   AbstractTrueRandomNumberGenerator.h
 * \brief  抽象真性乱数生成器
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// My
#include "Engine/PrimaryTrueRandomNumberEngine.h"
#include "AbstractBaseRandomNumberGenerator.h"

namespace random_number_generator
{
/**
 * \brief 抽象真性乱数生成器
 * \tparam BaseEngineFactory_ 乱数ベースエンジンファクトリ
 */
template <typename BaseEngineFactory_>
class AbstractTrueRandomNumberGenerator : public AbstractBaseRandomNumberGenerator
{
private:
    /**
     * \brief 乱数ベースエンジンファクトリ
     */
    using BaseEngineFactory = BaseEngineFactory_;

    /**
     * \brief 乱数ベースエンジン特性
     */
    using BaseEngineTraits = typename BaseEngineFactory::BaseEngineTraits;

    /**
     * \brief 乱数ベースエンジン
     */
    using BaseEngine = typename BaseEngineTraits::BaseEngine;

    /**
     * \brief ベースエンジン生成結果の型
     */
    using BaseEngineResultType = typename BaseEngineTraits::BaseEngineResultType;

    /**
     * \brief 乱数エンジン TODO factoryと共用できないか？
     */
    using Engine = typename PrimaryTrueRandomNumberEngine<BaseEngine, BaseEngineResultType>;

public:
    /**
     * \brief コンストラクタ
     */
    AbstractTrueRandomNumberGenerator(void)
        : m_baseEngine(createBaseEngine())
    {}

    /**
     * \brief 乱数を生成
     * \return 乱数
     */
    BaseEngineResultType operator()(void) /*override*/
    {
        BaseEngineResultType result = getBaseEngine()->operator()();
        return result;
    }

     /**
      * \brief エントロピー(乱数の乱雑さの度合い)を取得
      * \return エントロピー
      */
    virtual double getEntropy(void) const noexcept /*override*/
    {
        double entropy = getBaseEngine()->getEntropy();
        return entropy;
    }

    /**
     * \brief 生成する値の最小値を取得
     * \return 最小値
     */
    virtual BaseEngineResultType getMin(void) const noexcept /*override*/
    {
        BaseEngineResultType min = getBaseEngine()->getMin();
        return min;
    }

    /**
     * \brief 生成する値の最大値を取得
     * \return 最大値
     */
    virtual BaseEngineResultType getMax(void) const noexcept /*override*/
    {
        BaseEngineResultType max = getBaseEngine()->getMax();
        return max;
    }

private:
    /**
     * \brief 乱数ベースエンジンを生成
     * \return 乱数ベースエンジン
     */
    std::shared_ptr<AbstractRandomNumberEngine> createBaseEngine(void) const
    {
        BaseEngineFactory factory;
        return factory.create();
    }

    /**
     * \brief 乱数ベースエンジンを取得
     * \return 乱数ベースエンジン
     */
    std::shared_ptr<Engine> getBaseEngine(void) const
    {
        std::shared_ptr<Engine> engine = std::dynamic_pointer_cast<Engine>(m_baseEngine);
        return engine;
    }

private:
    /**
     * \brief 乱数ベースエンジン
     */
    std::shared_ptr<AbstractRandomNumberEngine> m_baseEngine;
};
} // namespace random_number_generator
