/*****************************************************************//**
 * \file   StdRandomDeviceSeedGenerator.h
 * \brief  �V�[�h�G���W�� - std::random_device
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <random>

#include "SeedEngine.h"

namespace random_number_generator
{
/**
 * \brief �V�[�h�G���W�� - std::random_device
 */
template <typename Seed_>
class StdRandomDeviceSeedEngine : public SeedEngine<Seed_>
{
    using SeedEngine<Seed_>::Seed;

    /**
     * \brief �G���W���̌^
     */
    using Engine = std::random_device;

public:
    /**
     * \brief �R���X�g���N�^
     */
    StdRandomDeviceSeedEngine(void)
        : SeedEngine<Seed>(SeedEngineParameter<Seed>{
            SeedEngineID::StdRandomDevice,
            []() { return Engine()(); }
            })
    {
    }
};
} // namespace random_number_generator
