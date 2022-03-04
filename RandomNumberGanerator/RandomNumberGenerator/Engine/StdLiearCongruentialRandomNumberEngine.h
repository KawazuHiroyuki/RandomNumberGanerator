/*****************************************************************//**
 * \file   StdLiearCongruentialRandomNumberEngine.h
 * \brief  線形合同法 乱数生成器
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <random>
// My
#include "StdLiearCongruentialRandomNumberEngineParameter.h"
#include "PrimaryPseudoRandomNumberEngine.h"

namespace random_number_generator
{
/**
 * \brief 線形合同法 乱数生成器
 * \note std::linear_congruential_engine
 * \tparam EngineResultType_ エンジン生成結果の型
 */
template <typename EngineResultType_,
    EngineResultType_ A, EngineResultType_ C, EngineResultType_ M,
    typename Seed_
>
class StdLiearCongruentialRandomNumberEngine : public PrimaryPseudoRandomNumberEngine<std::linear_congruential_engine<EngineResultType_, A, C, M>, EngineResultType_, Seed_>
{
private:
    using Base = PrimaryPseudoRandomNumberEngine<std::linear_congruential_engine<EngineResultType_, A, C, M>, EngineResultType_, Seed_>;
    using Engine = Base::Engine;

    //static_assert(std::is_same<Engine::result_type, EngineResultType_>::value, "");

public:
    /**
     * \brief コンストラクタ
     * \param seed シードエンジン
     */
    StdLiearCongruentialRandomNumberEngine(std::shared_ptr<AbstractSeedEngine<Seed_>> seed)
        : Base(RandomNumberEngineID::StdLiearCongruential, Engine(seed->operator()()), seed)
    {
    }
};
} // namespace random_number_generator
