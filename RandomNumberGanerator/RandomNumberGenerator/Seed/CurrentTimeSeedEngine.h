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
    using PrimarySeedEngine<Seed_>::Seed;

public:
    /**
     * \brief �R���X�g���N�^
     */
    CurrentTimeSeedEngine(void)
        : PrimarySeedEngine<Seed>(SeedEngineParameter<Seed>{
            SeedEngineID::CurrentTime,
            []() { return static_cast<Seed>(std::time(nullptr)); }
            })
    {
    }
};
} // namespace random_number_generator
