/*****************************************************************//**
 * \file   AbstractRandomNumberGenerator.h
 * \brief  抽象乱数生成器
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

namespace random_number_generator
{
/**
 * \brief 抽象乱数生成器
 */
class AbstractRandomNumberGenerator
{
public:
    virtual ~AbstractRandomNumberGenerator(void) = 0;
};
} // namespace random_number_generator
