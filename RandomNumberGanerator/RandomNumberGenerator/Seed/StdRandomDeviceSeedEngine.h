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
#include "PrimarySeedEngine.h"

namespace random_number_generator
{
/**
 * \brief �\���s�\�ȗ���������
 * \note std::random_device
 * \tparam Seed_ �V�[�h�̌^
 */
template <typename Seed_>
class StdRandomDeviceSeedEngine : public PrimarySeedEngine<Seed_>
{
    using PrimarySeedEngine<Seed_>::Seed;

    /**
     * \brief �G���W���̌^
     */
    using Engine = std::random_device;

public:
    /**
     * \brief �R���X�g���N�^
     */
    StdRandomDeviceSeedEngine(void)
        : PrimarySeedEngine<Seed>(SeedEngineParameter<Seed>{
            SeedEngineID::StdRandomDevice,
            []() { return Engine()(); }
            })
    {
    }
};
} // namespace random_number_generator
