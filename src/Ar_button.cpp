#include "Ar_button.h"

// ptr_release_cb ptr_call = NULL;

void init_button(Button_t *btn, uint8_t _pin)
{
  btn->pin = _pin;
  btn->tim = millis();
  btn->ptr_pressed_cb = NULL;
  btn->ptr_release_cb = NULL;
  btn->md = 0;
  pinMode(btn->pin, INPUT_PULLUP);
}

void read_button(Button_t *btn)
{
  if (millis() < btn->tim)
    btn->tim = millis();
  switch (btn->md)
  {
  case 0:
    if (!digitalRead(btn->pin) && millis() - btn->tim >= DEBOUNCE_TIME)
    {
      btn->md = 1;
      btn->tim = millis();
      if (btn->ptr_pressed_cb != NULL)
      {
        btn->ptr_pressed_cb();
      }
    }
    else if (digitalRead(btn->pin))
    {
      btn->tim = millis();
    }
    break;
  case 1:
    if (digitalRead(btn->pin))
    {
      if (btn->ptr_release_cb != NULL)
      {
        btn->ptr_release_cb(millis() - (btn->tim - 30), btn->tim);
      }
      btn->md = 0;
    }
    else if (!digitalRead(btn->pin))
    {
      if (btn->ptr_hold_cb != NULL)
        btn->ptr_hold_cb(millis() - btn->tim);
    }
    break;

  default:
    break;
  }
}

void set_button_released_cb(Button_t *btn, void (*cb)(unsigned long, unsigned long))
{
  btn->ptr_release_cb = cb;
}

void set_button_pressed_cb(Button_t *btn, void (*cb)())
{
  btn->ptr_pressed_cb = cb;
}

void set_button_hold_cb(Button_t *btn, void (*cb)(unsigned long))
{
  btn->ptr_hold_cb = cb;
}