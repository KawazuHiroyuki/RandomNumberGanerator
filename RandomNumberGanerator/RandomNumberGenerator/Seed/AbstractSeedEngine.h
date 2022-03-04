/*****************************************************************//**
 * \file   AbstractSeedEngine.h
 * \brief  抽象シードエンジン
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// My
#include "Parameter/SeedEngineParameter.h"

namespace random_number_generator
{
/**
 * \brief 抽象シードエンジン
 * \tparam Seed_ シードの型
 */
template <typename Seed_>
class AbstractSeedEngine
{
public:
    /**
     * \brief シードの型
     */
    using Seed = Seed_;

public:
    /**
     * \brief シードを生成
     * \return シード
     */
    virtual Seed operator()(void) = 0;

    /**
     * \brief シードエンジンパラメータを取得
     * \return シードエンジンパラメータ
     */
    virtual SeedEngineParameter<Seed> getParam(void) const = 0;
};
} // namespace random_number_generator
