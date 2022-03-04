/*****************************************************************//**
 * \file   CurrentTimeSeedEngine.h
 * \brief  ���ݎ��� �V�[�h�G���W��
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <ctime>
// My
#include "PrimarySeedEngine.h"

namespace random_number_generator
{
/**
 * \brief ���ݎ��� �V�[�h�G���W��
 * \tparam Seed_ �V�[�h�̌^
 */
template <typename Seed_>
class CurrentTimeSeedEngine : public PrimarySeedEngine<Seed_>
{
public:
    /**
     * \brief �R���X�g���N�^
     */
    CurrentTimeSeedEngine(void)
        : PrimarySeedEngine<Seed_>(SeedEngineParameter<Seed_>{SeedEngineID::CurrentTime, createEngine()})
    {
    }

private:
    /**
     * \brief �V�[�h�G���W������
     * \return �V�[�h�G���W��
     */
    SeedEngineParameter<Seed_>::Engine<Seed_> createEngine(void) const
    {
        return []() { return static_cast<Seed_>(std::time(nullptr)); };
    }
};
} // namespace random_number_generator
