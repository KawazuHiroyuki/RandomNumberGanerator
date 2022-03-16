/*****************************************************************//**
 * \file   AbstractPseudoRandomNumberGenerator.h
 * \brief  抽象疑似乱数生成器
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <memory>
// My
#include "Seed/AbstractSeedEngine.h"
#include "Seed//SeedEngineParameter.h"
//#include "Engine/AbstractRandomNumberEngine.h"
#include "Engine/PrimaryPseudoRandomNumberEngine.h"
#include "AbstractBaseRandomNumberGenerator.h"

namespace random_number_generator
{
/**
 * \brief 抽象疑似乱数生成器
 * \tparam ResultType_ 乱数の型
 * \tparam SeedType_ シードの型
 */
 //template <
 //    typename ResultType_,
 //    typename SeedType_
 //>
template <typename BaseEngineFactory_>
class AbstractPseudoRandomNumberGenerator : public AbstractBaseRandomNumberGenerator/*<ResultType_>*/
{
private:
    using BaseEngineFactory = BaseEngineFactory_;
    using BaseEngine = typename BaseEngineFactory::BaseEngine;
    using DefaultSeedEngineResultType = typename BaseEngine::DefaultSeedEngineResultType;
    using BaseEngineResultType = typename BaseEngine::BaseEngineResultType;
    //template <typename SeedEngineResultType>
    //using Engine = typename BaseEngineFactory::Engine<SeedEngineResultType>;

    template <typename SeedEngineResultType>
    using Engine = PrimaryPseudoRandomNumberEngine<typename BaseEngine::BaseEngine, BaseEngineResultType, SeedEngineResultType>;

public:
    /**
     * \brief コンストラクタ
     * \param seedParam シードエンジンパラメータ
     */
    template <typename SeedEngineResultType = DefaultSeedEngineResultType>
    AbstractPseudoRandomNumberGenerator(const SeedEngineParameter<SeedEngineResultType>& seedParam = {})
        : m_baseEngine(createBaseEngine<SeedEngineResultType>(seedParam))
    {
    }

    /**
     * \brief シードエンジンを設定
     * \tparam SeedType_ シードの型
     * \param seed シードエンジン
     */
    template <typename SeedEngineResultType = DefaultSeedEngineResultType>
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
    virtual BaseEngineResultType operator()(void) /*override*/
    {
        BaseEngineResultType result = getBaseEngine()->operator()();
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
    BaseEngineResultType getMin(void) noexcept /*override*/
    {
        BaseEngineResultType min = getBaseEngine()->getMin();
        return min;
    }

    /**
     * \brief 生成する値の最大値を取得
     * \return 最大値
     */
     //template <typename ResultType>
    BaseEngineResultType getMax(void) noexcept /*override*/
    {
        BaseEngineResultType max = getBaseEngine()->getMax();
        return max;
    }

private:
    template <typename SeedEngineResultType = DefaultSeedEngineResultType>
    std::shared_ptr<AbstractRandomNumberEngine> createBaseEngine(const SeedEngineParameter<SeedEngineResultType>& seedParam)
    {
        BaseEngineFactory factory;
        return factory.create<SeedEngineResultType>(seedParam);
    }

    template <typename SeedEngineResultType = DefaultSeedEngineResultType>
    std::shared_ptr<Engine<SeedEngineResultType>> getBaseEngine(void) const
    {
        std::shared_ptr<Engine<SeedEngineResultType>> engine = std::dynamic_pointer_cast<Engine<SeedEngineResultType>>(m_baseEngine);
        return engine;
    }

private:
    /**
     * \brief 乱数ベースエンジン
     */
    std::shared_ptr<AbstractRandomNumberEngine> m_baseEngine;

public:
    /**
     * \brief シードの型
     */
    //using SeedType = SeedType_;

private:
    /**
     * \brief シードエンジンの型
     */
    //using SeedEngine = AbstractSeedEngine<SeedType>;

public:
#if 0
    /**
     * \brief シードエンジンを設定
     * \tparam SeedType_ シードの型
     * \param seed シードエンジン
     */
    template <typename SeedType>
    void setSeedEngine(std::shared_ptr<AbstractSeedEngine<SeedType>> seedEngine) = 0;
#endif
};
} // namespace random_number_generator
