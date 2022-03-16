/*****************************************************************//**
 * \file   StdMinStdRand0RandomNumberEngine.h
 * \brief  最小標準MINSTD 疑似乱数生成器
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
 * \brief 最小標準MINSTD 乱数生成器
 * \note std::minstd_rand0
 */
class StdMinStdRand0RandomNumberEngine : public AbstractPseudoRandomNumberGenerator<StdMinStdRand0BaseEngineFactory>/* : public PrimaryPseudoRandomNumberEngine<BaseEngine<StdMinStdRand0RandomNumberEngine<Seed_>, Seed_>, BaseEngineResultType<StdMinStdRand0RandomNumberEngine<Seed_>, Seed_>, Seed_>*/
{
private:
    /**
     * \brief 基底クラス
     */
    using Base = AbstractPseudoRandomNumberGenerator<StdMinStdRand0BaseEngineFactory>;

    using DefaultSeedEngineResultType = StdMinStdRand0BaseEngineFactory::BaseEngineTraits::DefaultSeedEngineResultType;

public:
    /**
     * \brief コンストラクタ
     * \tparam SeedEngineResultType シードエンジン生成結果の型
     * \param seedParam シードエンジンパラメータ
     */
    template <typename SeedEngineResultType = DefaultSeedEngineResultType>
    StdMinStdRand0RandomNumberEngine(const SeedEngineParameter<SeedEngineResultType>& seedParam = {})
        : Base(seedParam)
    {
    }
};
} // namespace random_number_generator
