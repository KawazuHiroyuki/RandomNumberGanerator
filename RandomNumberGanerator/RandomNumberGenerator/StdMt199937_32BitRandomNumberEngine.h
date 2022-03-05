/*****************************************************************//**
 * \file   StdMt199937_32BitRandomNumberEngine.h
 * \brief  メルセンヌツイスターの32ビット版 乱数生成器
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once
#if 0
// C++
#include <random>
// My
#include "PrimaryPseudoRandomNumberEngine.h"
#include "RandomNumberBaseEngine.h"

namespace random_number_generator
{
/**
 * \brief メルセンヌツイスターの32ビット版 乱数生成器
 * \note std::mt19937
 * \tparam Seed_ シードの型
 */
template <typename Seed_ = std::uint32_t>
class StdMt199937_32BitRandomNumberEngine : public PrimaryPseudoRandomNumberEngine<BaseEngine<StdMt199937_32BitRandomNumberEngine<Seed_>, Seed_>, BaseEngineResultType<StdMt199937_32BitRandomNumberEngine<Seed_>, Seed_>, Seed_>
{
private:
    using Base = PrimaryPseudoRandomNumberEngine<BaseEngine<StdMt199937_32BitRandomNumberEngine<Seed_>, Seed_>, BaseEngineResultType<StdMt199937_32BitRandomNumberEngine<Seed_>, Seed_>, Seed_>;
    using Engine = BaseEngine<StdMt199937_32BitRandomNumberEngine<Seed_>, Seed_>;

public:
    /**
     * \brief コンストラクタ
     * \param seedParam シードエンジンパラメータ
     */
    StdMt199937_32BitRandomNumberEngine(const SeedEngineParameter<Seed_>& seedParam = {})
        : Base(RandomNumberEngineID::StdMt199937_32Bit, seedParam)
    {
    }
};
} // namespace random_number_generator
#endif