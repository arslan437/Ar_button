#include<Ar_button.h>

#define BTN_1 4

Button_t btn;
int count = 0;

void fnc_pressed()
{
    count++;
    Serial.println("count:"+String(count));
}

void fnc_released(unsigned long mil, unsigned long tim )
{
    Serial.println("Released");
}

void setup()
{
    Serial.begin(9600);
    init_button(&btn, BTN_1);
    set_button_pressed_cb(&btn, fnc_pressed);
    set_button_released_cb(&btn, fnc_released);
}

void loop()
{
    read_button(&btn);
}