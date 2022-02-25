/*****************************************************************//**
 * \file   RandomNumberDistributionID.h
 * \brief  乱数分布ID
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/

#pragma once

namespace random_number_generator
{
/**
 * \brief 乱数分布ID
 */
enum class RandomNumberDistributionID {
    NoAdapt = 0, //!< 無適応
    // C++標準:一様分布
    StdIntUniform, //!< 一様整数分布
    StdRealUniform, //!< 一様実数分布
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

constexpr std::size_t RANDOM_NUMBER_DISTRIBUTION_ID_SIZE = static_cast<std::size_t>(RandomNumberDistributionID::StdPiecewiseLinear) + 1;

/**
 * \brief デフォルトの乱数分布ID
 */
constexpr RandomNumberDistributionID DEFAULT_RANDOM_NUMBER_DISTRIBUTION_ID = RandomNumberDistributionID::NoAdapt;
} // namespace random_number_generator
