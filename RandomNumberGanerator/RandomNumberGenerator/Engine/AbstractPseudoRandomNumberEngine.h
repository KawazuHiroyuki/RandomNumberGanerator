/*****************************************************************//**
 * \file   AbstractPseudoRandomNumberEngine.h
 * \brief  抽象疑似乱数エンジン
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <memory>
// My
#include "Seed/AbstractSeedEngine.h"
#include "AbstractRandomNumberEngine.h"

namespace random_number_generator
{
/**
 * \brief 抽象疑似乱数エンジン
 * \tparam EngineResultType_ 乱数エンジン生成結果の型
 * \tparam SeedEngine_ シードエンジンの型
 * \tparam Seed_ シードの型
 */
template <
    typename EngineResultType_,
    typename SeedEngine_,
    typename Seed_
>
class AbstractPseudoRandomNumberEngine : public AbstractRandomNumberEngine<EngineResultType_>
{
public:
    /**
     * \brief シードエンジンの型
     */
    using SeedEngine = SeedEngine_;

    /**
     * \brief シードの型
     */
    using Seed = Seed_;

public:
    /**
     * \brief シードエンジンを設定
     * \param seed シードエンジン
     */
    virtual void setSeedEngine(std::shared_ptr<SeedEngine> seed) = 0;

protected:
    /**
     * \brief シードを取得
     * \return シード
     */
    virtual Seed getSeed(void) const = 0;
};
} // namespace random_number_generator
