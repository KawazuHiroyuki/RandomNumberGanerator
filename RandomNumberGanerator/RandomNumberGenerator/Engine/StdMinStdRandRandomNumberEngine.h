/*****************************************************************//**
 * \file   StdMinStdRandRandomNumberEngine.h
 * \brief  最小標準MINSTDのパラメータ改良版 乱数生成器
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
 * \brief 最小標準MINSTDのパラメータ改良版 乱数生成器
 * \note std::minstd_rand
 * \tparam Seed_ シードの型
 */
template <typename Seed_ = std::uint32_t>
class StdMinStdRandRandomNumberEngine : public PrimaryPseudoRandomNumberEngine<BaseEngine<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>, BaseEngineResultType<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>, Seed_>
{
private:
    using Base = PrimaryPseudoRandomNumberEngine<BaseEngine<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>, BaseEngineResultType<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>, Seed_>;
    using Engine = BaseEngine<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>;

public:
    /**
     * \brief コンストラクタ
     * \param seedParam シードエンジンパラメータ
     */
    StdMinStdRandRandomNumberEngine(const SeedEngineParameter<Seed_>& seedParam = {})
        : Base(RandomNumberEngineID::StdMinStdRand, seedParam)
    {
    }
};
} // namespace random_number_generator
