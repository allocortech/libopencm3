/** @defgroup pwr_defines PWR Defines

@brief <b>Defined Constants and Types for the STM32H7xx Power Control</b>

@ingroup STM32H7xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2019 Brian Viele <vielster@allocor.tech>

@date 6 November 2019

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2017 Matthew Lai <m@matthewlai.ca>
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

#ifndef LIBOPENCM3_PWR_H
#define LIBOPENCM3_PWR_H

/**@{*/

/** @defgroup pwr_registers PWR Registers
 * @ingroup STM32F_pwr_defines
@{*/
/** Power control register (PWR_CR1) */
#define PWR_CR1         MMIO32(POWER_CONTROL_BASE + 0x00)

/** Power control/status register (PWR_CSR1) */
#define PWR_CSR1        MMIO32(POWER_CONTROL_BASE + 0x04)

/** Power control register 2 (PWR_CR2) */
#define PWR_CR2         MMIO32(POWER_CONTROL_BASE + 0x08)

/** Power control register 3 (PWR_CR3) */
#define PWR_CR3         MMIO32(POWER_CONTROL_BASE + 0x0C)

/** CPU Power control register 3 (PWR_CPUCR) */
#define PWR_CPUCR       MMIO32(POWER_CONTROL_BASE + 0x10)

/** D3 Domain Power Control register (PWR_D3CR) */
#define PWR_D3CR        MMIO32(POWER_CONTROL_BASE + 0x18)

/** Wakeup Domain Power Control register (PWR_WKUPCR) */
#define PWR_WKUPCR      MMIO32(POWER_CONTROL_BASE + 0x20)

/*@}*/

/* VOS[15:14]: Regulator voltage scaling output selection */
#define PWR_CR1_SVOS_SHIFT        14
#define PWR_CR1_SVOS_SCALE_3       (0x3 << PWR_CR1_SVOS_SHIFT)
#define PWR_CR1_SVOS_SCALE_4       (0x2 << PWR_CR1_SVOS_SHIFT)
#define PWR_CR1_SVOS_SCALE_5       (0x3 << PWR_CR1_SVOS_SHIFT)
#define PWR_CR1_SVOS_MASK          (0x3 << PWR_CR1_SVOS_SHIFT)

/** VOSRDY: Regulator voltage scaling output selection ready bit */
#define PWR_CSR1_ACTVOSRDY        (1 << 13)

/** PVDO: PVD output */
#define PWR_CSR1_PVDO             (1 << 4)

/* --- Function prototypes ------------------------------------------------- */
enum pwr_svos_scale {
  PWR_SCALE3 = PWR_CR1_SVOS_SCALE_3,
  PWR_SCALE4 = PWR_CR1_SVOS_SCALE_4,
  PWR_SCALE5 = PWR_CR1_SVOS_SCALE_5,
};

BEGIN_DECLS

void pwr_set_svos_scale(enum pwr_svos_scale scale);

END_DECLS

/**@}*/

#endif
