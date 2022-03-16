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
     * \brief ベースエンジン
     */
    using BaseEngine = BaseEngine_;

    /**
     * \brief ベースエンジン生成結果の型
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
};
} // namespace random_number_generator
