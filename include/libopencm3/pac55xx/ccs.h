/** @file
 *
 *  Clock Control and System Defines for the Qorvo PAC55xx series of microcontrollers.
 *
 *  @defgroup system_defines Clock Config and System Defines.
 *  @ingroup PAC55xx
 *  @author Brian Viele <vielster@allocor.tech>
 *  LGPL License Terms @ref lgpl_license
 *  @date 1 Dec 2019
 *
 *  Definitions in this file come from the PAC55XX Family User Guide Rev 1.21
 *  by Active-Semi dated August 26, 2019.
 */
/*
 * This file is part of the libopencm3 project.
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
#ifndef INCLUDE_LIBOPENCM3_PAC55XX_CCS_H_
#define INCLUDE_LIBOPENCM3_PAC55XX_CCS_H_

#include <libopencm3/cm3/common.h>

/* clang-format off */
/* Clock Control Registers */
/** @defgroup clock_config_regs Clock Config Registers.
@ingroup system_defines
@{*/
#define CCSCTL                        MMIO32(SCC_BASE)
#define CCSPLLCTL                     MMIO32(SCC_BASE + 0x04)
#define CCSROSCTRIM                   MMIO32(SCC_BASE + 0x08)
/**@}*/

/* Port Pin Config Addresses */
/** @defgroup port_pin_addresses Port Pinmux Register Base.
@ingroup system_defines
@{*/
#define CCS_PORTA                     (SCC_BASE + 0x0C)
#define CCS_PORTB                     (SCC_BASE + 0x10)
#define CCS_PORTC                     (SCC_BASE + 0x14)
#define CCS_PORTD                     (SCC_BASE + 0x18)
#define CCS_PORTE                     (SCC_BASE + 0x1C)
#define CCS_PORTF                     (SCC_BASE + 0x20)
#define CCS_PORTG                     (SCC_BASE + 0x24)
/**@}*/

/* Port Pin Mux Select Registers */
/** @defgroup pmux_sel_regs PMUXSEL register mapping.
@ingroup system_defines
@{*/
#define CCS_MUXSELR(base)             MMIO32(base)
#define CCS_PAMUXSELR                 MUXSELR(PORTA)
#define CCS_PBMUXSELR                 MUXSELR(PORTB)
#define CCS_PCMUXSELR                 MUXSELR(PORTC)
#define CCS_PDMUXSELR                 MUXSELR(PORTD)
#define CCS_PEMUXSELR                 MUXSELR(PORTE)
#define CCS_PFMUXSELR                 MUXSELR(PORTF)
#define CCS_PGMUXSELR                 MUXSELR(PORTG)
#define CCS_MUXSELR_MASK              0x7
/* clang-format on */

/* Enum type for port function setting for type specificity. */
typedef enum {
	CCS_MUXSEL_GPIO = 0,
	CCS_MUXSEL_AF1  = 1,
	CCS_MUXSEL_AF2  = 2,
	CCS_MUXSEL_AF3  = 3,
	CCS_MUXSEL_AF4  = 4,
	CCS_MUXSEL_AF5  = 5,
	CCS_MUXSEL_AF6  = 6,
	CCS_MUXSEL_AF7  = 7,
} ccs_muxsel_func_t;
/**@}*/

/* clang-format off */
/* Port Pull-Up/Down Enable Registers. */
/** @defgroup pden_regs PUEN PDEN register mapping.
@ingroup system_defines
@{*/
#define CCS_PUENR(base)               MMIO32(base + 0x1C)
#define CCS_PAPUENR                   CCS_PUENR(PORTA)
#define CCS_PBPUENR                   CCS_PUENR(PORTB)
#define CCS_PCPUENR                   CCS_PUENR(PORTC)
#define CCS_PDPUENR                   CCS_PUENR(PORTD)
#define CCS_PEPUENR                   CCS_PUENR(PORTE)
#define CCS_PFPUENR                   CCS_PUENR(PORTF)
#define CCS_PGPUENR                   CCS_PUENR(PORTG)
#define CCS_PDENR(base)               MMIO32(base + 0x38)
#define CCS_PAPDENR                   CCS_PDENR(PORTA)
#define CCS_PBPDENR                   CCS_PDENR(PORTB)
#define CCS_PCPDENR                   CCS_PDENR(PORTC)
#define CCS_PDPDENR                   CCS_PDENR(PORTD)
#define CCS_PEPDENR                   CCS_PDENR(PORTE)
#define CCS_PFPDENR                   CCS_PDENR(PORTF)
#define CCS_PGPDENR                   CCS_PDENR(PORTG)
/* clang-format on */

/* Pull Up/Down enum for type specificity. */
typedef enum {
	CCS_IO_PULL_NONE = 0,
	CCS_IO_PULL_UP   = 1,
	CCS_IO_PULL_DOWN = 2
} ccs_pull_updown_t;
/**@}*/

/* clang-format off */
/* Port Drive Strength Enable Registers. */
/** @defgroup dsr_regs DSR register mapping.
@ingroup system_defines
@{*/
#define CCS_DSR(base)                 MMIO32(base + 0x54)
#define CCS_PADSR                     CCS_DSR(PORTA)
#define CCS_PBDSR                     CCS_DSR(PORTB)
#define CCS_PCDSR                     CCS_DSR(PORTC)
#define CCS_PDDSR                     CCS_DSR(PORTD)
#define CCS_PEDSR                     CCS_DSR(PORTE)
#define CCS_PFDSR                     CCS_DSR(PORTF)
#define CCS_PGDSR                     CCS_DSR(PORTG)
#define CCS_DSR_MASK                  0x7
#define CCS_DSR_MASK_PIN(pin)         (CCS_DSR_MASK << ((pin)) * 4)
#define CCS_DSR_DS_VAL(pin, ds)       (((ds) & CCS_DSR_MASK) << ((pin) * 4))
#define CCS_DSR_SCHMIDT_PIN(pin)      (BIT0 << (((pin) * 4) + 3))
/* clang-format on */

/* Drive strength enumeration for type specificity. */
typedef enum {
	CCS_DSR_DS_6MA  = 0x00,
	CCS_DSR_DS_8MA  = 0x01,
	CCS_DSR_DS_11MA = 0x02,
	CCS_DSR_DS_14MA = 0x03,
	CCS_DSR_DS_17MA = 0x04,
	CCS_DSR_DS_20MA = 0x05,
	CCS_DSR_DS_22MA = 0x06,
	CCS_DSR_DS_25MA = 0x07,
} ccs_drive_strength_t;

/* clang format off */
#define CCS_DSR_DS(pin_, ds_) (ds_ << (pin << 4))
#define CCS_DSR_SCHMIDT_EN(pin_) (1 << ((pin << 4) + 3))
/**@}*/
/* clang format on */

#endif /* INCLUDE_LIBOPENCM3_PAC55XX_CCS_H_ */
