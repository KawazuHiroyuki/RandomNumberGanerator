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

namespace random_number_generator
{
/**
 * \brief 抽象真性乱数エンジン
 * \tparam EngineResultType_ 乱数エンジン生成結果の型
 */
template <typename EngineResultType_>
class AbstractTrueRandomNumberEngine : public AbstractBaseRandomNumberEngine<EngineResultType_>
{
};
} // namespace random_number_generator
