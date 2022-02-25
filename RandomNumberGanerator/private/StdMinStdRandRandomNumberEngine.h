/*****************************************************************//**
 * \file   StdMinStdRandRandomNumberEngine.h
 * \brief  乱数エンジン - 最小標準MINSTDのパラメータ改良版
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <random>

#include "PrimaryPseudoRandomNumberEngine.h"
#include "RandomNumberEngineUtility.h"

namespace random_number_generator
{
/**
 * \brief 乱数エンジン - 最小標準MINSTDのパラメータ改良版
 * \tparam Seed_ シードの型
 */
template <typename Seed_ = std::uint32_t>
class StdMinStdRandRandomNumberEngine : public PrimaryPseudoRandomNumberEngine<BaseEngine<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>, Seed_>
{
private:
    using Base = PrimaryPseudoRandomNumberEngine<BaseEngine<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>, EngineResultType<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>, Seed_>;
    using Engine = BaseEngine<StdMinStdRandRandomNumberEngine<Seed_>, Seed_>;

public:
    /**
     * \brief コンストラクタ
     * \param seed シードエンジン
     */
    StdMinStdRandRandomNumberEngine(std::shared_ptr<SeedEngine<Seed_>> seed)
        : Base(RandomNumberEngineID::StdMinStdRand, Engine(seed->operator()()), seed)
    {
    }
};
} // namespace random_number_generator
