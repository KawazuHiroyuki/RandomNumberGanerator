/*****************************************************************//**
 * \file   CurrentTimeSeedGenerator.h
 * \brief  シード生成器 - 現在時刻
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <ctime>

#include "SeedGenerator.h"

namespace random_number_generator
{
/**
 * \brief シード生成器 - 現在時刻
 */
template <typename T>
class CurrentTimeSeedGenerator : public SeedGenerator<T>
{
    using SeedGenerator<T>::Seed;

public:
    CurrentTimeSeedGenerator(void)
        : SeedGenerator<Seed>(SeedGeneratorParameter<Seed>{
            SeedGeneratorID::CurrentTime,
            []() { return static_cast<Seed>(std::time(nullptr)); }
            })
    {
    }
};
} // namespace random_number_generator
