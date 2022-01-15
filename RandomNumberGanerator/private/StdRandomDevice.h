/*****************************************************************//**
 * \file   StdRandomDevice.h
 * \brief  乱数エンジン - 予測不能な乱数生成器
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once
 // C++
#include <random>
// 
#include "TrueRandomNumberEngine.h"
#include "RandomNumberEngineUtility.h"

namespace random_number_generator
{
/**
 * \brief 乱数エンジン - 予測不能な乱数生成器
 */
class StdRandomDevice : public TrueRandomNumberEngine<BaseEngine<StdRandomDevice>, EngineResultType<StdRandomDevice>>
{

};

} // namespace random_number_generator
