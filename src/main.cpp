#include <Arduino.h>


#define topLights 36 // Ensure this pin supports PWM on your specific board
#define bottomLights 37

int topBrightness =30;
int bottomBrightness = 30;

int topPwm, bottomPwm;

void setup()
{
    pinMode(topLights, OUTPUT);
    Serial.begin(115200);

    topPwm = map(topBrightness,0,100,0,255);
    bottomPwm = map(bottomBrightness,0,100,0,255);

    analogWrite(topLights, topPwm); // Write PWM value to the LED pin
    analogWrite(bottomLights, bottomPwm);
}

void loop()
{
    // The main loop can be used for other tasks
}
