#pragma once

#include <cstdint>

#include "../RandomNumberEngineID.h"

namespace random_number_generator
{
class AbstractRandomNumberEngine
{
public:
    /**
     * \brief �w�肵���񐔂����^�������𐶐����A������Ԃ�i�߂�
     * \param skip �w���
     */
    virtual void discard(std::uint64_t skip) = 0;

    /**
     * \brief �G���g���s�[(�����̗��G���̓x����)���擾
     * \return �G���g���s�[
     */
    virtual double getEntropy(void) const noexcept = 0;

    /**
     * \brief �����G���W��ID���擾
     * \return �����G���W��ID
     */
    virtual RandomNumberEngineID getRandomNumberEngineID(void) const = 0;
};
} // namespace random_number_generator
