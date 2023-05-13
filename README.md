NewServo Library
================

* Author: [GhassanYusuf](https://github.com/GhassanYusuf)
* Copyright (C) 2022.
* Released under the MIT license.

The NewServo Library provides a simple and easy-to-use API for controlling servo motors with Arduino boards. It is built on top of the Servo library and allows you to easily set the position of one or more servo motors within the range of the minimum and maximum position limits, without having to worry about the low-level details of pulse width modulation (PWM) signals.

Features
--------

* Simple and easy-to-use API.
* Supports multiple servo motors.
* Allows you to set the position of each servo motor within the range of the minimum and maximum position limits.
* Automatically handles PWM signals and timing.
* Allows you to set minimum, maximum, and initial position limits.
* Provides a command-line interface for controlling the servo motor using the serial port.

Installation
------------

To use the NewServo Library, follow these steps:

1. Download the ZIP archive (https://github.com/GhassanYusuf/NewServo/releases).
2. Open the Arduino IDE and choose Sketch > Include Library > Add .ZIP Library... and select the downloaded file.
3. Create a new sketch in the Arduino IDE and import the library by adding the following line at the top of your sketch:

   ``````````c++
   #include <NewServo.h>
   ```

   This will also include the Servo library, which is a dependency.

Usage
-----

To use the NewServo Library, follow these steps:

1. Create a NewServo object for each servo motor you want to control, like this:

   ````c++
   NewServo myservo(9);
   ```

   This sets up the servo motor on pin 9, and initializes it to its default position.

2. Set the position of the servo motor within the range of the minimum and maximum position limits by calling the `move()` function, like this:

   ````c++
   myservo.move(90);
   ```

   This sets the servo motor to the 90-degree position, which is within the range of the minimum and maximum position limits.

3. Set the minimum, maximum, and initial position limits by calling the `setMin()`, `setMax()`, and `setInit()` functions, respectively, like this:

   ````c++
   myservo.setMin(0);
   myservo.setMax(180);
   myservo.setInit(90);
   ```

   This sets the minimum position limit to 0 degrees, the maximum position limit to 180 degrees, and the initial position to 90 degrees.

4. Use the `goMax()`, `goMin()`, and `goInit()` functions to move the servo motor to the minimum, maximum, and initial positions, respectively, like this:

   ````c++
   myservo.goMax();
   myservo.goMin();
   myservo.goInit();
   ```

5. Use the `sweep()` function to sweep the servo motor back and forth between two positions, like this:

   ````c++
   myservo.sweep(0, 180, 50); // sweep back and forth between 0 and 180 degrees with a delay of 50 milliseconds between each position
   ```

6. Use the `override()` function to move the servo motor to a specific position, without regard to the minimum and maximum position limits, like this:

   ````c++
   myservo.override(45); // move the servo motor to the 45-degree position, regardless of the limits set by setMin() and setMax()
   ```

7. Use the `command()` function to control the servo motor using the serial port, like this:

   ````c++
   myservo.command(Serial); // wait for user input on the serial port, and move the servo motor to the specified position
   ```

Documentation
-------------

The NewServo Library provides the following functions:

**`NewServo()`**
Initialize with no pin.

**`NewServo(pin)`**
Initialize with pin definition.

**`begin()`**
Begin operation.

**`setPin(pin)`**
Set the pin.

**`setMin(start)`**
Set the minimum position limit.

**`setMax(stop)`**
Set the maximum position limit.

**`setInit(init)`**
Set the initial position.

**`goMax()`**
Go to the start position.

**`goMin()`**
Go to the stop position.

**`goInit()`**
Go to the initial position.

**`command(serial)`**
Command by serial.

**`move(pos)`**
Move to a specific position within the range of the minimum and maximum position limits.

**`sweep(start, stop, mDelay)`**
Sweep function.

**`override(pos)`**
Override limits.

**`verify(input)`**
Verify.

License
-------

Copyright (c) 2022.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
