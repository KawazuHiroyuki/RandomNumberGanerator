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
template <typename Seed_>
class SeedGenerator
{
public:
    /**
     * \brief 乱数エンジンに渡すシードの型
     */
    using Seed = Seed_;

public:
    /**
     * \brief コンストラクタ
     * \param param シード生成器パラメータ
     */
    SeedGenerator(SeedGeneratorParameter<Seed> param = {})
        : m_param(param)
    {
    }

    /**
     * \brief シードを生成
     * \return シード
     */
    Seed operator()(void)
    {
        return m_param.generator();
    }

    /**
     * \brief シード生成器パラメータを取得
     * \return シード生成器パラメータ
     */
    SeedGeneratorParameter<Seed> getParam(void) const
    {
        return m_param;
    }

private:
    SeedGeneratorParameter<Seed> m_param;
};
} // namespace random_number_generator
