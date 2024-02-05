//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2024-02-04
// PURPOSE: unit tests for the CHT8310 temperature and humidity sensor
//          https://github.com/RobTillaart/CHT8310
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)


#include <ArduinoUnitTests.h>

#include "DS3232.h"


unittest_setup()
{
  fprintf(stderr, "DS3232_LIB_VERSION: %s\n", (char *) DS3232_LIB_VERSION);
}


unittest_teardown()
{
}


unittest(test_constants)
{
  assertEqual(0x40, CHT8310_DEFAULT_ADDRESS);
  
  // #define DS3232_OK                  0
// #define DS3232_ERROR_ADDR          -10
// #define DS3232_ERROR_I2C           -11
// #define DS3232_ERROR_CONNECT       -12
}


unittest_main()


//  -- END OF FILE --
