/*****************************************************************//**
 * \file   StdSubtractWithCarryRandomNumberEngineParameter.h
 * \brief  �����G���W���p�����[�^ - std::subtract_with_carry_engine	
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include <cstddef>

#include "RandomNumberEngineID.h"

namespace random_number_generator
{
/**
 * \brief �����G���W���p�����[�^ - std::subtract_with_carry_engine
 * \tparam EngineResultType_ �������镄���Ȃ������̌^
 * \tparam WordSize_ ���[�h�T�C�Y
 * \tparam ShortLag_ �Z�����O
 * \tparam LongLag_ �������O
 */
template <
    typename EngineResultType_,
    std::size_t WordSize_,
    std::size_t ShortLag_,
    std::size_t LongLag_
>
struct StdSubtractWithCarryRandomNumberEngineParameter
{
    /**
     * \brief �����G���W�����������闐���̌^
     */
    using EngineResultType = EngineResultType_;

    /**
     * \brief ���[�h�T�C�Y (w)
     * \note 0 < w <=std::numeric_limits<EngineResultType_>::digits �łȂ���΂Ȃ�Ȃ�
     */
    static constexpr std::size_t WordSize = WordSize_;

    /**
     * \brief �Z�����O (s)
     * \note 0 < s < r �łȂ���΂Ȃ�Ȃ�
     */
    static constexpr std::size_t ShortLag = ShortLag_;

    /**
     * \brief �������O (r)
     * \note 0 < s < r �łȂ���΂Ȃ�Ȃ�
     */
    static constexpr std::size_t LongLag = LongLag_;

    /**
     * \brief �����G���W��ID
     */
    static constexpr RandomNumberEngineID ID = RandomNumberEngineID::StdSubtractWithCarry;
};
} // namespace random_number_generator
