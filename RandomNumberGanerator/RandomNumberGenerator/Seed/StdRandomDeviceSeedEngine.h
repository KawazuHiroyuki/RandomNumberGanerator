/*****************************************************************//**
 * \file   StdRandomDeviceSeedGenerator.h
 * \brief  �\���s�\�ȗ��������� �V�[�h�G���W��
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <random>
// My
#include "SeedEngine.h"

namespace random_number_generator
{
/**
 * \brief �\���s�\�ȗ���������
 * \note std::random_device
 * \tparam Seed_ �V�[�h�̌^
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
