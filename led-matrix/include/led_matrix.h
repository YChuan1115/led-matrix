#ifndef LED_MATRIX_H
#define LED_MATRIX_H


#define USE_BCM2835_C_LIB
// #define USE_WIRINGPI_C_LIB

#include<stdint.h>
#include<led_gpio_set.h>
#include<bit_tools.h>



// define the structure of led matrix
//
typedef struct _LEDpin{
	uint8_t A;
	uint8_t B;
	uint8_t C;
	uint8_t D;

	uint8_t R1;
	uint8_t G1;
	uint8_t B1;
	uint8_t R2;
	uint8_t G2;
	uint8_t B2;

	uint8_t CLK;
	uint8_t LAT;
	uint8_t OE;
} LEDpin;


typedef struct _pixel {
	uint8_t R,G,B;
} pixel;

typedef struct _LED_matrix{
	LEDpin pin_set;
	uint16_t x_size;
	uint16_t y_size;
	pixel **RGB_mat;
} LED_matrix;


typedef void (*Scan_action_ptr)(LED_matrix * );

int  create_led_mat (LED_matrix * led ,uint16_t x_size,uint16_t y_size,LEDpin * pin_set);
void init_led_mat(LED_matrix * led);
void release_led_mat(LED_matrix * led );
void print_led_mat_content(LED_matrix * led);

void copy_mat_to_R_LED_mat(LED_matrix * led , uint8_t **mat, uint16_t x_start , uint16_t y_start,uint16_t x_len, uint16_t y_len );
void copy_mat_to_G_LED_mat(LED_matrix * led , uint8_t **mat, uint16_t x_start , uint16_t y_start,uint16_t x_len, uint16_t y_len );
void copy_mat_to_B_LED_mat(LED_matrix * led , uint8_t **mat, uint16_t x_start , uint16_t y_start,uint16_t x_len, uint16_t y_len );
void copy_mat_to_select_RGB_LED_mat(LED_matrix * led , uint8_t **mat, uint16_t x_start , uint16_t y_start,uint16_t x_len, uint16_t y_len, char color );

/*
 * pixel matrix tools
 * */

pixel ** malloc_pixel_mat_2D(uint16_t x_size, uint16_t y_size);

#endif
