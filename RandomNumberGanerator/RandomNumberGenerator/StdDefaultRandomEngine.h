/*****************************************************************//**
 * \file   StdDefaultRandomEngine.h
 * \brief  非専門用途でデフォルト使用する擬似乱数生成器
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// My
#include "Engine/RandomNumberBaseEngineFactory.h"
#include "AbstractPseudoRandomNumberGenerator.h"

namespace random_number_generator
{
/**
 * \brief 非専門用途でデフォルト使用する擬似乱数生成器
 * \note std::default_random_engine
 * \tparam SeedEngineResultType_ シードエンジン生成結果の型
 */
//template <typename SeedEngineResultType_ = StdDefaultRandomEngineBaseEngine::DefaultSeedEngineResultType>
class StdDefaultRandomEngine /*: public AbstractPseudoRandomNumberGenerator*/
{
private:
    using BaseEngineFactory = StdDefaultRandomEngineBaseEngineFactory;
    using BaseEngine = StdDefaultRandomEngineBaseEngine;

private:
    //using SeedEngineResultType = SeedEngineResultType_;

public:
    /**
     * \brief コンストラクタ
     * \param seedParam シードエンジンパラメータ
     */
    template <typename SeedEngineResultType = BaseEngine::DefaultSeedEngineResultType>
    StdDefaultRandomEngine(const SeedEngineParameter<SeedEngineResultType>& seedParam = {})
        : m_baseEngine(createBaseEngine<SeedEngineResultType>(seedParam))
    {
    }

    /**
     * \brief シードエンジンを設定
     * \tparam SeedType_ シードの型
     * \param seed シードエンジン
     */
    template <typename SeedEngineResultType = BaseEngine::DefaultSeedEngineResultType>
    void setSeedEngine(std::shared_ptr<AbstractSeedEngine<SeedEngineResultType>> seedEngine) /*override*/
    {
        getBaseEngine()->setSeedEngine(seedEngine);
    }

    /**
     * \brief 乱数を生成
     * \tparam ResultType 乱数の型
     * \return 乱数
     */
    /*template <typename ResultType>*/
    virtual BaseEngine::BaseEngineResultType operator()(void) /*override*/
    {
        BaseEngine::BaseEngineResultType result = getBaseEngine()->operator()();
        return result;
    }

    /**
     * \brief 指定した回数だけ疑似乱数を生成し、内部状態を進める
     * \param skip 指定回数
     */
     virtual void discard(std::uint64_t skip) /*override*/
     {
         getBaseEngine()->discard(skip);
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
    /*template <typename ResultType>*/
    BaseEngine::BaseEngineResultType getMin(void) noexcept /*override*/
    {
        BaseEngine::BaseEngineResultType min = getBaseEngine()->getMin();
        return min;
    }

    /**
     * \brief 生成する値の最大値を取得
     * \return 最大値
     */
    //template <typename ResultType>
    BaseEngine::BaseEngineResultType getMax(void) noexcept /*override*/
    {
        BaseEngine::BaseEngineResultType max = getBaseEngine()->getMax();
        return max;
    }

private:
    template <typename SeedEngineResultType = BaseEngine::DefaultSeedEngineResultType>
    std::shared_ptr<AbstractRandomNumberEngine> createBaseEngine(const SeedEngineParameter<SeedEngineResultType>& seedParam)
    {
        BaseEngineFactory factory;
        return factory.create<SeedEngineResultType>(seedParam);
    }

    template <typename SeedEngineResultType = BaseEngine::DefaultSeedEngineResultType>
    std::shared_ptr<BaseEngineFactory::BaseEngine<SeedEngineResultType>> getBaseEngine(void) const
    {
        std::shared_ptr<BaseEngineFactory::BaseEngine<SeedEngineResultType>> engine = std::dynamic_pointer_cast<BaseEngineFactory::BaseEngine<SeedEngineResultType>>(m_baseEngine);
        return engine;
    }

private:
    /**
     * \brief 乱数ベースエンジン
     */
    std::shared_ptr<AbstractRandomNumberEngine> m_baseEngine;
};
} // namespace random_number_generator
