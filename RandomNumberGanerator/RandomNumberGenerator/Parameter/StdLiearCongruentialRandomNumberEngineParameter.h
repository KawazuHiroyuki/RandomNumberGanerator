/*****************************************************************//**
 * \file   StdLiearCongruentialRandomNumberEngineParameter.h
 * \brief  �����G���W���p�����[�^ - std::linear_congruential_engine
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include "RandomNumberEngineID.h"

namespace random_number_generator
{
/**
 * \brief �����G���W���p�����[�^ - std::linear_congruential_engine
 * \tparam EngineResultType_ �������镄���Ȃ������̌^
 * \tparam Multiplier_ �搔
 * \tparam Increment_ ����
 * \tparam Modulus_ �@
 */
template <
    typename EngineResultType_,
    EngineResultType_ Multiplier_,
    EngineResultType_ Increment_,
    EngineResultType_ Modulus_
>
struct StdLiearCongruentialRandomNumberEngineParameter
{
    /**
     * \brief �������镄���Ȃ������̌^
     */
    using EngineResultType = EngineResultType_;

    /**
     * \brief �搔(a)
     * \note  m ���� 0 �̏ꍇ a < m �łȂ���΂Ȃ�Ȃ�
     */
    static constexpr EngineResultType Multiplier = Multiplier_;

    /**
     * \brief ����(c)
     * \note m ���� 0 �̏ꍇ c < m �łȂ���΂Ȃ�Ȃ�
     */
    static constexpr EngineResultType Increment = Increment_;

    /**
     * \brief �@(m)
     * \note 0 �̏ꍇ std::numeric_limits<EngineResultType_>::max()
     */
    static constexpr EngineResultType Modulus = Modulus_;

    /**
     * \brief �����G���W��ID
     */
    static constexpr RandomNumberEngineID ID = RandomNumberEngineID::StdLiearCongruential;
};
} // namespace random_number_generator
