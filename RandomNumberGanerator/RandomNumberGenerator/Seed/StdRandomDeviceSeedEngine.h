/*****************************************************************//**
 * \file   StdRandomDeviceSeedGenerator.h
 * \brief  予測不能な乱数生成 シードエンジン
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

// C++
#include <random>
// My
#include "PrimarySeedEngine.h"

namespace random_number_generator
{
/**
 * \brief 予測不能な乱数生成 シードエンジン
 * \note std::random_device
 * \tparam SeedEngineResultType_ シードエンジン生成結果の型
 */
template <typename SeedEngineResultType_>
class StdRandomDeviceSeedEngine : public PrimarySeedEngine<SeedEngineResultType_>
{
public:
    /**
     * \brief コンストラクタ
     */
    StdRandomDeviceSeedEngine(void)
        : PrimarySeedEngine<SeedEngineResultType_>(SeedEngineParameter<SeedEngineResultType_>{SeedEngineID::StdRandomDevice, createGenerator()})
    {
    }

    virtual ~StdRandomDeviceSeedEngine(void) override = default;

private:
    /**
     * \brief シード生成関数を生成
     * \return シード生成関数
     */
    SeedEngineParameter<SeedEngineResultType_>::Generator<SeedEngineResultType_> createGenerator(void) const
    {
        return []() { return static_cast<SeedEngineResultType_>(std::random_device()()); };
    }
};
} // namespace random_number_generator
