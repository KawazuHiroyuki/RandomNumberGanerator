/*****************************************************************//**
 * \file   StdRandomDevice.h
 * \brief  �\���s�\�ȗ���������
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <random>
// My
#include "RandomNumberEngineUtility.h"
#include "PrimaryTrueRandomNumberEngine.h"

namespace random_number_generator
{
/**
 * \brief �\���s�\�ȗ���������
 * \note std::random_device
 */
class StdRandomDevice : public PrimaryTrueRandomNumberEngine<BaseEngine<StdRandomDevice>, EngineResultType<StdRandomDevice>>
{

};
} // namespace random_number_generator
