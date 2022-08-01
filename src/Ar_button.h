/*
 *   Auther: Muhammad Arslan
 *   Dated : January 19, 2021
 *   Last Updated: January 19, 2021
 */
#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>
#include <Arduino.h>

/*
 * Debounce time for the buttons
 */
#define DEBOUNCE_TIME 50

typedef struct
{
    uint8_t pin;
    uint8_t md;
    unsigned long tim;
    void (*ptr_release_cb)(unsigned long, unsigned long);
    void (*ptr_hold_cb)(unsigned long);
    void (*ptr_pressed_cb)(void);
} Button_t;

// typedef void (*ptr_release_cb)(uint8_t);

/*
 * Setting the button pin as input pullup and saving the time.
 */
void init_button(Button_t *btn, uint8_t _pin);

/*
 * Reading the button.
 */
void read_button(Button_t *btn);

/*
 * gettting the button call  back function for the user.
 */
void set_button_released_cb(Button_t *btn, void (*cb)(unsigned long, unsigned long));

/*
 * button pressed call back register button.
 */
void set_button_pressed_cb(Button_t *btn, void (*cb)(void));

/*
 * button hold call back function.
 */
void set_button_hold_cb(Button_t *btn, void (*cb)(unsigned long));

#endif