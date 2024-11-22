// https://github.com/qmk/qmk_firmware/blob/master/docs/i2c_driver.md
// Enable I2C, for using OLED.

#pragma once

#define HAL_USE_I2C TRUE

#include_next <halconf.h>
