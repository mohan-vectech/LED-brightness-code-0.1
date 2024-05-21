#include <Arduino.h>
#include <Ticker.h>

#define topLights 36 // Ensure this pin supports PWM on your specific board
#define bottomLights 37

Ticker timer;

volatile int topPwm = 0;
volatile int bottomPwm = 0;
volatile int topBrightness = 0;
volatile int bottomBrightness = 0;
volatile int step = 5; // 5% brightness change
bool stopFlag = true;

void doTask()
{
    // Placeholder for any task you want to perform
    Serial.print("Top Brightness: ");
    Serial.println(topBrightness);
    Serial.print("Bottom Brightness: ");
    Serial.println(bottomBrightness);
    //   To-Do: Capture code.
    Serial.println("Take capture");
}

void updatePWM()
{
    if (stopFlag)
    {
        topPwm = map(topBrightness, 0, 100, 0, 255);
        bottomPwm = map(bottomBrightness, 0, 100, 0, 255);
        analogWrite(topLights, topPwm); // Write PWM value to the LED pin
        analogWrite(bottomLights, bottomPwm);
        doTask();

        // Check if we reached the max or min value and reverse the direction
        if (topBrightness >= 100 || topBrightness <= 0)
        {
            if (topBrightness >= 100)
            {
                topBrightness = 100; // Ensure it doesn't go beyond 255
            }
            else if (topBrightness <= 0)
            {
                topBrightness = 0; // Ensure it doesn't go below 0
                Serial.println("Reached minimum brightness. Increasing now.");
            }
        }

        topBrightness += step; // Increment or decrement the pwm value
        if (topBrightness > 100)
        {
            topBrightness = 100; // Cap the value to 255
            bottomBrightness = bottomBrightness + 5;
            topBrightness = 0;
        }
        if (topBrightness < 0)
        {
            topBrightness = 0; // Cap the value to 0
        }
        if (bottomBrightness > 100)
        {
            bottomBrightness = 100;
            stopFlag = false;
        }
    }
    // Simulate doing a task here, which happens every 50ms with the interrupt
}

void setup()
{
    pinMode(topLights, OUTPUT);
    Serial.begin(115200);

    timer.attach(1, updatePWM); // Call updatePWM every 1
}

void loop()
{
    // The main loop can be used for other tasks
}
