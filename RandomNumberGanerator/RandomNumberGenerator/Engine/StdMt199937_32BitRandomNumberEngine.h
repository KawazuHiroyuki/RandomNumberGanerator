/*****************************************************************//**
 * \file   StdMt199937_32BitRandomNumberEngine.h
 * \brief  メルセンヌツイスターの32ビット版 乱数生成器
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <random>
// My
#include "RandomNumberBaseEngine.h"
#include "PrimaryPseudoRandomNumberEngine.h"

namespace random_number_generator
{
/**
 * \brief メルセンヌツイスターの32ビット版 乱数生成器
 * \note std::mt19937
 * \tparam Seed_ シードの型
 */
template <typename Seed_ = std::uint32_t>
class StdMt199937_32BitRandomNumberEngine : public PrimaryPseudoRandomNumberEngine<BaseEngine<StdMt199937_32BitRandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdMt199937_32BitRandomNumberEngine<Seed_>, Seed_>, Seed_>
{
private:
    using Base = PrimaryPseudoRandomNumberEngine<BaseEngine<StdMt199937_32BitRandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdMt199937_32BitRandomNumberEngine<Seed_>, Seed_>, Seed_>;
    using Engine = BaseEngine<StdMt199937_32BitRandomNumberEngine<Seed_>, Seed_>;

public:
    /**
     * \brief コンストラクタ
     * \param seed シードエンジン
     */
    StdMt199937_32BitRandomNumberEngine(std::shared_ptr<AbstractSeedEngine<Seed_>> seed)
        : Base(RandomNumberEngineID::StdMt199937_32Bit, Engine(seed->operator()()), seed)
    {
    }
};
} // namespace random_number_generator
