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
#include "Engine/PrimaryPseudoRandomNumberEngine.h"
#include "AbstractBaseRandomNumberGenerator.h"

namespace random_number_generator
{
/**
 * \brief 抽象疑似乱数生成器
 * \tparam BaseEngineFactory_ 乱数ベースエンジンファクトリ
 */
template <typename BaseEngineFactory_>
class AbstractPseudoRandomNumberGenerator : public AbstractBaseRandomNumberGenerator
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
     * \brief デフォルトのシードエンジン生成結果の型
     */
    using DefaultSeedEngineResultType = typename BaseEngineTraits::DefaultSeedEngineResultType;

    /**
     * \brief ベースエンジン生成結果の型
     */
    using BaseEngineResultType = typename BaseEngineTraits::BaseEngineResultType;

    /**
     * \brief 乱数エンジン  TODO factoryと共用できないか？
     * \tparam SeedEngineResultType シードエンジン生成結果の型
     */
    template <typename SeedEngineResultType>
    using Engine = PrimaryPseudoRandomNumberEngine<BaseEngine, BaseEngineResultType, SeedEngineResultType>;

public:
    /**
     * \brief コンストラクタ
     * \tparam SeedEngineResultType シードエンジン生成結果の型
     * \param seedParam シードエンジンパラメータ
     */
    template <typename SeedEngineResultType = DefaultSeedEngineResultType>
    AbstractPseudoRandomNumberGenerator(const SeedEngineParameter<SeedEngineResultType>& seedParam = {})
        : m_baseEngine(createBaseEngine<SeedEngineResultType>(seedParam))
    {
    }

    /**
     * \brief シードエンジンを設定
     * \tparam SeedEngineResultType シードエンジン生成結果の型
     * \param seed シードエンジン
     */
    template <typename SeedEngineResultType = DefaultSeedEngineResultType>
    void setSeedEngine(std::shared_ptr<AbstractSeedEngine<SeedEngineResultType>> seedEngine) /*override*/
    {
        getBaseEngine()->setSeedEngine(seedEngine);
    }

    /**
     * \brief 乱数を生成
     * \return 乱数
     */
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
    BaseEngineResultType getMin(void) const noexcept /*override*/
    {
        BaseEngineResultType min = getBaseEngine()->getMin();
        return min;
    }

    /**
     * \brief 生成する値の最大値を取得
     * \return 最大値
     */
    BaseEngineResultType getMax(void) const noexcept /*override*/
    {
        BaseEngineResultType max = getBaseEngine()->getMax();
        return max;
    }

private:
    /**
     * \brief 乱数ベースエンジンを生成
     * \tparam SeedEngineResultType シードエンジン生成結果の型
     * \param seedParam シードエンジンパラメータ
     * \return 乱数ベースエンジン
     */
    template <typename SeedEngineResultType = DefaultSeedEngineResultType>
    std::shared_ptr<AbstractRandomNumberEngine> createBaseEngine(const SeedEngineParameter<SeedEngineResultType>& seedParam)
    {
        BaseEngineFactory factory;
        return factory.create<SeedEngineResultType>(seedParam);
    }

    /**
     * \brief 乱数ベースエンジンを取得
     * \return 乱数ベースエンジン
     */
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
};
} // namespace random_number_generator
