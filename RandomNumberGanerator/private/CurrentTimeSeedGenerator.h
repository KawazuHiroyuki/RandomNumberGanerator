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
