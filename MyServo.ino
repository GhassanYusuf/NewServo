  #include <Servo.h>
  #include "NewServo.h"
  
  NewServo test(3);
  
  void setup() {
  
    Serial.begin(9600);
    test.setMin(15);
    test.setMax(148);
//    test.setMin(5);
//    test.setMax(133);
    test.begin();
    
  }
  
  void loop() {

//    test.command();

    while(Serial.available()) {
      dispense(command());
    }
  
  }

  // Asking The Count
  int command() {
    if(Serial.available()) {
      String x = Serial.readStringUntil('\n');
      while(Serial.available()) {
        Serial.read();
      }
      x.trim();
      return x.toInt();
    }
  }

  // Dispensing Function
  void dispense(uint8_t times) {
    for(int i=0; i<times; i++) {
      test.goMin();
      delay(500);
      test.goMax();
      delay(1000);
    }
  }
