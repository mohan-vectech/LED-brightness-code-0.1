#include <Arduino.h>

#define led 10

void setup(){
  pinMode(led,OUTPUT);
  Serial.begin(115200);
}

void loop(){
  for (int pwm =0;pwm++;pwm<255){
    analogWrite(led,pwm);
    delay(50);
  }

  for (int pwm = 255;pwm--;pwm>0){
    analogWrite(led,pwm);
    delay(50);
  }
}