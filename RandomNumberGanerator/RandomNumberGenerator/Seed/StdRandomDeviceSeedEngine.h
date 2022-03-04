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
 * \brief �\���s�\�ȗ��������� �V�[�h�G���W��
 * \note std::random_device
 * \tparam Seed_ �V�[�h�̌^
 */
template <typename Seed_>
class StdRandomDeviceSeedEngine : public PrimarySeedEngine<Seed_>
{
public:
    /**
     * \brief �R���X�g���N�^
     */
    StdRandomDeviceSeedEngine(void)
        : PrimarySeedEngine<Seed_>(SeedEngineParameter<Seed_>{SeedEngineID::StdRandomDevice, createEngine()})
    {
    }

private:
    /**
     * \brief �V�[�h�G���W������
     * \return �V�[�h�G���W��
     */
    SeedEngineParameter<Seed_>::Engine<Seed_> createEngine(void) const
    {
        return []() { return static_cast<Seed_>(std::random_device()()); };
    }
};
} // namespace random_number_generator
