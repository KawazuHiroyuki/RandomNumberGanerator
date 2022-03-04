/*****************************************************************//**
 * \file   StdDefaultRandomEngine.h
 * \brief  非専門用途でデフォルト使用する擬似乱数生成器
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <random>
// My
#include "PrimaryPseudoRandomNumberEngine.h"
#include "RandomNumberEngineUtility.h"

namespace random_number_generator
{
/**
 * \brief 非専門用途でデフォルト使用する擬似乱数生成器
 * \note std::default_random_engine
 * \tparam Seed_ シードの型
 */
template <typename Seed_ = std::uint32_t>
class StdDefaultRandomEngine : public PrimaryPseudoRandomNumberEngine<BaseEngine<StdDefaultRandomEngine<Seed_>, Seed_>, EngineResultType<StdDefaultRandomEngine<Seed_>, Seed_>, Seed_>
{
private:
    using Base = PrimaryPseudoRandomNumberEngine<BaseEngine<StdDefaultRandomEngine<Seed_>, Seed_>, EngineResultType<StdDefaultRandomEngine<Seed_>, Seed_>, Seed_>;
    using Engine = BaseEngine<StdDefaultRandomEngine<Seed_>, Seed_>;

public:
    /**
     * \brief コンストラクタ
     * \param seed シードエンジン
     */
    StdDefaultRandomEngine(std::shared_ptr<AbstractSeedEngine<Seed_>> seed)
        : Base(RandomNumberEngineID::StdDefaultRandomEngine, Engine(seed->operator()()), seed)
    {
    }
};
} // namespace random_number_generator
