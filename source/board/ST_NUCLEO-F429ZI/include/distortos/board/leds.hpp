/**
 * \file
 * \brief Declaration of leds for ST,NUCLEO-F429ZI
 *
 * \author Copyright (C) 2014-2019 Kamil Szczygiel http://www.distortec.com http://www.freddiechopin.info
 *
 * \par License
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
 * distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * \warning
 * Automatically generated file - do not edit!
 */

#ifndef SOURCE_BOARD_ST_NUCLEO_F429ZI_INCLUDE_DISTORTOS_BOARD_LEDS_HPP_
#define SOURCE_BOARD_ST_NUCLEO_F429ZI_INCLUDE_DISTORTOS_BOARD_LEDS_HPP_

#include "distortos/distortosConfiguration.h"

#include <cstddef>

#ifdef DISTORTOS_BOARD_LEDS_LD1_ENABLE
#define DISTORTOS_BOARD_LEDS_LD1_ENABLED	1
#else	// !def DISTORTOS_BOARD_LEDS_LD1_ENABLE
#define DISTORTOS_BOARD_LEDS_LD1_ENABLED	0
#endif	// !def DISTORTOS_BOARD_LEDS_LD1_ENABLE

#ifdef DISTORTOS_BOARD_LEDS_LD2_ENABLE
#define DISTORTOS_BOARD_LEDS_LD2_ENABLED	1
#else	// !def DISTORTOS_BOARD_LEDS_LD2_ENABLE
#define DISTORTOS_BOARD_LEDS_LD2_ENABLED	0
#endif	// !def DISTORTOS_BOARD_LEDS_LD2_ENABLE

#ifdef DISTORTOS_BOARD_LEDS_LD3_ENABLE
#define DISTORTOS_BOARD_LEDS_LD3_ENABLED	1
#else	// !def DISTORTOS_BOARD_LEDS_LD3_ENABLE
#define DISTORTOS_BOARD_LEDS_LD3_ENABLED	0
#endif	// !def DISTORTOS_BOARD_LEDS_LD3_ENABLE

/// count of leds on the board
#define DISTORTOS_BOARD_LEDS_COUNT	(DISTORTOS_BOARD_LEDS_LD1_ENABLED + \
		DISTORTOS_BOARD_LEDS_LD2_ENABLED + \
		DISTORTOS_BOARD_LEDS_LD3_ENABLED)

#if defined(DISTORTOS_BOARD_LEDS_ENABLE) && DISTORTOS_BOARD_LEDS_COUNT != 0

namespace distortos
{

namespace chip
{

class ChipOutputPin;

}	// namespace chip

namespace board
{

/// count of leds on the board
constexpr size_t ledsCount {DISTORTOS_BOARD_LEDS_COUNT};

/*---------------------------------------------------------------------------------------------------------------------+
| indexes of leds
+---------------------------------------------------------------------------------------------------------------------*/

enum
{
#ifdef DISTORTOS_BOARD_LEDS_LD1_ENABLE
		/// index of Ld1 (Green) from leds
		ledsLd1Index,
#endif	// def DISTORTOS_BOARD_LEDS_LD1_ENABLE
#ifdef DISTORTOS_BOARD_LEDS_LD2_ENABLE
		/// index of Ld2 (Blue) from leds
		ledsLd2Index,
#endif	// def DISTORTOS_BOARD_LEDS_LD2_ENABLE
#ifdef DISTORTOS_BOARD_LEDS_LD3_ENABLE
		/// index of Ld3 (Red) from leds
		ledsLd3Index,
#endif	// def DISTORTOS_BOARD_LEDS_LD3_ENABLE
};

/*---------------------------------------------------------------------------------------------------------------------+
| alternative indexes of leds
+---------------------------------------------------------------------------------------------------------------------*/

#ifdef DISTORTOS_BOARD_LEDS_LD1_ENABLE

/// alternative index of Ld1 (Green) from leds
constexpr size_t ledsGreenIndex {ledsLd1Index};

#endif	// def DISTORTOS_BOARD_LEDS_LD1_ENABLE

#ifdef DISTORTOS_BOARD_LEDS_LD2_ENABLE

/// alternative index of Ld2 (Blue) from leds
constexpr size_t ledsBlueIndex {ledsLd2Index};

#endif	// def DISTORTOS_BOARD_LEDS_LD2_ENABLE

#ifdef DISTORTOS_BOARD_LEDS_LD3_ENABLE

/// alternative index of Ld3 (Red) from leds
constexpr size_t ledsRedIndex {ledsLd3Index};

#endif	// def DISTORTOS_BOARD_LEDS_LD3_ENABLE

/*---------------------------------------------------------------------------------------------------------------------+
| indexed access to leds objects
+---------------------------------------------------------------------------------------------------------------------*/

/// array with all leds objects
extern chip::ChipOutputPin leds[ledsCount];

}	// namespace board

}	// namespace distortos

#endif	// defined(DISTORTOS_BOARD_LEDS_ENABLE) && DISTORTOS_BOARD_LEDS_COUNT != 0

#endif	// SOURCE_BOARD_ST_NUCLEO_F429ZI_INCLUDE_DISTORTOS_BOARD_LEDS_HPP_
