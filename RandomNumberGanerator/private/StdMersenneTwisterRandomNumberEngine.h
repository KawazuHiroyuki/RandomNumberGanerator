/*****************************************************************//**
 * \file   StdMersenneTwisterRandomNumberEngine.h
 * \brief  乱数エンジン - メルセンヌツイスター法
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <random>

#include "PseudoRandomNumberEngine.h"

namespace random_number_generator
{
/**
 * \brief 乱数エンジン - メルセンヌツイスター法
 * \tparam EngineResultType_ 生成する符号なし整数の型
 */
template <
    typename EngineResultType_,
    std::size_t W, std::size_t N, std::size_t M, std::size_t R,
    EngineResultType_ A, std::size_t U, EngineResultType_ D, std::size_t S,
    EngineResultType_ B, std::size_t T,
    EngineResultType_ C, std::size_t L, EngineResultType_ F,
    typename Seed_
>
class StdMersenneTwisterRandomNumberEngine : public PseudoRandomNumberEngine<std::mersenne_twister_engine<EngineResultType_, W, N, M, R, A, U, D, S, B, T, C, L, F>, EngineResultType_, Seed_>
{
private:
    using Base = PseudoRandomNumberEngine<std::mersenne_twister_engine<EngineResultType_, W, N, M, R, A, U, D, S, B, T, C, L, F>, EngineResultType_, Seed_>;
    using Engine = Base::Engine;

    //static_assert(std::is_same<Engine::result_type, EngineResultType_>::value, "");

public:
    /**
     * \brief コンストラクタ
     * \param seed シードエンジン
     */
    StdMersenneTwisterRandomNumberEngine(std::shared_ptr<SeedEngine<Seed_>> seed)
        : Base(RandomNumberEngineID::StdMersenneTwister, Engine(seed->operator()()), seed)
    {
    }
};
} // namespace random_number_generator
