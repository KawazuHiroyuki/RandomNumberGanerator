/*****************************************************************//**
 * \file   StdRanlux24RandomNumberEngine.h
 * \brief  RANLUX法のレベル3 乱数生成器
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <random>
// My
#include "PrimaryPseudoRandomNumberEngine.h"
#include "RandomNumberBaseEngine.h"

namespace random_number_generator
{
/**
 * \brief RANLUX法のレベル3 乱数生成器
 * \note std::ranlux24
 * \tparam Seed_ シードの型
 */
template <typename Seed_ = std::uint32_t>
class StdRanlux24RandomNumberEngine : public PrimaryPseudoRandomNumberEngine<BaseEngine<StdRanlux24RandomNumberEngine<Seed_>, Seed_>, BaseEngineResultType<StdRanlux24RandomNumberEngine<Seed_>, Seed_>, Seed_>
{
private:
    using Base = PrimaryPseudoRandomNumberEngine<BaseEngine<StdRanlux24RandomNumberEngine<Seed_>, Seed_>, BaseEngineResultType<StdRanlux24RandomNumberEngine<Seed_>, Seed_>, Seed_>;
    using Engine = BaseEngine<StdRanlux24RandomNumberEngine<Seed_>, Seed_>;

public:
    /**
     * \brief コンストラクタ
     * \param seedParam シードエンジンパラメータ
     */
    StdRanlux24RandomNumberEngine(const SeedEngineParameter<Seed_>& seedParam = {})
        : Base(RandomNumberEngineID::StdRanlux24, seedParam)
    {
    }
};
} // namespace random_number_generator
