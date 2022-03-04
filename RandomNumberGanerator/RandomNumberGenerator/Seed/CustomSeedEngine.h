/*****************************************************************//**
 * \file   CustomSeedEngine.h
 * \brief  �J�X�^�� �V�[�h�G���W��
 * 
 * \author japan
 * \date   March 2022
 *********************************************************************/

#pragma once

// My
#include "PrimarySeedEngine.h"

namespace random_number_generator
{
/**
 * \brief �J�X�^�� �V�[�h�G���W��
 * \tparam Seed_ �V�[�h�̌^
 */
template <typename Seed_>
class CustomSeedEngine : public PrimarySeedEngine<Seed_>
{
public:
    /**
     * \brief �R���X�g���N�^
     * \param engine �V�[�h�����֐�
     */
    CustomSeedEngine(SeedEngineParameter::Engine<Seed_> engine)
        : PrimarySeedEngine<Seed_>(SeedEngineParameter<Seed_>{SeedEngineID::Custom, engine})
    {
    }
};
} // namespace random_number_generator
