/*****************************************************************//**
 * \file   StdSubtractWithCarryRandomNumberEngine.h
 * \brief  キャリー付き減算法 乱数生成器
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
 * \brief キャリー付き減算法 乱数生成器
 * \note std::subtract_with_carry_engine
 * \tparam EngineResultType_ エンジン生成結果の型
 */
template <typename EngineResultType_,
    std::size_t W, std::size_t S, std::size_t R,
    typename Seed_
>
class StdSubtractWithCarryRandomNumberEngine : public PrimaryPseudoRandomNumberEngine<std::subtract_with_carry_engine<EngineResultType_, W, S, R>, EngineResultType_, Seed_>
{
private:
    using Base = PrimaryPseudoRandomNumberEngine<std::subtract_with_carry_engine<EngineResultType_, W, S, R>, EngineResultType_, Seed_>;
    using Engine = Base::Engine;

    //static_assert(std::is_same<Engine::result_type, Base::EngineResultType>::value, "");

public:
    /**
     * \brief コンストラクタ
     * \param seedParam シードエンジンパラメータ
     */
    StdSubtractWithCarryRandomNumberEngine(const SeedEngineParameter<Seed_>& seedParam = {})
        : Base(RandomNumberEngineID::StdSubtractWithCarry, seedParam)
    {
    }
};
} // namespace random_number_generator
