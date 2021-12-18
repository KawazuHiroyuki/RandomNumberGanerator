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
template <typename T>
class StdRandomDeviceSeedGenerator : public SeedGenerator<T>
{
    using SeedGenerator<T>::Seed;

public:
    StdRandomDeviceSeedGenerator(void)
        : SeedGenerator<Seed>(SeedGeneratorParameter<Seed>{
            SeedGeneratorID::StdRandomDevice,
            []() { return std::random_device()(); }
            })
    { 
    }
};
} // namespace random_number_generator
