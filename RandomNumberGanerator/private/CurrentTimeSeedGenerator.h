/*****************************************************************//**
 * \file   CurrentTimeSeedGenerator.h
 * \brief  �V�[�h������ - ���ݎ���
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
 * \brief �V�[�h������ - ���ݎ���
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
