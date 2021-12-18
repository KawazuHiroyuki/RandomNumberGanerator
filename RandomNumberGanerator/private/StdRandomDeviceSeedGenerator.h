/*****************************************************************//**
 * \file   StdRandomDeviceSeedGenerator.h
 * \brief  シード生成器 - std::random_device
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <random>

#include "SeedGenerator.h"

namespace random_number_generator
{
/**
 * \brief シード生成器 - std::random_device
 */
template <typename Type>
class StdRandomDeviceSeedGenerator : public SeedGenerator<Type>
{
public:
    StdRandomDeviceSeedGenerator(void)
        : SeedGenerator<Type>(SeedGeneratorParameter<Type>{
            SeedGeneratorID::StdRandomDevice,
            []() { return std::random_device()(); }
            })
    { 
    }
};
} // namespace random_number_generator
