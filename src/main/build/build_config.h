/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))

#ifdef UNIT_TEST
// make these visible to unit test
#define STATIC_UNIT_TESTED
#define STATIC_INLINE_UNIT_TESTED
#define INLINE_UNIT_TESTED
#define UNIT_TESTED
#else
#define STATIC_UNIT_TESTED static
#define STATIC_INLINE_UNIT_TESTED static inline
#define INLINE_UNIT_TESTED inline
#define UNIT_TESTED
#endif

//#define SOFT_I2C // enable to test software i2c

#ifndef __CC_ARM
#define REQUIRE_CC_ARM_PRINTF_SUPPORT
#define REQUIRE_PRINTF_LONG_SUPPORT
#endif

#ifdef __APPLE__
#define FASTRAM                     __attribute__ ((section("__DATA,__.fastram_bss"), aligned(8)))
#else
#define FASTRAM                     __attribute__ ((section(".fastram_bss"), aligned(4)))
#endif

#if defined (STM32F4) || defined (STM32F7)
#define EXTENDED_FASTRAM FASTRAM
#else
#define EXTENDED_FASTRAM
#endif

#if defined (STM32H7)
#define DMA_RAM __attribute__ ((section(".DMA_RAM")))
#define SLOW_RAM __attribute__ ((section(".SLOW_RAM")))
#elif defined (AT32F43x)
#define DMA_RAM __attribute__ ((section(".DMA_RAM")))
#define SLOW_RAM __attribute__ ((section(".SLOW_RAM")))
#else
#define DMA_RAM
#define SLOW_RAM
#endif

#define STATIC_FASTRAM              static FASTRAM
#define STATIC_FASTRAM_UNIT_TESTED  STATIC_UNIT_TESTED FASTRAM
