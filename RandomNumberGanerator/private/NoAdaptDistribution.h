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
 * \brief �������z - ���K��
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
    /**
     * \brief �R���X�g���N�^
     */
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
    virtual DistributionResultType_ operator()(RandomNumberEngine& engine) override
    {
        DistributionResultType_ result = engine(); // TODO cast����H
        return result;
    }

    /**
     * \brief ��Ԃ����Z�b�g
     */
    virtual void reset(void) override
    {
    }

    /**
     * \brief �������zID���擾
     * \return �������zID
     */
    virtual RandomNumberDistributionID getRandomNumberDistributionID(void) const override
    {
        return m_param.id;
    }

protected:
    /**
     * \brief �������z�p�����[�^
     */
    RandomNumberDistributionParameter m_param;
};
} // namespace random_number_generator
