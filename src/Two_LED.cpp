#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>
//dùng nút ngoài chân 5, led 1 chân 4, led 2 chân 6

LED led1(LED_PIN_1, LED_ACT);
LED led2(LED_PIN_2, LED_ACT);

void Push();
void DoublePush();
void Hold();

OneButton button(BTN_PIN, !BTN_ACT);
int led_select = 1;

void setup()
{
    led1.on();
    led2.off();
    button.attachClick(Push);
    button.attachDoubleClick(DoublePush);
    button.attachLongPressStart(Hold);
}

void loop()
{
    led1.loop();
    led2.loop();
    button.tick();
}

void DoublePush()
{
    if (led_select == 1)
    {
        led_select = 2;
        led1.off();
        led2.on();
    }
    else
    {
        led_select = 1;
        led2.off();
        led1.on();
    }
}

void Push()
{
    if (led_select == 1)
    {
        led1.flip();
    }
    else
    {
        led2.flip();
    }
}

void Hold()
{
    if (led_select == 1)
    {
        led1.blink(200);
    }
    else
    {
        led2.blink(200);
    }
}