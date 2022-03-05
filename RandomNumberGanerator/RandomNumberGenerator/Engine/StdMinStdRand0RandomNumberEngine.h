/*****************************************************************//**
 * \file   StdMinStdRand0RandomNumberEngine.h
 * \brief  最小標準MINSTD 乱数生成器
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
 * \brief 最小標準MINSTD 乱数生成器
 * \note std::minstd_rand0
 * \tparam Seed_ シードの型
 */
template <typename Seed_ = std::uint32_t>
class StdMinStdRand0RandomNumberEngine : public PrimaryPseudoRandomNumberEngine<BaseEngine<StdMinStdRand0RandomNumberEngine<Seed_>, Seed_>, BaseEngineResultType<StdMinStdRand0RandomNumberEngine<Seed_>, Seed_>, Seed_>
{
private:
    using Base = PrimaryPseudoRandomNumberEngine<BaseEngine<StdMinStdRand0RandomNumberEngine<Seed_>, Seed_>, BaseEngineResultType<StdMinStdRand0RandomNumberEngine<Seed_>, Seed_>, Seed_>;
    using Engine = BaseEngine<StdMinStdRand0RandomNumberEngine<Seed_>, Seed_>;

public:
    /**
     * \brief コンストラクタ
     * \param seedParam シードエンジンパラメータ
     */
    StdMinStdRand0RandomNumberEngine(const SeedEngineParameter<Seed_>& seedParam = {})
        : Base(RandomNumberEngineID::StdMinStdRand0, seedParam)
    {
    }
};
} // namespace random_number_generator
