/*****************************************************************//**
 * \file   RandomNumberEngineParameter.h
 * \brief  乱数エンジンパラメータ
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include "RandomNumberEngineID.h"

namespace random_number_generator
{
/**
 * \brief 乱数エンジンパラメータ
 */
template <typename ResultType_, typename EngineResultType_>
struct RandomNumberEngineParameter
{
    /**
     * \brief 生成する乱数の型
     */
    using ResultType = ResultType_;

    /**
     * \brief 乱数エンジンが生成する乱数の型
     */
    using EngineResultType = EngineResultType_;

    /**
     * \brief コンストラクタ
     * \param id_ 乱数エンジンID
     */
    RandomNumberEngineParameter(RandomNumberEngineID id_ = DEFAULT_RANDOM_NUMBER_ENGINE_ID)
        : id(id_)
    {
    }

    /**
     * \brief 乱数エンジンID
     */
    RandomNumberEngineID id = DEFAULT_RANDOM_NUMBER_ENGINE_ID;
};

template <typename ResultType_, typename EngineResultType_>
std::shared_ptr<RandomNumberEngineParameter<ResultType_, EngineResultType_>> 
inline makeRandomNumberEngineParameter(RandomNumberEngineID id = DEFAULT_RANDOM_NUMBER_ENGINE_ID)
{
    return std::make_shared<RandomNumberEngineParameter<ResultType_, EngineResultType_>>(id);
}

} // namespace random_number_generator
