#include <Arduino.h>

#define topLights 13  // Ensure this pin supports PWM on your specific board
#define bottomLights 14

int topBrightness = 60;  // Brightness percentage (0-100)
int bottomBrightness = 60;  // Brightness percentage (0-100)

int topPwm, bottomPwm;

void setup() {
    Serial.begin(115200);

    // Map brightness percentage to duty cycle value with higher resolution
    topPwm = map(topBrightness, 0, 100, 0, 63); // 12-bit resolution
    bottomPwm = map(bottomBrightness, 0, 100, 0, 63 ); // 12-bit resolution

    Serial.print("Top PWM: ");
    Serial.println(topPwm);
    Serial.print("Bottom PWM: ");
    Serial.println(bottomPwm);

    // Configure the topLights pin for PWM with 12-bit resolution
    ledcSetup(0, 10000, 6);  // Channel 0, 10 kHz frequency, 12-bit resolution
    ledcAttachPin(topLights, 0);  // Attach topLights pin to channel 0
    ledcWrite(0, topPwm);  // Set duty cycle for topLights

    // Configure the bottomLights pin for PWM with 12-bit resolution
    ledcSetup(1, 10000, 6);  // Channel 1, 10 kHz frequency, 12-bit resolution
    ledcAttachPin(bottomLights, 1);  // Attach bottomLights pin to channel 1
    ledcWrite(1, bottomPwm);  // Set duty cycle for bottomLights
}

void loop() {
    // The main loop can be used for other tasks
}
