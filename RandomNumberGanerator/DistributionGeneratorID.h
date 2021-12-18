/*****************************************************************//**
 * \file   DistributionGeneratorID.h
 * \brief  分布生成器ID
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

namespace random_number_generator
{
/**
 * \brief 分布生成器ID
 */
enum class DistributionGeneratorID {
    NoAdjustment = 0, //!< 無調整
    // C++標準:一様分布
    StdUniform, //!< 一様分布
    // C++標準:ベルヌーイ分布
    StdBernoulli, //!< ベルヌーイ分布
    StdBinomial, //!< 二項分布
    StdGeometric, //!< 幾何分布
    StdNegaivaBinomial, //!< 負の二項分布
    // C++標準:ポワソン分布
    StdPoisson, //!< ポワソン分布
    StdExponetial, //!< 指数分布
    StdGamma, //!< ガンマ分布
    StdWeibull, //!< ワイブル分布
    StdExtreme, //!< 極値分布
    // C++標準:正規分布
    StdNormal, //!< 正規分布
    StdLognomarl, //!< 対数正規分布
    StdChiSquared, //!< カイ二乗分布
    StdCauchy, //!< コーシー分布
    StdFisherF, //!< フィッシャーF分布
    StdStudentT, //!< スチューデントT分布
    // C++標準:標本分布
    StdDiscrete, //!< 整数インデックスごとに離散した確率分布
    StdPiecewiseConstant, //!< 区間ごとの重み付けを低数値とした分布
    StdPiecewiseLinear, //!< 区間ごとの重みづけを線形に接続した分布
};
} // namespace random_number_generator
