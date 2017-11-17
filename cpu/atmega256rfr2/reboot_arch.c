/*
 * Copyright (C) 2017 RWTH Aachen, Josua Arndt
 *		 2016 Kaspar Schleiser <kaspar@schleiser.de>
 *               2014 Freie Universität Berlin, Hinnerk van Bruinehsen
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     cpu_atmega256rfr2
 * @{
 *
 * @file
 * @brief       Implementation of the kernels reboot interface
 *
 * @author      Hinnerk van Bruinehsen <h.v.bruinehsen@fu-berlin.de>
 * @author      Kaspar Schleiser <kaspar@schleiser.de>
 * @author      Josua Arndt <jarndt@ias.rwth-aachen.de>
 * @author	Steffen Robertz <steffen.robertz@rwth-aachen.de>
 * @}
 */

#include <avr/wdt.h>

#include "cpu.h"

void reboot(void)
{
    /*
     * Since the AVR doesn't support a real software reset, we set the Watchdog
     * Timer on a 250ms timeout. Consider this a kludge.
     */
    wdt_enable(WDTO_250MS);
    while (1) ;
}

void pm_reboot(void) {
	reboot();
}