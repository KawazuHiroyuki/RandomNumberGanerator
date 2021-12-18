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

namespace random_number_generator
{
template <typename Type>
class RandomNumberGenerator
{
public:
    RandomNumberGenerator(void)
    {
        SeedGeneratorFactory::create(SeedGeneratorParameter<Type>{ SeedGeneratorID::StdRandomDevice });
        SeedGeneratorFactory::create(SeedGeneratorParameter<Type>{ SeedGeneratorID::CurrentTime });
        SeedGeneratorFactory::create(SeedGeneratorParameter<Type>{ SeedGeneratorID::Custom, []() { return 0;  } });
        StdRandomDeviceSeedGenerator<Type>();
    }
};
} // namespace random_number_generator
