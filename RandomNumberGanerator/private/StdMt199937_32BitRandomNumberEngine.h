/*****************************************************************//**
 * \file   StdMt199937_32BitRandomNumberEngine.h
 * \brief  乱数エンジン - メルセンヌツイスターの32ビット版
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <random>

#include "RandomNumberEngine.h"
#include "RandomNumberEngineUtility.h"

namespace random_number_generator
{
/**
 * \brief 乱数エンジン - メルセンヌツイスターの32ビット版
 * \tparam Seed_ シードの型
 */
template <typename Seed_ = std::uint32_t>
class StdMt199937_32BitRandomNumberEngine : public RandomNumberEngine<BaseEngine<StdMt199937_32BitRandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdMt199937_32BitRandomNumberEngine<Seed_>, Seed_>, Seed_>
{
private:
    using Base = RandomNumberEngine<BaseEngine<StdMt199937_32BitRandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdMt199937_32BitRandomNumberEngine<Seed_>, Seed_>, Seed_>;
    using Engine = BaseEngine<StdMt199937_32BitRandomNumberEngine<Seed_>, Seed_>;

public:
    /**
     * \brief コンストラクタ
     * \param seed シードエンジン
     */
    StdMt199937_32BitRandomNumberEngine(std::shared_ptr<SeedEngine<Seed_>> seed)
        : Base(RandomNumberEngineID::StdMt199937_32Bit, Engine(seed->operator()()), seed)
    {
    }
};
} // namespace random_number_generator
