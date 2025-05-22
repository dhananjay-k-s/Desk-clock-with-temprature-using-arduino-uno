# Desk Clock with Temperature and Humidity Display

A versatile Arduino-based desk clock project that displays time, date, temperature, and humidity using a 16x2 LCD display, DHT11 sensor, and DS3231 RTC module.

## Features

- Real-time clock display (24-hour format)
- Temperature display in Celsius
- Humidity percentage display
- Day of the week display
- Date display
- Automatic display cycling between different information
- LCD backlight support
- I2C interface for LCD

## Hardware Requirements

- Arduino UNO
- 16x2 LCD Display with I2C adapter (0x27 address)
- DHT11 Temperature and Humidity Sensor
- DS3231 Real Time Clock Module
- Connecting wires

## Pin Configuration

- DHT11 Sensor: Pin 2
- DS3231 RTC: Pins 6, 7 (for communication)
- LCD Display: Connected via I2C (SDA, SCL)

## Required Libraries

1. [New Liquid Crystal Library](https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home)
2. [Liquid Crystal I2C Library](https://www.arduinolibraries.info/libraries/liquid-crystal-i2-c)
3. [Adafruit DHT Library](https://github.com/adafruit/DHT-sensor-library)
4. [DS3231 Library](http://www.rinkydinkelectronics.com/library.php?id=73)

## Display Features

The display cycles through different information modes:
1. Time with Temperature
2. Day of Week
3. Date with Month
4. Time Only (for 5 seconds)
5. Temperature Reading
6. Humidity Reading

Each display mode shows for 5 seconds before cycling to the next.

## Images

<div>
  <img  src = "https://github.com/dhananjay-k-s/Desk-clock-with-temprature-using-arduino-uno/blob/main/Pictures/PXL_20250522_161103139.jpg" height = 600 />
<img  src = "https://github.com/dhananjay-k-s/Desk-clock-with-temprature-using-arduino-uno/blob/main/Pictures/79275674-e129-4a58-8c9b-b76dd68ac1c0~1.jpg" height = 600 />

</div>

## Circuit Diagram
 
<div>
  <img  src = "https://github.com/dhananjay-k-s/Desk-clock-with-temprature-using-arduino-uno/blob/main/Pictures/IMG-20250517-WA0000.jpg" height = 600 />

</div>

## Installation

1. Install all required libraries in Arduino IDE
2. Connect the hardware components according to the pin configuration
3. Upload the code to Arduino UNO
4. (Optional) Uncomment and modify the time setting code in setup() to set current time

## Setting the Time

To set the time, uncomment these lines in the setup() function and modify as needed:
```cpp
//rtc.setDOW(SATURDAY);     // Set Day-of-Week
//rtc.setTime(22,55, 0);    // Set the time (24hr format)
//rtc.setDate(17, 5, 2025); // Set the date
```

## Notes

- Temperature is displayed in Celsius
- The LCD display uses I2C communication with address 0x27
- The display includes automatic clearing of the second line to prevent text overlap
- Day of Week is displayed in uppercase

## License

See the [LICENSE](LICENSE) file for details.

## Contributing

Feel free to submit issues and enhancement requests!
