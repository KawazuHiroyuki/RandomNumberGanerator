/*****************************************************************//**
 * \file   SeedEngine.h
 * \brief  シードエンジン
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

#include "../SeedEngineParameter.h"

namespace random_number_generator
{
/**
 * \brief シードエンジン
 * \tparam Seed_ シードの型
 */
template <typename Seed_>
class SeedEngine
{
public:
    /**
     * \brief 乱数エンジンに渡すシードの型
     */
    using Seed = Seed_;

public:
    /**
     * \brief コンストラクタ
     * \param param シードエンジンパラメータ
     */
    SeedEngine(SeedEngineParameter<Seed> param = {})
        : m_param(param)
    {
    }

    /**
     * \brief シードを生成
     * \return シード
     */
    Seed operator()(void)
    {
        return m_param.engine();
    }

    /**
     * \brief シードエンジンパラメータを取得
     * \return シードエンジンパラメータ
     */
    SeedEngineParameter<Seed> getParam(void) const
    {
        return m_param;
    }

private:
    /**
     * \brief シードエンジンパラメータ
     */
    SeedEngineParameter<Seed> m_param;
};
} // namespace random_number_generator
