/*****************************************************************//**
 * \file   RandomNumberGenerator.h
 * \brief  乱数生成器
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include "private/SeedGeneratorFactory.h"
#include "private/StdRandomDeviceSeedGenerator.h"

#include "private/StdDefaultRandomEngine.h"
#include "private/StdKnuthRandomNumberEngine.h"
#include "private/StdLiearCongruentialRandomNumberEngine.h"
#include "private/StdMersenneTwisterRandomNumberEngine.h"
#include "private/StdMinStdRand0RandomNumberEngine.h"
#include "private/StdMinStdRandRandomNumberEngine.h"
#include "private/StdMt199937_32BitRandomNumberEngine.h"
#include "private/StdMt199937_64BitRandomNumberEngine.h"
#include "private/StdRandomDevice.h"
#include "private/StdRanlux24RandomNumberEngine.h"
#include "private/StdRanlux48RandomNumberEngine.h"
#include "private/StdSubtractWithCarryRandomNumberEngine.h"

namespace random_number_generator
{
template <typename T>
class RandomNumberGenerator
{
public:
    RandomNumberGenerator(void)
    {



    }
};
} // namespace random_number_generator
