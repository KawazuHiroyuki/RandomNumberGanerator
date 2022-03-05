/*****************************************************************//**
 * \file   AbstractTrueRandomNumberGenerator.h
 * \brief  抽象真性乱数生成器
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include "AbstractBaseRandomNumberGenerator.h"

namespace random_number_generator
{
/**
 * \brief 抽象真性乱数生成器
 * \tparam ResultType_ 乱数の型
 */
//template <
//    typename ResultType_
//>
class AbstractTrueRandomNumberGenerator : public AbstractBaseRandomNumberGenerator/*<ResultType_>*/
{
public:
#if 0
    /**
     * \brief 指定した回数だけ疑似乱数を生成し、内部状態を進める
     * \param skip 指定回数
     */
    void discard(std::uint64_t skip) override = delete;
#endif
};
} // namespace random_number_generator
