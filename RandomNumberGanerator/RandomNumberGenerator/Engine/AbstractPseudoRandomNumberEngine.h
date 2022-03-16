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
#include "AbstractBaseRandomNumberEngine.h"
#include "RandomNumberEngineID.h"

namespace random_number_generator
{
/**
 * \brief 抽象疑似乱数エンジン
 * \tparam EngineResultType_ 乱数エンジン生成結果の型
 * \tparam SeedEngine_ シードエンジンの型
 * \tparam SeedEngineResultType_ シードエンジン生成結果の型
 */
template <
    typename EngineResultType_,
    typename SeedEngine_,
    typename SeedEngineResultType_
>
class AbstractPseudoRandomNumberEngine : public AbstractBaseRandomNumberEngine<EngineResultType_>
{
public:
    /**
     * \brief シードエンジンの型
     */
    using SeedEngine = SeedEngine_;

    /**
     * \brief シードエンジン生成結果の型
     */
    using SeedEngineResultType = SeedEngineResultType_;
    // TODO SeedEngineのinvoke結果から推論可能？

public:
    /**
     * \brief シードエンジンを設定
     * \param seed シードエンジン
     */
    virtual void setSeedEngine(std::shared_ptr<SeedEngine> seed) = 0;

    /**
     * \brief 指定した回数だけ疑似乱数を生成し、内部状態を進める
     * \param skip 指定回数
     */
    virtual void discard(std::uint64_t skip) = 0;

protected:
    /**
     * \brief シードを取得
     * \return シード
     */
    virtual SeedEngineResultType getSeed(void) const = 0;
};
} // namespace random_number_generator
