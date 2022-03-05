/*****************************************************************//**
 * \file   CurrentTimeSeedEngine.h
 * \brief  現在時刻 シードエンジン
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <ctime>
// My
#include "PrimarySeedEngine.h"

namespace random_number_generator
{
/**
 * \brief 現在時刻 シードエンジン
 * \tparam SeedEngineResultType_ シードエンジン生成結果の型
 */
template <typename SeedEngineResultType_>
class CurrentTimeSeedEngine : public PrimarySeedEngine<SeedEngineResultType_>
{
public:
    /**
     * \brief コンストラクタ
     */
    CurrentTimeSeedEngine(void)
        : PrimarySeedEngine<SeedEngineResultType_>(SeedEngineParameter<SeedEngineResultType_>{SeedEngineID::CurrentTime, createGenerator()})
    {
    }

    virtual ~CurrentTimeSeedEngine(void) override = default;

private:
    /**
     * \brief シード生成関数を生成
     * \return シード生成関数
     */
    SeedEngineParameter<SeedEngineResultType_>::Generator<SeedEngineResultType_> createGenerator(void) const
    {
        return []() { return static_cast<SeedEngineResultType_>(std::time(nullptr)); };
    }
};
} // namespace random_number_generator
