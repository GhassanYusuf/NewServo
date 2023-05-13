#ifndef NewServo_h
#define NewServo_h

// Our Dependant Library
#include <Servo.h>
#include <Arduino.h>

// Our New Servo Class
class NewServo {

  private:

    // Private Variables
    uint8_t _pin        = 2;      // Pin Number
    uint8_t _init_pos   = 0;      // Initial Position
    uint8_t _max_pos    = 255;    // Stop Position
    uint8_t _min_pos    = 0;      // Start Position
    uint8_t _prv_pos    = 0;      // History

    // Working With It
    Servo               _servo;   // Servo Object

    // Function To Check Before Writing
    uint8_t verify(uint8_t input);

  public:

    // Initialize With No Pin
    NewServo();

    // Initialize With Pin Definition
    NewServo(uint8_t pin);

    // Begin Operation
    void begin();

    // Setting The Pin
    void setPin(uint8_t pin);

    // Set Min Position Limit
    void setMin(uint8_t start);

    // Set Max Position Limit
    void setMax(uint8_t stop);

    // Set Initial Position
    void setInit(uint8_t init);

    // Go To Start Position
    void goMax();

    // Go To Stop Position
    void goMin();

    // Go To Initial Position
    void goInit();

    // Command By Serial
    void command(Stream &serial);

    // Move With Specific Position Between Limits
    void move(uint8_t pos);

    // Percentage
    void percent(uint8_t pos);

    // Sweep Function
    void sweep(uint8_t start, uint8_t stop, unsigned int mDelay);

    // Over Ride Limits
    void override(uint8_t pos);

};

#endif
