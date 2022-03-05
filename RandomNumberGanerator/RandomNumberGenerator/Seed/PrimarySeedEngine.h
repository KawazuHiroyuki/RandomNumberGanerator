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
 * \tparam SeedEngineResultType_ シードエンジン生成結果の型
 */
template <typename SeedEngineResultType_>
class PrimarySeedEngine : public AbstractSeedEngine<SeedEngineResultType_>
{
public:
    /**
     * \brief シードエンジン生成結果の型
     */
    //using SeedEngineResultType = SeedEngineResultType_;

public:
    /**
     * \brief コンストラクタ
     * \param param シードエンジンパラメータ
     */
    PrimarySeedEngine(SeedEngineParameter<SeedEngineResultType_> param = {})
        : m_param(param)
    {
    }
    
    virtual ~PrimarySeedEngine() = 0;

    /**
     * \brief シードを生成
     * \return シード
     */
    virtual SeedEngineResultType_ operator()(void) override
    {
        return m_param.generator();
    }

    /**
     * \brief シードエンジンパラメータを取得
     * \return シードエンジンパラメータ
     */
    virtual SeedEngineParameter<SeedEngineResultType_> getParam(void) const override
    {
        return m_param;
    }

private:
    /**
     * \brief シードエンジンパラメータ
     */
    SeedEngineParameter<SeedEngineResultType_> m_param;
};

template <typename SeedEngineResultType_>
PrimarySeedEngine<SeedEngineResultType_>::~PrimarySeedEngine(void) {}
} // namespace random_number_generator
