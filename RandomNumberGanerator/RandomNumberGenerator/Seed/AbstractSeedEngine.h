/*****************************************************************//**
 * \file   AbstractSeedEngine.h
 * \brief  抽象シードエンジン
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// My
#include "SeedEngineParameter.h"

namespace random_number_generator
{
/**
 * \brief 抽象シードエンジン
 * \tparam SeedEngineResultType_ シードエンジン生成結果の型
 */
template <typename SeedEngineResultType_>
class AbstractSeedEngine
{
public:
    /**
     * \brief シードエンジン生成結果の型
     */
    using SeedEngineResultType = SeedEngineResultType_;

    /**
     * \brief ードエンジンパラメータの型
     */
    using SeedEngineParameter = SeedEngineParameter<SeedEngineResultType>;

public:
    /**
     * \brief シードを生成
     * \return シード
     */
    virtual SeedEngineResultType operator()(void) = 0;

    /**
     * \brief シードエンジンパラメータを取得
     * \return シードエンジンパラメータ
     */
    virtual SeedEngineParameter getParam(void) const = 0;
};
} // namespace random_number_generator
