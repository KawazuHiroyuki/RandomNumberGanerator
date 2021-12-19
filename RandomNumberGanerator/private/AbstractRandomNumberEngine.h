#pragma once

#include <cstdint>

#include "../RandomNumberEngineID.h"

namespace random_number_generator
{
class AbstractRandomNumberEngine
{
public:
    /**
     * \brief 指定した回数だけ疑似乱数を生成し、内部状態を進める
     * \param skip 指定回数
     */
    virtual void discard(std::uint64_t skip) = 0;

    /**
     * \brief エントロピー(乱数の乱雑さの度合い)を取得
     * \return エントロピー
     */
    virtual double getEntropy(void) const noexcept = 0;

    /**
     * \brief 乱数エンジンIDを取得
     * \return 乱数エンジンID
     */
    virtual RandomNumberEngineID getRandomNumberEngineID(void) const = 0;
};
} // namespace random_number_generator
