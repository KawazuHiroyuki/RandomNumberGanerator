/*****************************************************************//**
 * \file   SeedGenerator.h
 * \brief  シード生成器
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include "../SeedGeneratorParameter.h"

namespace random_number_generator
{
/**
 * \brief シード生成器
 */
template <typename Type>
class SeedGenerator
{
public:
    /**
     * \brief シード型
     */
    using Random = Type;

public:
    /**
     * \brief コンストラクタ
     * \param param シード生成器パラメータ
     */
    SeedGenerator(SeedGeneratorParameter<Type> param)
        : m_param(param)
    {
    }

    /**
     * \brief シードを生成
     * \return シード
     */
    Type operator()(void)
    {
        return m_param();
    }

    /**
     * \brief シード生成器パラメータを取得
     * \return シード生成器パラメータ
     */
    SeedGeneratorParameter<Type> getParam(void) const
    {
        return m_param;
    }

private:
    SeedGeneratorParameter<Type> m_param;
};
} // namespace random_number_generator
