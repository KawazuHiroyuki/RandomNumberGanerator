/*****************************************************************//**
 * \file   AbstractBaseEngineTraits.h
 * \brief  抽象乱数ベースエンジン特性
 *
 * \author japan
 * \date   March 2022
 *********************************************************************/

#pragma once

// My
#include "RandomNumberEngineID.h"

namespace random_number_generator
{
/**
 * \brief 抽象乱数ベースエンジン特性
 * \tparam BaseEngine_ ベース乱数エンジンの型
 * \tparam ID_ 乱数エンジンID
 */
template <
    typename BaseEngine_,
    RandomNumberEngineID ID_
>
struct AbstractBaseEngineTraits
{
    /**
     * \brief 乱数ベースエンジン
     */
    using BaseEngine = BaseEngine_;

    /**
     * \brief 乱数ベースエンジン生成結果の型
     */
    using BaseEngineResultType = typename BaseEngine::result_type;

    /**
     * \brief デフォルトのシードエンジン生成結果の型
     */
    using DefaultSeedEngineResultType = typename BaseEngine::result_type;

    /**
     * \brief 乱数エンジンID
     */
    static constexpr RandomNumberEngineID ID = ID_;

    /**
     * \brief 真性乱数エンジンフラグ
     */
    static constexpr bool IS_TRUE_RANDOM_NUMBER_ENGINE = isTrueRandomNumberEngine(ID);

    /**
     * \brief 疑似乱数エンジンフラグ
     */
    static constexpr bool IS_PSEUDO_RANDOM_NUMBER_ENGINE = isPseudoRandomNumberEngine(ID);
};
} // namespace random_number_generator
