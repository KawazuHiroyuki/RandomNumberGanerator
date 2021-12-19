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
template <typename Seed_>
class CurrentTimeSeedGenerator : public SeedGenerator<Seed_>
{
    using SeedGenerator<Seed_>::Seed;

public:
    /**
     * \brief �R���X�g���N�^
     */
    CurrentTimeSeedGenerator(void)
        : SeedGenerator<Seed>(SeedGeneratorParameter<Seed>{
            SeedGeneratorID::CurrentTime,
            []() { return static_cast<Seed>(std::time(nullptr)); }
            })
    {
    }
};
} // namespace random_number_generator
