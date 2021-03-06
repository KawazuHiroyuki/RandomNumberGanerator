/*****************************************************************//**
 * \file   AbstractRandomNumberEngine.h
 * \brief  抽象乱数エンジン
 *
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

namespace random_number_generator
{
/**
 * \brief 抽象乱数エンジン
 */
class AbstractRandomNumberEngine
{
public:
    virtual ~AbstractRandomNumberEngine(void) = 0;
};
} // namespace random_number_generator
