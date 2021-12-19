/*****************************************************************//**
 * \file   StdRandomDeviceSeedGenerator.h
 * \brief  �V�[�h������ - std::random_device
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
 * \brief �V�[�h������ - std::random_device
 */
template <typename Seed_>
class StdRandomDeviceSeedGenerator : public SeedGenerator<Seed_>
{
    using SeedGenerator<Seed_>::Seed;

    using Engine = std::random_device;

public:
    /**
     * \brief �R���X�g���N�^
     */
    StdRandomDeviceSeedGenerator(void)
        : SeedGenerator<Seed>(SeedGeneratorParameter<Seed>{
            SeedGeneratorID::StdRandomDevice,
            []() { return Engine()(); }
            })
    {
    }
};
} // namespace random_number_generator
