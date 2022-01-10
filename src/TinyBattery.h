/*
TinyBattery.h - Ligth Library for Arduino Environment to Battery management.
v0.2

Copyright © 2021 Francisco Rafael Reyes Carmona.
All rights reserved.

rafael.reyes.carmona@gmail.com


  This file is part of TinyBattery Library.

  TinyBattery Library is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  TinyBattery Library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with TinyBattery Library.  If not, see <https://www.gnu.org/licenses/>.

*/

/**
 * Ligth Library for Arduino Enveroment to Battery management.
 */


#ifndef TinyBattery_h
#define TinyBattery_h

#include "Arduino.h"

class TinyBattery {
  private:
    #if defined(__LGT8F__)
      int _ADC_MAX = 4096;  //ADC max. value (4095) + 1 -> 4096. But it will be 4069 by design.
    #elif defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || defined(__AVR_ATmega328__)
      int _ADC_MAX = 1024;  //ADC max. value (1023) + 1 -> 1024.
    #else
      int _ADC_MAX = 1024;  //ADC max. value (1023) + 1 -> 1024.
    #endif
    float _VREF;
    byte _PIN;
    float _FACTOR;
    float _MIN_V;
    float _MAX_V;

  public:
    TinyBattery(byte, float, long, long, float, float);
    TinyBattery(byte, float, float, float, float);
    TinyBattery() = delete;
    TinyBattery(const TinyBattery&) = delete;

    byte GetChargeLevel();
    float GetVoltage();
    float GetVoltage_LowNoise();

    void setADC(int);
    void analogRef(uint8_t mode);
    void setVref(float Vref){_VREF = Vref;};

};

#endif
