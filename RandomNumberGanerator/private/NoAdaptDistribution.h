/*****************************************************************//**
 * \file   NoAdaptDistribution.h
 * \brief  �������z
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

 // MyProject
#include "../RandomNumberDistributionParameter.h"
 #include "AbstractRandomNumberDistribution.h"

namespace random_number_generator
{
/**
 * \brief �������z - std::uniform_int_distribution
 * \tparam DistributionResultType_ �������z �������ʂ̌^
 */
template <
    typename DistributionResultType_
>
class NoAdaptDistribution : public AbstractRandomNumberDistribution<DistributionResultType_>
{
private:
    using Base = AbstractRandomNumberDistribution<DistributionResultType_>;

public:
    NoAdaptDistribution(void)
        : Base()
        , m_param(RandomNumberDistributionID::NoAdapt)
    {
    }

    /**
     * \brief �����𐶐�
     * \param engine �����G���W��
     * \return ����
     */
    template <typename RandomNumberEngine>
    virtual DistributionResultType operator(RandomNumberEngine& engine) = 0;

    /**
     * \brief ��Ԃ����Z�b�g
     */
    virtual void reset(void) = 0;

    /**
     * \brief �������zID���擾
     * \return �������zID
     */
    virtual RandomNumberDistributionID getRandomNumberDistributionID(void) const = 0;

protected:
    /**
     * \brief �������z�p�����[�^
     */
    RandomNumberDistributionParameter m_param;
};
} // namespace random_number_generator
