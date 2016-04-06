/**
 * \file
 * \brief Header for RCC-related functions for STM32F0
 *
 * This file covers devices as described in following places:
 * - RM0091 reference manual (STM32F0x1, STM32F0x2, STM32F0x8), Revision 8, 2015-07-29
 * - RM0360 reference manual (STM32F030x4/6/8/C, STM32F070x6/B), Revision 3, 2015-05-19
 *
 * \author Copyright (C) 2016 Kamil Szczygiel http://www.distortec.com http://www.freddiechopin.info
 *
 * \par License
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
 * distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef SOURCE_CHIP_STM32_STM32F0_INCLUDE_DISTORTOS_CHIP_STM32F0_RCC_HPP_
#define SOURCE_CHIP_STM32_STM32F0_INCLUDE_DISTORTOS_CHIP_STM32F0_RCC_HPP_

#include "distortos/distortosConfiguration.h"

#if defined(CONFIG_CHIP_STM32F04) || defined(CONFIG_CHIP_STM32F071) || defined(CONFIG_CHIP_STM32F072) || \
	defined(CONFIG_CHIP_STM32F078) || defined(CONFIG_CHIP_STM32F09)

#define STM32F04_STM32F071_STM32F072_STM32F078_STM32F09_RCC_FEATURES

#endif	// defined(CONFIG_CHIP_STM32F04) || defined(CONFIG_CHIP_STM32F071) || defined(CONFIG_CHIP_STM32F072) ||
		// defined(CONFIG_CHIP_STM32F078) || defined(CONFIG_CHIP_STM32F09)

namespace distortos
{

namespace chip
{

/*---------------------------------------------------------------------------------------------------------------------+
| global functions' declarations
+---------------------------------------------------------------------------------------------------------------------*/

/**
 * \brief Disables HSE clock.
 *
 * \warning Before changing configuration of HSE clock make sure that it is not used in any way (as core clock, as
 * source for any PLL or as source of RTC clock).
 */

void disableHse();

#ifdef STM32F04_STM32F071_STM32F072_STM32F078_STM32F09_RCC_FEATURES

/**
 * \brief Disables HSI48 clock.
 *
 * \warning Before changing configuration of HSI48 clock make sure that it is not used in any way (as core clock, as
 * source for any PLL or as source of USB clock).
 */

void disableHsi48();

#endif	// def STM32F04_STM32F071_STM32F072_STM32F078_STM32F09_RCC_FEATURES

/**
 * \brief Enables HSE clock.
 *
 * Enables HSE clock using crystal/ceramic resonator (bypass disabled) or external user clock (bypass enabled). This
 * function waits until the HSE oscillator is stable after enabling the clock.
 *
 * \warning Before changing configuration of HSE clock make sure that it is not used in any way (as core clock, as
 * source for any PLL or as source of RTC clock).
 *
 * \param [in] bypass selects whether crystal/ceramic resonator (false) or external user clock (true) is used
 */

void enableHse(bool bypass);

}	// namespace chip

}	// namespace distortos

#endif	// SOURCE_CHIP_STM32_STM32F0_INCLUDE_DISTORTOS_CHIP_STM32F0_RCC_HPP_
