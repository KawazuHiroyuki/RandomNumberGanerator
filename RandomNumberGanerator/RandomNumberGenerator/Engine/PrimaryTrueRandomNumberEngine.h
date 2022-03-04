#pragma once
// C++
#include <memory>
// MyProject
#include "Parameter/RandomNumberEngineParameter.h"
#include "AbstractRandomNumberEngine.h"

namespace random_number_generator
{
/**
 * \brief �^�������G���W��
 */
template <
    typename Engine_,
    typename EngineResultType_
>
class PrimaryTrueRandomNumberEngine : public AbstractRandomNumberEngine<EngineResultType_>
{
public:
    /**
     * \brief �G���W���̌^
     */
    using Engine = Engine_;

public:
    /**
     * \brief �R���X�g���N�^
     */
    PrimaryTrueRandomNumberEngine(void)
        : m_param(RandomNumberEngineID::StdRandomDevice)
        , m_engine()
    {
    }

    virtual ~PrimaryTrueRandomNumberEngine(void) = default;

#if 0
    /**
     * \brief �V�[�h��ݒ�
     * \param seed �V�[�h
     */
    virtual void setSeed(void) = delete;
#endif

    /**
     * \brief �����𐶐�
     * \return ����
     */
    virtual EngineResultType_ operator()(void) override
    {
        return m_engine();
    }

    /**
     * \brief �w�肵���񐔂����^�������𐶐����A������Ԃ�i�߂�
     * \param times �w���
     */
    void discard(std::uint64_t skip) override
    {
        // �Ȃ�
    }

    /**
     * \brief �G���g���s�[(�����̗��G���̓x����)���擾
     * \return �G���g���s�[
     */
    double getEntropy(void) const noexcept override
    {
        return m_engine.entropy();
    }

    /**
     * \brief ��������l�̍ŏ��l���擾
     * \return �ŏ��l
     */
    virtual EngineResultType_ getMin(void) const override
    {
        return Engine::min();
    }

    /**
     * \brief ��������l�̍ő�l���擾
     * \return �ő�l
     */
    virtual EngineResultType_ getMax(void) const override
    {
        return Engine::max();
    }

    /**
     * \brief �����G���W��ID���擾
     * \return �����G���W��ID
     */
    RandomNumberEngineID getRandomNumberEngineID(void) const override
    {
        return m_param.id;
    }

protected:
    /**
     * \brief �����G���W���p�����[�^
     */
    RandomNumberEngineParameter m_param;

    /**
     * \brief �����G���W��
     */
    Engine m_engine;
};
} // namespace random_number_generator