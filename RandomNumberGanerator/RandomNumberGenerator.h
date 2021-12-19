/*****************************************************************//**
 * \file   RandomNumberGenerator.h
 * \brief  乱数生成器
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include "private/SeedEngineFactory.h"
#include "private/RandomNumberEngineFactory.h"



namespace random_number_generator
{
/**
 * \brief 乱数生成器
 * \tparam ResultType_ ResultType_
 * \tparam EngineResultType_ 乱数エンジンが生成する符号なし整数の型
 */
template <typename ResultType_>
class RandomNumberGenerator
{
public:
    /**
     * \brief 生成する乱数の型
     */
    using ResultType = ResultType_;

public:
    RandomNumberGenerator(void)
    {



    }

private:
    std::shared_ptr<RandomNumberEngine<ResultType>> m_engine;
};
} // namespace random_number_generator
