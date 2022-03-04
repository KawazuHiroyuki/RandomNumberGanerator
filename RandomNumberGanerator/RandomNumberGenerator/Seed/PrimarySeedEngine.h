/*****************************************************************//**
 * \file   PrimarySeedEngine.h
 * \brief  プライマリシードエンジン
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// My
#include "SeedEngineParameter.h"
#include "AbstractSeedEngine.h"

namespace random_number_generator
{
/**
 * \brief プライマリシードエンジン
 * \tparam Seed_ シードの型
 */
template <typename Seed_>
class PrimarySeedEngine : public AbstractSeedEngine<Seed_>
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
    PrimarySeedEngine(SeedEngineParameter<Seed> param = {})
        : m_param(param)
    {
    }

    /**
     * \brief シードを生成
     * \return シード
     */
    virtual Seed operator()(void) override
    {
        return m_param.engine();
    }

    /**
     * \brief シードエンジンパラメータを取得
     * \return シードエンジンパラメータ
     */
    virtual SeedEngineParameter<Seed> getParam(void) const override
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
