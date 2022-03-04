/*****************************************************************//**
 * \file   StdRandomDevice.h
 * \brief  予測不能な乱数生成器
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <random>
// My
#include "RandomNumberBaseEngine.h"
#include "PrimaryTrueRandomNumberEngine.h"

namespace random_number_generator
{
/**
 * \brief 予測不能な乱数生成器
 * \note std::random_device
 */
class StdRandomDevice : public PrimaryTrueRandomNumberEngine<BaseEngine<StdRandomDevice>, EngineResultType<StdRandomDevice>>
{

};
} // namespace random_number_generator
