#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<led_matrix.h>


int create_led_mat(LED_matrix * led ,uint16_t x_size, uint16_t y_size, LEDpin * pin_set)
{

	led->x_size = x_size;
	led->y_size = y_size;
	// START: alloc memory space for the matrix;
	led->RGB_mat = malloc_pixel_mat_2D(x_size,y_size);
	if(led->RGB_mat == NULL) return -1;
	// END: alloc memory space for the matrix;

	if(pin_set == NULL)
	{
		led->pin_set.A = LED_A;
		led->pin_set.B = LED_B;
		led->pin_set.C = LED_C;
		led->pin_set.D = LED_D;
		led->pin_set.R1 = LED_DR1;
		led->pin_set.R2 = LED_DR2;
		led->pin_set.G1 = 0;
		led->pin_set.G2 = 0;
		led->pin_set.B1 = LED_DB1;
		led->pin_set.B2 = LED_DB2;
		led->pin_set.CLK = LED_CLK;
		led->pin_set.LAT = LED_LAT;
		led->pin_set.OE  = LED_OE;
	}else{
		led->pin_set.A = pin_set->A;
		led->pin_set.B = pin_set->B;
		led->pin_set.C = pin_set->C;
		led->pin_set.D = pin_set->D;
		led->pin_set.R1 = pin_set->R1;
		led->pin_set.G1 = pin_set->G1;
		led->pin_set.B1 = pin_set->B1;
		led->pin_set.R2 = pin_set->R2;
		led->pin_set.G2 = pin_set->G2;
		led->pin_set.B2 = pin_set->B2;
		led->pin_set.CLK = pin_set->CLK;
		led->pin_set.LAT = pin_set->LAT;
		led->pin_set.OE = pin_set->OE;
	}


}


void init_led_mat(LED_matrix * led)
{

	GPIO_INIT();

	// set all pin input
	GPIO_SET_INPUT(led->pin_set.R1);
	GPIO_SET_INPUT(led->pin_set.R2);
	GPIO_SET_INPUT(led->pin_set.B1);
	GPIO_SET_INPUT(led->pin_set.B2);
	GPIO_SET_INPUT(led->pin_set.A);
	GPIO_SET_INPUT(led->pin_set.B);
	GPIO_SET_INPUT(led->pin_set.C);
	GPIO_SET_INPUT(led->pin_set.D);
	GPIO_SET_INPUT(led->pin_set.CLK);
	GPIO_SET_INPUT(led->pin_set.LAT);
	GPIO_SET_INPUT(led->pin_set.OE);

	// set all pin output low
	GPIO_WRITE(led->pin_set.R1 , LOW);
	GPIO_WRITE(led->pin_set.R2 , LOW);
	GPIO_WRITE(led->pin_set.B1 , LOW);
	GPIO_WRITE(led->pin_set.B2 , LOW);
	GPIO_WRITE(led->pin_set.A  , LOW);
	GPIO_WRITE(led->pin_set.B  , LOW);
	GPIO_WRITE(led->pin_set.C  , LOW);
	GPIO_WRITE(led->pin_set.D  , LOW);
	GPIO_WRITE(led->pin_set.CLK, LOW);
	GPIO_WRITE(led->pin_set.LAT, LOW);
	GPIO_WRITE(led->pin_set.OE , LOW);

	// set all pin output
	GPIO_SET_OUTPUT(led->pin_set.R1);
	GPIO_SET_OUTPUT(led->pin_set.R2);
	GPIO_SET_OUTPUT(led->pin_set.B1);
	GPIO_SET_OUTPUT(led->pin_set.B2);
	GPIO_SET_OUTPUT(led->pin_set.A);
	GPIO_SET_OUTPUT(led->pin_set.B);
	GPIO_SET_OUTPUT(led->pin_set.C);
	GPIO_SET_OUTPUT(led->pin_set.D);
	GPIO_SET_OUTPUT(led->pin_set.CLK);
	GPIO_SET_OUTPUT(led->pin_set.LAT);
	GPIO_SET_OUTPUT(led->pin_set.OE);

	// set initialization situation
	GPIO_WRITE(led->pin_set.OE , LOW);
}




void release_led_mat(LED_matrix * led )
{
	int i;
	for( i = 0 ; i < led->y_size ; i++ ){
		free((led->RGB_mat)[i]);
	}
	free(led->RGB_mat);
}



void print_led_mat_content(LED_matrix * led)
{
	int x,y;
	printf("Red pixel in mat:\n");
	for( y = 0 ; y < led->y_size ;y++ ){
		for( x = 0 ; x < led->x_size ;x++ ){
			printf("%02X ", led->RGB_mat[x][y].R);
		}
		printf("\n");
	}
	printf("\n");

	printf("Green pixel in mat:\n");
	for( y = 0 ; y < led->y_size ;y++ ){
		for( x = 0 ; x < led->x_size ;x++ ){
			printf("%02X ", led->RGB_mat[x][y].G);
		}
		printf("\n");
	}
	printf("\n");

	printf("Blue pixel in mat:\n");
	for( y = 0 ; y < led->y_size ;y++ ){
		for( x = 0 ; x < led->x_size ;x++ ){
			printf("%02X ", led->RGB_mat[x][y].B);
		}
		printf("\n");
	}
	printf("\n");

}



void copy_mat_to_R_LED_mat(LED_matrix * led , uint8_t **mat, uint16_t x_start , uint16_t y_start,uint16_t x_len, uint16_t y_len )
{
	copy_mat_to_select_RGB_LED_mat(led,mat,x_start, y_start, x_len, y_len, 'R');
}

void copy_mat_to_G_LED_mat(LED_matrix * led , uint8_t **mat, uint16_t x_start , uint16_t y_start,uint16_t x_len, uint16_t y_len )
{
	copy_mat_to_select_RGB_LED_mat(led,mat,x_start, y_start, x_len, y_len, 'G');
}

void copy_mat_to_B_LED_mat(LED_matrix * led , uint8_t **mat, uint16_t x_start , uint16_t y_start,uint16_t x_len, uint16_t y_len )
{
	copy_mat_to_select_RGB_LED_mat(led,mat,x_start, y_start, x_len, y_len, 'B');
}


void copy_mat_to_select_RGB_LED_mat(LED_matrix * led , uint8_t **mat, uint16_t x_start , uint16_t y_start,uint16_t x_len, uint16_t y_len, char color )
{

	int x_limit = (x_len > led->x_size )?(led->x_size):(x_len);
	int y_limit = (y_len > led->y_size )?(led->y_size):(y_len);

	int x,y;
	for( x = x_start ; x < (x_start + x_limit) ; x++){
		for( y = y_start ; y < (y_start + y_limit) ; y++){
			switch(color){
				case 'R':
					led->RGB_mat[x][y].R = mat[x][y];
					break;
				case 'G':
					led->RGB_mat[x][y].G = mat[x][y];
					break;
				case 'B':
					led->RGB_mat[x][y].B = mat[x][y];
					break;
				default:
					break;
			}
		}
	}
}


pixel ** malloc_pixel_mat_2D(uint16_t x_size, uint16_t y_size)
{
	pixel ** mat;
	int x,y;
	mat = malloc(sizeof(pixel *) * x_size);
	if(mat == NULL) return NULL;
	for(x=0 ;x<x_size ;x++ ){
		mat[x] = malloc(sizeof(pixel) * y_size);
		if(mat[x] == NULL){
			for(x = x - 1 ;x >= 0 ;x-- ){
				free(mat[x]);
			}
			free(mat);
			return NULL;
		}
	}
	return mat;
}
