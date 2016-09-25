/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
  This code contributed by Triffid_Hunter and modified by Kliment
  why double up on these macros? see http://gcc.gnu.org/onlinedocs/cpp/Stringification.html
*/

//Matthias: Make this stuff faster.... just a cheapo hack. sorry

#ifndef _FASTIO_ARDUINO_H
#define _FASTIO_ARDUINO_H

#include <io.h>

/**
  utility functions
*/

#ifndef MASK
  #define MASK(PIN)  (1 << PIN)
#endif

/**
  magic I/O routines
  now you can simply SET_OUTPUT(STEP); WRITE(STEP, 1); WRITE(STEP, 0);
*/

/// Read a pin
#define _READ(IO) ((bool)(gpio_read_bit(PIN_MAP[IO].gpio_device, PIN_MAP[IO].gpio_bit))))
/// write to a pin

#define _WRITE(IO, v)  do {gpio_write_bit(PIN_MAP[IO].gpio_device, PIN_MAP[IO].gpio_bit, v); } while (0)

/// toggle a pin
#define _TOGGLE(IO)  do {gpio_toggle_bit(PIN_MAP[IO].gpio_device, PIN_MAP[IO].gpio_bit); } while (0)

/// set pin as input
#define _SET_INPUT(IO) do {gpio_set_mode(PIN_MAP[IO].gpio_device, PIN_MAP[IO].gpio_bit, GPIO_INPUT_FLOATING); } while (0)
/// set pin as output
#define _SET_OUTPUT(IO) do {gpio_set_mode(PIN_MAP[IO].gpio_device, PIN_MAP[IO].gpio_bit, GPIO_OUTPUT_PP); } while (0)

/// check if pin is an input (with )
//#define _GET_INPUT(IO)  ((gpio_get_mode(PIN_MAP[IO].gpio_device, PIN_MAP[IO].gpio_bit)) == INPUT || gpio_get_mode(PIN_MAP[IO].gpio_device, PIN_MAP[IO].gpio_bit)) == GPIO_INPUT_PU || gpio_get_mode(PIN_MAP[IO].gpio_device, PIN_MAP[IO].gpio_bit)) == GPIO_INPUT_PD)
/// check if pin is an output
//#define _GET_OUTPUT(IO)  ((gpio_get_mode(PIN_MAP[IO].gpio_device, PIN_MAP[IO].gpio_bit)) == GPIO_OUTPUT_PP || gpio_get_mode(PIN_MAP[IO].gpio_device, PIN_MAP[IO].gpio_bit)) == GPIO_OUTPUT_OD)

/// check if pin is an timer
//#define _GET_TIMER(IO)  ((DIO ## IO ## _PWM)

//  why double up on these macros? see http://gcc.gnu.org/onlinedocs/cpp/Stringification.html

/// Read a pin wrapper
#define READ(IO)  _READ(IO)
/// Write to a pin wrapper
#define WRITE(IO, v)  _WRITE(IO, v)

/// toggle a pin wrapper
#define TOGGLE(IO)  _TOGGLE(IO)

/// set pin as input wrapper
#define SET_INPUT(IO)  _SET_INPUT(IO)
/// set pin as output wrapper
#define SET_OUTPUT(IO)  _SET_OUTPUT(IO)

/// check if pin is an input wrapper
//#define GET_INPUT(IO)  _GET_INPUT(IO)
/// check if pin is an output wrapper
//#define GET_OUTPUT(IO)  _GET_OUTPUT(IO)

/// check if pin is an timer wrapper
//#define GET_TIMER(IO)  _GET_TIMER(IO)

// Shorthand
#define OUT_WRITE(IO, v) { SET_OUTPUT(IO); WRITE(IO, v); }

/**
  ports and functions

  added as necessary or if I feel like it- not a comprehensive list!
*/

//Matthias: REWORK THAT SHIT

#if defined(_BOARDS_GENERIC_STM32F103V_H_)
/*
  // UART
  #define RXD         DIO0
  #define TXD         DIO1

  // SPI
  #define SCK         DIO52
  #define MISO        DIO50
  #define MOSI        DIO51
  #define SS          DIO53

  // TWI (I2C)
  #define SCL         DIO21
  #define SDA         DIO20

  // timers and PWM
  #define OC0A        DIO13
  #define OC0B        DIO4
  #define OC1A        DIO11
  #define OC1B        DIO12
  #define OC2A        DIO10
  #define OC2B        DIO9
  #define OC3A        DIO5
  #define OC3B        DIO2
  #define OC3C        DIO3
  #define OC4A        DIO6
  #define OC4B        DIO7
  #define OC4C        DIO8
  #define OC5A        DIO46
  #define OC5B        DIO45
  #define OC5C        DIO44

  // change for your board
  #define DEBUG_LED   DIO21
	*/
  /**
  pins
  */
  #define DIO0_PIN    PE2

  #define DIO1_PIN    PE3

  #define DIO2_PIN    PE4

  #define DIO3_PIN    PE5

  #define DIO4_PIN    PE6

  #define DIO5_PIN    PC0

  #define DIO6_PIN    PC1

  #define DIO7_PIN    PC2

  #define DIO8_PIN    PC3

  #define DIO9_PIN    PA1

  #define DIO10_PIN   PA2

  #define DIO11_PIN   PA3
  
  #define DIO12_PIN   PA4
  
  #define DIO13_PIN   PA5
  
  #define DIO14_PIN   PA6
  
  #define DIO15_PIN   PA7
  
  #define DIO16_PIN   PC4
  
  #define DIO17_PIN   PC5
  
  #define DIO18_PIN   PB0
  
  #define DIO19_PIN   PB1
  
  #define DIO20_PIN   PB2
  
  #define DIO21_PIN   PE7
  
  #define DIO22_PIN   PE8
  
  #define DIO23_PIN   PE9
  
  #define DIO24_PIN   PE10
  
  #define DIO25_PIN   PE11
  
  #define DIO26_PIN   PE12
  
  #define DIO27_PIN   PE13
  
  #define DIO28_PIN   PE14
  
  #define DIO29_PIN   PE15
  
  #define DIO30_PIN   PB10
  
  #define DIO31_PIN   PB11
  
  #define DIO32_PIN   PB12
  
  #define DIO33_PIN   PB13
  
  #define DIO34_PIN   PB14
  
  #define DIO35_PIN   PB15
  
  #define DIO36_PIN   PD8
  
  #define DIO37_PIN   PD9
  
  #define DIO38_PIN   PD10
  
  #define DIO39_PIN   PD11
  
  #define DIO40_PIN   PD12
  
  #define DIO41_PIN   PD13
  
  #define DIO42_PIN   PD14
  
  #define DIO43_PIN   PD15
  
  #define DIO44_PIN   PC6
  
  #define DIO45_PIN   PC7
  
  #define DIO46_PIN   PC8
  
  #define DIO47_PIN   PC9
  
  #define DIO48_PIN   PA8
  
  #define DIO49_PIN   PA9
  
  #define DIO50_PIN   PA10
  
  #define DIO51_PIN   PA11
  
  #define DIO52_PIN   PA12
  
  #define DIO53_PIN   PA13
  
  #define DIO54_PIN   PA14
  
  #define DIO55_PIN   PA15
  
  #define DIO56_PIN   PC10
  
  #define DIO57_PIN   PC11
  
  #define DIO58_PIN   PC12
  
  #define DIO59_PIN   PD0
  
  #define DIO60_PIN   PD1
  
  #define DIO61_PIN   PD2
  
  #define DIO62_PIN   PD3
  
  #define DIO63_PIN   PD4
  
  #define DIO64_PIN   PD5
  
  #define DIO65_PIN   PD6
  
  #define DIO66_PIN   PD7
  
  #define DIO67_PIN   PB3
  
  #define DIO68_PIN   PB4
  
  #define DIO69_PIN   PB5
  
  #define DIO70_PIN   PB6
  
  #define DIO71_PIN   PB7
  
  #define DIO72_PIN   PB8
  
  #define DIO73_PIN   PB9
  
  #define DIO74_PIN   PE0
  
  #define DIO75_PIN   PE1

#endif

#ifndef DIO0_PIN
  #error "pins for this chip not defined in arduino.h! If you write an appropriate pin definition and have this firmware work on your chip, please submit a pull request"
#endif

#endif /* _FASTIO_ARDUINO_H */
