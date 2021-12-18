/*****************************************************************//**
 * \file   SeedGaneratorID.h
 * \brief  V[h¶¬íID
 * 
 * \author japan
 * \date   December 2021
 *********************************************************************/
#pragma once
namespace random_number_ganerator
{
    /**
     * \brief V[h¶¬íID
     */
    enum class SeedGaneratorID {
        // C++W
        StdRandomDevice = 0, //!< \ªs\È¶¬í
        // ÅL
        CurrentTime, //!< »Ý (ñ§)
        // Custom
        Custom, //!< JX^
    };
} // namespace random_number_ganerator
