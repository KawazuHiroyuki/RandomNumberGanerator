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
template <typename Type>
class CurrentTimeSeedGenerator : public SeedGenerator<Type>
{
public:
    CurrentTimeSeedGenerator(void)
        : SeedGenerator<Type>(SeedGeneratorParameter<Type>{
            SeedGeneratorID::CurrentTime,
            []() { return static_cast<Type>(std::time(nullptr)); }
            })
    {
    }
};
} // namespace random_number_generator
