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
#include "SeedEngine.h"

namespace random_number_generator
{
/**
 * \brief �V�[�h�G���W�� - ���ݎ���
 * \tparam Seed_ �V�[�h�̌^
 */
template <typename Seed_>
class CurrentTimeSeedEngine : public SeedEngine<Seed_>
{
    using SeedEngine<Seed_>::Seed;

public:
    /**
     * \brief �R���X�g���N�^
     */
    CurrentTimeSeedEngine(void)
        : SeedEngine<Seed>(SeedEngineParameter<Seed>{
            SeedEngineID::CurrentTime,
            []() { return static_cast<Seed>(std::time(nullptr)); }
            })
    {
    }
};
} // namespace random_number_generator
