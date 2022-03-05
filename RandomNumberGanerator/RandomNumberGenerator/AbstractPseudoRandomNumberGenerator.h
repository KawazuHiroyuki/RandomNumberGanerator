/*****************************************************************//**
 * \file   AbstractPseudoRandomNumberGenerator.h
 * \brief  抽象疑似乱数生成器
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <memory>
// My
#include "Seed/AbstractSeedEngine.h"
#include "AbstractBaseRandomNumberGenerator.h"

namespace random_number_generator
{
/**
 * \brief 抽象疑似乱数生成器
 * \tparam ResultType_ 乱数の型
 * \tparam SeedType_ シードの型
 */
 //template <
 //    typename ResultType_,
 //    typename SeedType_
 //>
class AbstractPseudoRandomNumberGenerator : public AbstractBaseRandomNumberGenerator/*<ResultType_>*/
{
public:
    /**
     * \brief シードの型
     */
    //using SeedType = SeedType_;

private:
    /**
     * \brief シードエンジンの型
     */
    //using SeedEngine = AbstractSeedEngine<SeedType>;

public:
#if 0
    /**
     * \brief シードエンジンを設定
     * \tparam SeedType_ シードの型
     * \param seed シードエンジン
     */
    template <typename SeedType>
    void setSeedEngine(std::shared_ptr<AbstractSeedEngine<SeedType>> seedEngine) = 0;
#endif
};
} // namespace random_number_generator
