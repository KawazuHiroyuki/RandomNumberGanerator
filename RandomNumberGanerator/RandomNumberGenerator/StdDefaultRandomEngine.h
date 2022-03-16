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
 */
class StdDefaultRandomEngine : public AbstractPseudoRandomNumberGenerator<StdDefaultRandomEngineBaseEngineFactory>
{
private:
    /**
     * \brief 基底クラス
     */
    using Base = AbstractPseudoRandomNumberGenerator<StdDefaultRandomEngineBaseEngineFactory>;

    using DefaultSeedEngineResultType = StdDefaultRandomEngineBaseEngineFactory::BaseEngineTraits::DefaultSeedEngineResultType;

public:
    /**
     * \brief コンストラクタ
     * \tparam SeedEngineResultType シードエンジン生成結果の型
     * \param seedParam シードエンジンパラメータ
     */
    template <typename SeedEngineResultType = DefaultSeedEngineResultType>
    StdDefaultRandomEngine(const SeedEngineParameter<SeedEngineResultType>& seedParam = {})
        : Base(seedParam)
    {
    }
};
} // namespace random_number_generator
