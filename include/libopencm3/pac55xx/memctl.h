/**
 * @brief Memory Controller definitions for the Qorvo PAC55xx series of microcontrollers
 *
 * @addtogroup PAC55xx_memctl MEMCTL
 * @ingroup PAC55xx_defines
 * @author Kevin Stefanik <kevin@allocor.tech>
 * LGPL License Terms @ref lgpl_license
 * @date 17 Mar 2020
 *
 * Definitions in this file come from the PAC55XX Family User Guide Rev 1.23
 * by Active-Semi dated November 19, 2019.
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2020 Kevin Stefanik <kevin@allocor.tech>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBOPENCM3_PAC55XX_MEMCTL_H_
#define LIBOPENCM3_PAC55XX_MEMCTL_H_

#include <libopencm3/cm3/common.h>
#include <libopencm3/pac55xx/memorymap.h>
/**@{*/


/** @defgroup memctl_reg Memory Controller Configuration Register
@{*/
/** Memory Controller Configuration Register */
#define MEMCTL          MMIO32(MEMCTL_BASE)
#define MEMCTL_WSTATE_MASK              (0xF)
#define MEMCTL_WSTATE(ws)               ((ws) & MEMCTL_WSTATE_MASK)
#define MEMCTL_MCLKDIV_MASK             (0xF)
#define MEMCTL_MCLKDIV_SHIFT            4
#define MEMCTL_MCLKDIV(d)               (((d) & MEMCTL_MCLKDIV_MASK) << MEMCTL_MCLKDIV_SHIFT)
#define MEMCTL_MCLKDIV1     (0)
#define MEMCTL_MCLKDIV2     (1)
#define MEMCTL_MCLKDIV3     (2)
#define MEMCTL_MCLKDIV4     (3)
#define MEMCTL_MCLKDIV5     (4)
#define MEMCTL_MCLKDIV6     (5)
#define MEMCTL_MCLKDIV7     (6)
#define MEMCTL_MCLKDIV8     (7)
#define MEMCTL_MCLKDIV9     (8)
#define MEMCTL_MCLKDIV10    (9)
#define MEMCTL_MCLKDIV11    (10)
#define MEMCTL_MCLKDIV12    (11)
#define MEMCTL_MCLKDIV13    (12)
#define MEMCTL_MCLKDIV14    (13)
#define MEMCTL_MCLKDIV15    (14)
#define MEMCTL_MCLKDIV16    (15)
#define MEMCTL_WRITEWORDCNT_MASK        (0x3)
#define MEMCTL_WRITEWORDCNT_SHIFT       8
#define MEMCTL_WRITEWORDCNT(cnt)        (((cnt) & MEMCTL_WRITEWORDCNT_MASK) << MEMCTL_WRITEWORDCNT_SHIFT)
#define MEMCTL_SEIE                     BIT16
#define MEMCTL_DEIE                     BIT17
#define MEMCTL_INVADDRIE                BIT18
#define MEMCTL_STBY                     BIT19
#define MEMCTL_ECCDIS                   BIT20
#define MEMCTL_CACHEDIS                 BIT21
#define MEMCTL_MCLKSEL                  BIT22
/**@}*/

/** @defgroup memstatus_reg Memory Controller Status Register
@{*/
/** Memory Controller Status Register */
#define MEMSTATUS       MMIO32(MEMCTL_BASE + 0x0004)
#define MEMSTATUS_WBUSY                 BIT0
#define MEMSTATUS_EBUSY                 BIT1
#define MEMSTATUS_WRITEWORDCNT_MASK     (0x3)
#define MEMSTATUS_WRITEWORDCNT_SHIFT    8
#define MEMSTATUS_WRITEWORDCNT(cnt)     (((cnt) & MEMSTATUS_WRITEWORDCNT_MASK) << MEMSTATUS_WRITEWORDCNT_SHIFT)
#define MEMSTATUS_SE                    BIT16
#define MEMSTATUS_DE                    BIT17
#define MEMSTATUS_INVADDR               BIT18
/**@}*/

/** @defgroup flashlock_vals Flash Lock/Write Enable Register values
@{*/
/** Flash Lock Access Register */
#define FLASHLOCK       MMIO32(MEMCTL_BASE + 0x0008)
#define FLASHLOCK_CLEAR                 (0)
#define FLASHLOCK_ALLOW_FLASH_WRITE     (0x43DF140A)
#define FLASHLOCK_ALLOW_MEMCTL_WRITE    (0xD513B490)
#define FLASHLOCK_ALLOW_INFO2_SWDFUSE   (0x79B4F762)
/**@}*/

/** Flash Page Address Register */
#define FLASHPAGE       MMIO32(MEMCTL_BASE + 0x000C)
/** SWD Unlock Register */
#define SWDUNLOCK       MMIO32(MEMCTL_BASE + 0x0010)

/** @defgroup flasherase_vals Flash Erase Enable Register values
@{*/
/** Flash Erase Enable Register */
#define FLASHERASE      MMIO32(MEMCTL_BASE + 0x0020)
#define FLASHERASE_PAGE_ERASE           (0x8C799CA7)
#define FLASHERASE_MASS_PAGE_ERASE      (0x09EE76C9)
#define FLASHERASE_INFO3_ERASE          (0x1266FF45)
/**@}*/

#endif /* LIBOPENCM3_PAC55XX_MEMCTL_H_ */
