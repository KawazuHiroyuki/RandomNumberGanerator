/*****************************************************************//**
 * \file   StdKnuthRandomNumberEngine.h
 * \brief  KnuthのリオーダーアルゴリズムB 乱数生成器
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
 * \brief KnuthのリオーダーアルゴリズムB 乱数生成器
 * \note std::knuth_b
 * \tparam Seed_ シードの型
 */
template <typename Seed_ = std::uint32_t>
class StdKnuthRandomNumberEngine : public PrimaryPseudoRandomNumberEngine<BaseEngine<StdKnuthRandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdKnuthRandomNumberEngine<Seed_>, Seed_>, Seed_>
{
private:
    using Base = PrimaryPseudoRandomNumberEngine<BaseEngine<StdKnuthRandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdKnuthRandomNumberEngine<Seed_>, Seed_>, Seed_>;
    using Engine = BaseEngine<StdKnuthRandomNumberEngine<Seed_>, Seed_>;

public:
    /**
     * \brief コンストラクタ
     * \param seedParam シードエンジンパラメータ
     */
    StdKnuthRandomNumberEngine(const SeedEngineParameter<Seed_>& seedParam = {})
        : Base(RandomNumberEngineID::StdKnuth, seedParam)
    {
    }
};
} // namespace random_number_generator
