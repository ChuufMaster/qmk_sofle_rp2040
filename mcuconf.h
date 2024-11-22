// https://github.com/qmk/qmk_firmware/blob/master/docs/platformdev_rp2040.md
// RP2040 has 2 I2C peripherals, enable the one with GPIO pins wired for OLED SDA & SCL pins.

#pragma once

#include_next <mcuconf.h>

// Disable I2C0 peripheral.
#undef RP_I2C_USE_I2C0
#define RP_I2C_USE_I2C0 FALSE
// #define RP_I2C_USE_I2C0 TRUE

// Enable I2C1 peripheral, because its GP2 & GP3 pins are wired for OLED SDA & SCL pins.
#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 TRUE
