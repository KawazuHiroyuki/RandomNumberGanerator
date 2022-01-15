/*****************************************************************//**
 * \file   StdLiearCongruentialRandomNumberEngine.h
 * \brief  乱数エンジン - 線形合同法
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <random>

#include "RandomNumberEngine.h"
#include "../StdLiearCongruentialRandomNumberEngineParameter.h"

namespace random_number_generator
{
/**
 * \brief 乱数エンジン - 線形合同法
 * \tparam EngineResultType_ 生成する符号なし整数の型
 */
template <typename EngineResultType_,
    EngineResultType_ A, EngineResultType_ C, EngineResultType_ M,
    typename Seed_
>
class StdLiearCongruentialRandomNumberEngine : public RandomNumberEngine<std::linear_congruential_engine<EngineResultType_, A, C, M>, EngineResultType_, Seed_>
{
private:
    using Base = RandomNumberEngine<std::linear_congruential_engine<EngineResultType_, A, C, M>, EngineResultType_, Seed_>;
    using Engine = Base::Engine;

    //static_assert(std::is_same<Engine::result_type, EngineResultType_>::value, "");

public:
    /**
     * \brief コンストラクタ
     * \param seed シードエンジン
     */
    StdLiearCongruentialRandomNumberEngine(std::shared_ptr<SeedEngine<Seed_>> seed)
        : Base(RandomNumberEngineID::StdLiearCongruential, Engine(seed->operator()()), seed)
    {
    }
};
} // namespace random_number_generator
