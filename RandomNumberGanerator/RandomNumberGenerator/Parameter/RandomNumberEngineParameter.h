/*****************************************************************//**
 * \file   RandomNumberEngineParameter.h
 * \brief  乱数エンジンパラメータ
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include "ID/RandomNumberEngineID.h"

namespace random_number_generator
{
/**
 * \brief 乱数エンジンパラメータ
 */
struct RandomNumberEngineParameter
{
    // TODO ↓復帰
    // using EngineResultType = EngineResultType_;

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
} // namespace random_number_generator
