  #include <Servo.h>
  #include "NewServo.h"
  
  NewServo ExampleServo(3);
  
  void setup() {

    // Serial Communication
    Serial.begin(9600);
    
    // By Setting The Bounderies Of Servo Movment, The Servo Will Not Move Out Of This Bounderies
    ExampleServo.setMin(15);    // The Servo Min Position Is Going To Be 15
    ExampleServo.setMax(148);   // The Servo Max Position In Goint To Be 148
    ExampleServo.setInit(90);   // The Servo Initial Position
    // Therefore the 0% position have value of 15 and 100% have a value of 148

    // Starting The Servo Activity
    ExampleServo.begin();

    // Go To Initial Position
    ExampleServo.goInit();
    
  }
  
  void loop() {

    ExampleServo.goMin();
    delay(1000);
    ExampleServo.goMax();
    delay(1000);
    ExampleServo.goInit();
    delay(1000);
    ExampleServo.move(40);
    delay(1000);
    ExampleServo.percent(80);
    delay(1000);
    ExampleServo.move(40);
    delay(1000);
    ExampleServo.sweep(32, 65, 10);
    delay(1000);
    ExampleServo.sweep(65, 32, 10);
    delay(1000);
    ExampleServo.override(255);
    
  }
