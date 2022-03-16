/*****************************************************************//**
 * \file   StdMinStdRand0RandomNumberEngine.h
 * \brief  最小標準MINSTD 疑似乱数生成器
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include "Engine/RandomNumberBaseEngineFactory.h"
#include "AbstractPseudoRandomNumberGenerator.h"

namespace random_number_generator
{
/**
 * \brief 最小標準MINSTD 乱数生成器
 * \note std::minstd_rand0
 * \tparam Seed_ シードの型
 */
//template <typename Seed_ = std::uint32_t>
class StdMinStdRand0RandomNumberEngine : public AbstractPseudoRandomNumberGenerator<StdMinStdRand0BaseEngineFactory>/* : public PrimaryPseudoRandomNumberEngine<BaseEngine<StdMinStdRand0RandomNumberEngine<Seed_>, Seed_>, BaseEngineResultType<StdMinStdRand0RandomNumberEngine<Seed_>, Seed_>, Seed_>*/
{
private:
    using Base = AbstractPseudoRandomNumberGenerator<StdMinStdRand0BaseEngineFactory>;
    //using BaseEngineFactory = StdMinStdRand0BaseEngineFactory;
    //using BaseEngine = BaseEngineFactory::BaseEngine;
    using DefaultSeedEngineResultType = StdMinStdRand0BaseEngineFactory::BaseEngineTraits::DefaultSeedEngineResultType;
    //using BaseEngineResultType = BaseEngine::BaseEngineResultType;
    //template <typename SeedEngineResultType>
    //using Engine = BaseEngineFactory::Engine<SeedEngineResultType>;

public:
    /**
     * \brief コンストラクタ
     * \param seedParam シードエンジンパラメータ
     */
    template <typename SeedEngineResultType = DefaultSeedEngineResultType>
    StdMinStdRand0RandomNumberEngine(const SeedEngineParameter<SeedEngineResultType>& seedParam = {})
        : Base(seedParam)
        //: m_baseEngine(createBaseEngine<SeedEngineResultType>(seedParam))
    {
    }

#if 0
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
#endif
};
} // namespace random_number_generator
