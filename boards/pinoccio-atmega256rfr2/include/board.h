/*
 * Copyright (C) 2016 RWTH Aachen, Josua Arndt
 * Copyright (C) 2014 Freie Universität Berlin, Hinnerk van Bruinehsen
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    boards_jiminy-mega256rfr2 Jiminy- Mega256rfr2
 * @ingroup     boards
 * @brief       Board specific files for the Jiminy Mega 256rfr2 board.
 * @{
 *
 * @file
 * @brief       Board specific definitions for the Jiminy Mega 256rfr2 board.
 *
 * @author      Hinnerk van Bruinehsen <h.v.bruinehsen@fu-berlin.de>
 * @author      Josua Arndt <jarndt@ias.rwth-aachen.de>
 * @author      Steffen Robertz <steffen.robertz@rwth-aachen.de>
 */

#ifndef BOARD_H
#define BOARD_H

#include "cpu.h"

#ifdef __cplusplus
extern "C" {
#endif

/*Fastest Baudrate possible for board*/
#define UART_STDIO_BAUDRATE (115200U)

/**
 * @name   LED pin definitions and handlers
 * @{
 */
#define LED_PORT            PORTB
#define LED_PORT_DDR        DDRB

#define LED_BLUE_PIN        GPIO_PIN(1, 4)
#define LED_RED_PIN         GPIO_PIN(1, 5)
#define LED_GREEN_PIN       GPIO_PIN(1, 6)

#define BLUE            (1 << DDRB4)
#define RED             (1 << DDRB5)
#define GREEN           (1 << DDRB6)
/** @} */

/**
 * @name   Miscellaneous pin definitions and handlers
 * @{
 */

#define VCC_ENABLE      GPIO_PIN(3, 4)
#define BATT_ALERT      GPIO_PIN(4, 7)
#define CHG_STATUS      GPIO_PIN(3, 7)
/** @} */

/**
 * @name Define the interface to the AT86RF231 radio
 *
 * {spi bus, spi speed, cs pin, int pin, reset pin, sleep pin}
 * @{
 */
#define AT86RF2XX_PARAMS_BOARD      {}
/** @} */

/**
 * @name Context swap defines
 * This emulates a software triggered interrupt
 */
/*TODO Check if the not implemented I/O pin interrupt could be used to not waste pin,
 *Note that the I/O ports corresponding to PCINT23:16 are not implemented. Therefore PCIE2 has no function in this device
 */
#define AVR_CONTEXT_SWAP_INIT do { \
        DDRE |= (1 << PE7); \
        EICRB |= (1 << ISC70); \
        EIMSK |= (1 << INT7); \
        sei(); \
} while (0)
#define AVR_CONTEXT_SWAP_INTERRUPT_VECT  INT7_vect
#define AVR_CONTEXT_SWAP_TRIGGER   PORTE ^= (1 << PE7)
/** @} */


/**
 * @name Initialize board specific hardware, including clock, LEDs and std-IO
 * @{
 */
void board_init(void);
/** @} */
#ifdef __cplusplus
}
#endif

#endif /* BOARD_H */
/** @} */