#include <Arduino.h>
#include <ESP32Servo.h>

Servo servo1;
Servo servo2;

void setup() 
{
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);

  servo1.setPeriodHertz(50);
  servo2.setPeriodHertz(50);

  servo1.attach(13, 500, 2400); 
  servo2.attach(12, 500, 2400); 
}

void loop() 
{
  for (int angle = 0; angle <= 180; angle++) 
  {
    servo1.write(angle);
    servo2.write(angle);
    delay(10);
  }

  for (int angle = 180; angle >= 0; angle--) 
  {
    servo1.write(angle);
    servo2.write(angle);
    delay(10);
  }
}