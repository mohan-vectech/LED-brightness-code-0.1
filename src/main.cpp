#include <Arduino.h>
#include <Ticker.h>

#define led 36 // Ensure this pin supports PWM on your specific board

volatile int pwmValue = 0;
volatile int step = 13; // 5% of 255 is approximately 13

Ticker timer;

void doTask()
{
    // Placeholder for any task you want to perform
    Serial.print("Brightness: ");
    int brightness = map(pwmValue, 0, 255, 0, 100);
    Serial.println(brightness);
    //   To-Do: Capture code.
    Serial.println("Take capture");
}

void updatePWM()
{
    analogWrite(led, pwmValue); // Write PWM value to the LED pin
    doTask();

    // Check if we reached the max or min value and reverse the direction
    if (pwmValue >= 255 || pwmValue <= 0)
    {
        step = -step;
        if (pwmValue >= 255)
        {
            pwmValue = 255; // Ensure it doesn't go beyond 255
            Serial.println("Reached maximum brightness. Decreasing now.");
        }
        else if (pwmValue <= 0)
        {
            pwmValue = 0; // Ensure it doesn't go below 0
            Serial.println("Reached minimum brightness. Increasing now.");
        }
    }

    pwmValue += step; // Increment or decrement the pwm value
    if (pwmValue > 255)
        pwmValue = 255; // Cap the value to 255
    if (pwmValue < 0)
        pwmValue = 0; // Cap the value to 0

    // Simulate doing a task here, which happens every 50ms with the interrupt
}

void setup()
{
    pinMode(led, OUTPUT);
    Serial.begin(115200);

    // Configure LED PWM functionality
    ledcSetup(0, 5000, 8); // Channel 0, 5 kHz, 8-bit resolution
    ledcAttachPin(led, 0); // Attach the LED pin to channel 0

    timer.attach(1, updatePWM); // Call updatePWM every 1
}

void loop()
{
    // The main loop can be used for other tasks
}
