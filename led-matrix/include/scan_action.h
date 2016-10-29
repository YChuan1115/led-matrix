#ifndef SCAN_ACTION_H
#define SCAN_ACTION_H

#include<led_matrix.h>

/*
 * SCAN ACTION
 * this part implemented by the scan_action.c
 * */

void scan_led_mat_0bit_32x32(LED_matrix * led);
void scan_led_mat_1bit_32x32(LED_matrix * led);
void scan_led_mat_2bit_32x32(LED_matrix * led);
void scan_led_mat_3bit_32x32(LED_matrix * led);
void scan_led_mat_4bit_32x32(LED_matrix * led);
void scan_led_mat_5bit_32x32(LED_matrix * led);
void scan_led_mat_6bit_32x32(LED_matrix * led);
void scan_led_mat_7bit_32x32(LED_matrix * led);

void scan_led_mat_for_microsec(LED_matrix * led, uint16_t micro_second,Scan_action_ptr scan_act );

#endif
