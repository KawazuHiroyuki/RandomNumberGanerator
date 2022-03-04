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
 * \tparam EngineResultType_ エンジン生成結果の型
 * \tparam Seed_ シードの型
 */
template <
    typename EngineResultType_,
    typename Seed_
>
class AbstractPseudoRandomNumberEngine : public AbstractRandomNumberEngine<EngineResultType_>
{
public:
#if 0
    /**
     * \brief シードを設定
     * \param seed シード
     */
    virtual void setSeed(Seed_ seed) override
    {
        m_engine.seed(seed);
    }
#endif



protected:
    /**
     * \brief シードを取得
     * \return シード
     */
    virtual Seed_ getSeed(void) const = 0;
};
} // namespace random_number_generator
