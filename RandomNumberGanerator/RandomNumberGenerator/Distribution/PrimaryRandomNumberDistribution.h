#pragma once

#include "../RandomNumberDistributionParameter.h"
#include "AbstractRandomNumberDistribution.h"

namespace random_number_generator
{
/**
 * \brief �������z
 * \tparam Distribution_�������z
 * \tparam DistributionResultType_ �������z �������ʂ̌^
 */
template <
    typename Distribution_,
    typename DistributionResultType_
>
class PrimaryRandomNumberDistribution : public AbstractRandomNumberDistribution<DistributionResultType_>
{
public:
    /**
     * \brief �������z�̌^
     */
    using Distribution = Distribution_;

public:
    /**
     * \brief �R���X�g���N�^
     * \param param �������z�p�����[�^
     * \param distribution �������z
     */
    PrimaryRandomNumberDistribution(const RandomNumberDistributionParameter& param, Distribution&& engine)
        : m_param(param)
        , m_distribution(engine)
    {
    }

    virtual ~PrimaryRandomNumberDistribution(void) = default;

    /**
     * \brief �����𐶐�
     * \param engine �����G���W��
     * \return ����
     */
    template <typename RandomNumberEngine>
    virtual DistributionResultType_ operator()(RandomNumberEngine& engine) override
    {
        DistributionResultType_ result = m_distribution(engine);
        return result;
    }

    /**
     * \brief ��Ԃ����Z�b�g
     */
    virtual void reset(void) override
    {
        m_distribution.reset();
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

    /**
     * \brief �������z
     */
    Distribution m_distribution;
};
} // namespace random_number_generator