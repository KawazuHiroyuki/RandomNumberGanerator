/*****************************************************************//**
 * \file   StdRanlux48RandomNumberEngine.h
 * \brief  RANLUX法のレベル4 乱数生成器
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <random>
// My
#include "RandomNumberEngineUtility.h"
#include "PrimaryPseudoRandomNumberEngine.h"

namespace random_number_generator
{
/**
 * \brief RANLUX法のレベル4 乱数生成器
 * \note std::ranlux48
 * \tparam Seed_ シードの型
 */
template <typename Seed_ = std::uint32_t>
class StdRanlux48RandomNumberEngine : public PrimaryPseudoRandomNumberEngine<BaseEngine<StdRanlux48RandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdRanlux48RandomNumberEngine<Seed_>, Seed_>, Seed_>
{
private:
    using Base = PrimaryPseudoRandomNumberEngine<BaseEngine<StdRanlux48RandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdRanlux48RandomNumberEngine<Seed_>, Seed_>, Seed_>;
    using Engine = BaseEngine<StdRanlux48RandomNumberEngine<Seed_>, Seed_>;

public:
    /**
     * \brief コンストラクタ
     * \param seed シードエンジン
     */
    StdRanlux48RandomNumberEngine(std::shared_ptr<PrimarySeedEngine<Seed_>> seed)
        : Base(RandomNumberEngineID::StdRanlux48, Engine(seed->operator()()), seed)
    {
    }
};
} // namespace random_number_generator
