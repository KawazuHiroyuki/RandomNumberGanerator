/*****************************************************************//**
 * \file   AbstractRandomNumberDistribution.h
 * \brief  ���ۗ������z
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// My
#include "ID/RandomNumberDistributionID.h"

namespace random_number_generator
{
/**
 * \brief ���ۗ������z
 * \tparam DistributionResultType_ �������z �������ʂ̌^
 */
template <
    typename DistributionResultType_
>
class AbstractRandomNumberDistribution
{
public:
    /**
     * \brief �������z �������ʂ̌^
     */
    using DistributionResultType = DistributionResultType_;

public:
    /**
     * \brief �����𐶐�
     * \param engine �����G���W��
     * \return ����
     */
    template <typename RandomNumberEngine>
    virtual DistributionResultType operator()(RandomNumberEngine& engine) = 0;

    /**
     * \brief ��Ԃ����Z�b�g
     */
    virtual void reset(void) = 0;

    /**
     * \brief �������zID���擾
     * \return �������zID
     */
    virtual RandomNumberDistributionID getRandomNumberDistributionID(void) const = 0;
};
} // namespace random_number_generator
