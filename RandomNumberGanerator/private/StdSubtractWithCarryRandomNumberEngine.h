/*****************************************************************//**
 * \file   StdSubtractWithCarryRandomNumberEngine.h
 * \brief  乱数エンジン - キャリー付き減算法
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <random>

#include "PseudoRandomNumberEngine.h"
#include "RandomNumberEngineUtility.h"

namespace random_number_generator
{
/**
 * \brief 乱数エンジン - キャリー付き減算法
 * \tparam EngineResultType_ 生成する符号なし整数の型
 */
template <typename EngineResultType_,
    std::size_t W, std::size_t S, std::size_t R,
    typename Seed_
>
class StdSubtractWithCarryRandomNumberEngine : public PseudoRandomNumberEngine<std::subtract_with_carry_engine<EngineResultType_, W, S, R>, EngineResultType_, Seed_>
{
private:
    using Base = PseudoRandomNumberEngine<std::subtract_with_carry_engine<EngineResultType_, W, S, R>, EngineResultType_, Seed_>;
    using Engine = Base::Engine;

    //static_assert(std::is_same<Engine::result_type, Base::EngineResultType>::value, "");

public:
    /**
     * \brief コンストラクタ
     * \param seed シードエンジン
     */
    StdSubtractWithCarryRandomNumberEngine(std::shared_ptr<SeedEngine<Seed_>> seed)
        : Base(RandomNumberEngineID::StdSubtractWithCarry, Engine(seed->operator()()), seed)
    {
    }
};
} // namespace random_number_generator
