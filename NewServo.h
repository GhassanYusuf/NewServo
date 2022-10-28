
  // Our Dependant Class
  #include <Servo.h>

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
      Servo             _servo;                 // Servo Object

      // Function To Check Before Writing
      uint8_t verify(uint8_t input) {
        if(input != _prv_pos) {
          _prv_pos = input;
          return input;
        }
      }

    public:

      // Initialize With No Pin
      NewServo() {}

      // Initialize With Pin Definition
      NewServo(uint8_t pin) {
        _pin = pin;
      }

      // Begin Operation
      void begin() {
        _servo.attach(_pin);
      }

      // Setting The Pin
      void setPin(uint8_t pin) {
        _pin = pin;
      }

      // Set Min Position Limit
      void setMin(uint8_t start) {
        _min_pos = start;
      }

      // Set Max Position Limit
      void setMax(uint8_t stop) {
        _max_pos = stop;
      }

      // Set Initial Position
      void setInit(uint8_t init) {
        _init_pos = init;
      }

      // Go To Start Position
      void goMax() {
        _servo.write(_min_pos);
      }

      // Go To Stop Position
      void goMin() {
        _servo.write(_max_pos);
      }

      // Go To Initial Position
      void goInit() {
        _servo.write(_init_pos);
      }

      // Command By Serial
      void command() {

        // Print A Message
        Serial.print("Please Enter Your Position Value : ");

        // Wait For User Input
        while(!Serial.available()) {}

        // Read The Value Convert To Number
        if(Serial.available()) {
          String x = Serial.readStringUntil('\n');
          while(Serial.available()) {
            Serial.read();
          }
          Serial.println();
          x.trim();
          Serial.println(x);
          _servo.write(x.toInt());
        }
        
      }

      // Move With Specific Position Between Limits
      void move(uint8_t pos) {
        pos = constrain(pos, _min_pos, _max_pos);
        _servo.write(pos);
      }

      // Percentage
      void percent(uint8_t pos) {
        pos = map(pos, 0, 100, _min_pos, _max_pos);
        _servo.write(pos);
      }

      // Sweep Function
      void sweep(uint8_t start, uint8_t stop, unsigned int mDelay) {
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
      void override(uint8_t pos) {
        _servo.write(pos);
      }
  
  };
