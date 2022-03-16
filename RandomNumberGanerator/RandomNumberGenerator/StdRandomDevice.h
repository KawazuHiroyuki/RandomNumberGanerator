/*****************************************************************//**
 * \file   StdRandomDevice.h
 * \brief  予測不能な乱数生成器
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// My
#include "Engine/RandomNumberBaseEngineFactory.h"
#include "AbstractTrueRandomNumberGenerator.h"

namespace random_number_generator
{
/**
 * \brief 予測不能な乱数生成器
 * \note std::random_device
 */
class StdRandomDevice : public AbstractTrueRandomNumberGenerator<StdRandomDeviceBaseEngineFactory>
{
private:
    using Base = AbstractTrueRandomNumberGenerator<StdRandomDeviceBaseEngineFactory>;
    using BaseEngineFactory = StdRandomDeviceBaseEngineFactory;
    using BaseEngine = BaseEngineFactory::BaseEngine;
    //using DefaultSeedEngineResultType = BaseEngine::DefaultSeedEngineResultType;
    using BaseEngineResultType = BaseEngine::BaseEngineResultType;
    using Engine = BaseEngineFactory::Engine;

public:
    StdRandomDevice(void)
        : Base()
    {}

#if 0
    /**
     * \brief 乱数を生成
     * \tparam ResultType 乱数の型
     * \return 乱数
     */
    //template <typename ResultType>
    BaseEngineResultType operator()(void) /*override*/
    {
        BaseEngineResultType result = getBaseEngine()->operator()();
        return result;
    }

    /**
     * \brief 指定した回数だけ疑似乱数を生成し、内部状態を進める
     * \param skip 指定回数
     */
    //virtual void discard(std::uint64_t skip) override
    //{
    //}

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
    //template <typename ResultType>
    virtual BaseEngineResultType getMin(void) noexcept /*override*/
    {
        BaseEngineResultType min = getBaseEngine()->getMin();
        return min;
    }

    /**
     * \brief 生成する値の最大値を取得
     * \return 最大値
     */
    //template <typename ResultType>
    virtual BaseEngineResultType getMax(void) noexcept /*override*/
    {
        BaseEngineResultType max = getBaseEngine()->getMax();
        return max;
    }

private:
    std::shared_ptr<AbstractRandomNumberEngine> createBaseEngine(void) const
    {
        BaseEngineFactory factory;
        return factory.create();
    }

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
#endif
};
} // namespace random_number_generator
