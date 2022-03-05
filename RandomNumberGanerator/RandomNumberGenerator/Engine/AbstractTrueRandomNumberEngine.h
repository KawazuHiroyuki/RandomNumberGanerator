/*****************************************************************//**
 * \file   AbstractTrueRandomNumberEngine.h
 * \brief  抽象真性乱数エンジン
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// My
#include "AbstractBaseRandomNumberEngine.h"
#include "RandomNumberEngineID.h"

namespace random_number_generator
{
/**
 * \brief 抽象真性乱数エンジン
 * \tparam EngineResultType_ 乱数エンジン生成結果の型
 */
template <typename EngineResultType_>
class AbstractTrueRandomNumberEngine : public AbstractBaseRandomNumberEngine<EngineResultType_>
{
public:
    ///**
    // * \brief 指定した回数だけ疑似乱数を生成し、内部状態を進める
    // * \param skip 指定回数
    // */
    //void discard(std::uint64_t skip) = delete;
};
} // namespace random_number_generator
