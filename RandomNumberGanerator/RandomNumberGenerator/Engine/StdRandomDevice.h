/*****************************************************************//**
 * \file   StdRandomDevice.h
 * \brief  �����G���W�� - �\���s�\�ȗ���������
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once
 // C++
#include <random>
// 
#include "PrimaryTrueRandomNumberEngine.h"
#include "RandomNumberEngineUtility.h"

namespace random_number_generator
{
/**
 * \brief �����G���W�� - �\���s�\�ȗ���������
 */
class StdRandomDevice : public PrimaryTrueRandomNumberEngine<BaseEngine<StdRandomDevice>, EngineResultType<StdRandomDevice>>
{

};

} // namespace random_number_generator