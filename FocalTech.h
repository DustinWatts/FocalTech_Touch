/*!
 * FocalTech.h
 */

#ifndef FocalTech_H
#define FocalTech_H

#include <Arduino.h>
#include <Wire.h>

// FocalTech I2C Address
#define FT_ADDR 0x38            // I2C address

// Register addresses
#define FT_REG_NUMTOUCHES 0x02  // Number of touch points
#define FT_REG_MODE 0x00        // Device mode, either WORKING or FACTORY
#define FT_REG_CALIBRATE 0x02   // Calibrate mode
#define FT_REG_WORKMODE 0x00    // Work mode
#define FT_REG_FACTORYMODE 0x40 // Factory mode
#define FT_REG_THRESHHOLD 0x80  // Threshold for touch detection
#define FT_REG_POINTRATE 0x88   // Point rate
#define FT_REG_FIRMVERS 0xA6    // Firmware version
#define FT_REG_CHIPID 0xA3      // Chip selecting
#define FT_REG_VENDID 0xA8      // FocalTech's panel ID

// FocalTech ID's
#define FT6234_VENVID 0x79  // FocalTech's panel ID
#define FT6236_VENDID 0x11  // FocalTech's panel ID
#define FT5436_VENDID 0x79  // FocalTech's panel ID
#define FT6206_CHIPID 0x06  // FT6206 ID
#define FT6234_CHIPID 0x54  // FT6234 ID
#define FT6236_CHIPID 0x36  // FT6236 ID
#define FT5436_CHIPID 0x54  // FT5436 ID
#define FT6236U_CHIPID 0x64 // FT6236U ID

#define FT_DEFAULT_THRESHOLD 128 // Default threshold for touch detection

class TS_Point
{
public:
  TS_Point(void);
  TS_Point(int16_t x, int16_t y, int16_t z, uint16_t width = 480, uint16_t height = 320, uint8_t rotation = 0);

  bool operator==(TS_Point);
  bool operator!=(TS_Point);

  int16_t x;
  int16_t y;
  int16_t z;
};

class FocalTech
{
public:
  FocalTech(uint16_t width = 480, uint16_t height = 320);
  void debug(void);
  boolean begin(uint8_t thresh = FT_DEFAULT_THRESHOLD, int8_t sda = -1, int8_t scl = -1);
  uint8_t touched(void);
  TS_Point getPoint(uint8_t n = 0);
// Helper functions to make the touch display aware
	void setRotation(uint8_t rotation);

private:
  void writeRegister8(uint8_t reg, uint8_t val);
  uint8_t readRegister8(uint8_t reg);

  void readData(void);
  uint8_t touches;
  uint16_t touchX[2], touchY[2], touchID[2];
// Make touch rotation aware:
	uint8_t _rotation = 0;
	uint16_t _touch_width = 0;
	uint16_t _touch_height = 0;
};

#endif
