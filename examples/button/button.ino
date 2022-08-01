#include<Ar_button.h>

#define BTN_1 4

Button_t btn;

void fnc_pressed()
{
    Serial.println("Pressed");
}

void setup()
{
    Serial.begin(9600);
    init_button(&btn, BTN_1);
    set_button_pressed_cb(&btn, fnc_pressed)
}

void loop()
{
    read_button(&btn);
}