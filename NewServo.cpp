#include <Servo.h>
#include "NewServo.h"

// Initialize With No Pin
NewServo::NewServo() {}

// Initialize With Pin Definition
NewServo::NewServo(uint8_t pin) {
    _pin = pin;
}

// Begin Operation
void NewServo::begin() {
    _servo.attach(_pin);
}

// Setting The Pin
void NewServo::setPin(uint8_t pin) {
    _pin = pin;
}

// Set Min Position Limit
void NewServo::setMin(uint8_t start) {
    _min_pos = start;
}

// Set Max Position Limit
void NewServo::setMax(uint8_t stop) {
    _max_pos = stop;
}

// Set Initial Position
void NewServo::setInit(uint8_t init) {
    _init_pos = init;
}

// Go To Start Position
void NewServo::goMax() {
    _servo.write(_min_pos);
}

// Go To Stop Position
void NewServo::goMin() {
    _servo.write(_max_pos);
}

// Go To Initial Position
void NewServo::goInit() {
    _servo.write(_init_pos);
}

// Command By Serial
void NewServo::command(Stream &serial) {

    // Print A Message
    serial.print("Please Enter Your Position Value : ");

    // Wait For User Input
    while(!serial.available()) {}

    // Read The Value Convert To Number
    if(serial.available()) {
    String x = serial.readStringUntil('\n');
    while(serial.available()) {
        serial.read();
    }
    serial.println();
    x.trim();
    serial.println(x);
    _servo.write(x.toInt());
    }
    
}

// Move With Specific Position Between Limits
void NewServo::move(uint8_t pos) {
    pos = constrain(pos, _min_pos, _max_pos);
    _servo.write(pos);
}

// Percentage
void NewServo::percent(uint8_t pos) {
    pos = map(pos, 0, 100, _min_pos, _max_pos);
    _servo.write(pos);
}

// Sweep Function
void NewServo::sweep(uint8_t start, uint8_t stop, unsigned int mDelay) {
    if(start < stop) {
    for(int i=start; i<stop; i++) {
        move(i);
        delay(mDelay);
    }
    } else if(start > stop) {
    for(int i=start; i>stop; i--) {
        move(i);
        delay(mDelay);
    }
    }
}

// Over Ride Limits
void NewServo::override(uint8_t pos) {
    _servo.write(pos);
}

// Verify
uint8_t NewServo::verify(uint8_t input) {
    if(input != _prv_pos) {
        _prv_pos = input;
        return input;
    }
}