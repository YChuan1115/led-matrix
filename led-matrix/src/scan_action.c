#include<sys/time.h>
#include<unistd.h>
#include<stdint.h>
#include<led_matrix.h>

static void enable_Y(LED_matrix * led, uint8_t y_line )
{
	GPIO_WRITE(led->pin_set.A , (y_line & 0x01 )?(HIGH):(LOW));
	GPIO_WRITE(led->pin_set.B , (y_line & 0x02 )?(HIGH):(LOW));
	GPIO_WRITE(led->pin_set.C , (y_line & 0x04 )?(HIGH):(LOW));
	GPIO_WRITE(led->pin_set.D , (y_line & 0x08 )?(HIGH):(LOW));
}


void scan_led_mat_0bit_32x32(LED_matrix * led)
{
	int x,y,y1,y2,y_line ;
	for(y_line = 0 ; y_line < 16; y_line++ ){
		for(x=0 ; x < 32 ; x++){
			y1 = y_line;
			y2 = y_line + 16;

			GPIO_WRITE(led->pin_set.R1 , ((BIT8*)(&(led->RGB_mat[x][y1].R)))->b0 );
			GPIO_WRITE(led->pin_set.B1 , ((BIT8*)(&(led->RGB_mat[x][y1].B)))->b0 );

			GPIO_WRITE(led->pin_set.R2 , ((BIT8*)(&(led->RGB_mat[x][y2].R)))->b0 );
			GPIO_WRITE(led->pin_set.B2 , ((BIT8*)(&(led->RGB_mat[x][y2].B)))->b0 );

			GPIO_WRITE(led->pin_set.CLK,HIGH); GPIO_WRITE(led->pin_set.CLK,LOW);
		}
		enable_Y(led,y_line);
		GPIO_WRITE(led->pin_set.LAT,HIGH); GPIO_WRITE(led->pin_set.LAT,LOW);
	}
}


void scan_led_mat_1bit_32x32(LED_matrix * led)
{
	int x,y,y1,y2,y_line ;
	for(y_line = 0 ; y_line < 16; y_line++ ){
		for(x=0 ; x < 32 ; x++){
			y1 = y_line;
			y2 = y_line + 16;

			GPIO_WRITE(led->pin_set.R1 , ((BIT8*)(&(led->RGB_mat[x][y1].R)))->b1 );
			GPIO_WRITE(led->pin_set.B1 , ((BIT8*)(&(led->RGB_mat[x][y1].B)))->b1 );

			GPIO_WRITE(led->pin_set.R2 , ((BIT8*)(&(led->RGB_mat[x][y2].R)))->b1 );
			GPIO_WRITE(led->pin_set.B2 , ((BIT8*)(&(led->RGB_mat[x][y2].B)))->b1 );

			GPIO_WRITE(led->pin_set.CLK,HIGH); GPIO_WRITE(led->pin_set.CLK,LOW);
		}
		enable_Y(led,y_line);
		GPIO_WRITE(led->pin_set.LAT,HIGH); GPIO_WRITE(led->pin_set.LAT,LOW);
	}

}

void scan_led_mat_2bit_32x32(LED_matrix * led)
{
	int x,y,y1,y2,y_line ;
	for(y_line = 0 ; y_line < 16; y_line++ ){
		for(x=0 ; x < 32 ; x++){
			y1 = y_line;
			y2 = y_line + 16;

			GPIO_WRITE(led->pin_set.R1 , ((BIT8*)(&(led->RGB_mat[x][y1].R)))->b2 );
			GPIO_WRITE(led->pin_set.B1 , ((BIT8*)(&(led->RGB_mat[x][y1].B)))->b2 );

			GPIO_WRITE(led->pin_set.R2 , ((BIT8*)(&(led->RGB_mat[x][y2].R)))->b2 );
			GPIO_WRITE(led->pin_set.B2 , ((BIT8*)(&(led->RGB_mat[x][y2].B)))->b2 );

			GPIO_WRITE(led->pin_set.CLK,HIGH); GPIO_WRITE(led->pin_set.CLK,LOW);
		}
		enable_Y(led,y_line);
		GPIO_WRITE(led->pin_set.LAT,HIGH); GPIO_WRITE(led->pin_set.LAT,LOW);
	}

}


void scan_led_mat_3bit_32x32(LED_matrix * led)
{
	int x,y,y1,y2,y_line ;
	for(y_line = 0 ; y_line < 16; y_line++ ){
		for(x=0 ; x < 32 ; x++){
			y1 = y_line;
			y2 = y_line + 16;

			GPIO_WRITE(led->pin_set.R1 , ((BIT8*)(&(led->RGB_mat[x][y1].R)))->b3 );
			GPIO_WRITE(led->pin_set.B1 , ((BIT8*)(&(led->RGB_mat[x][y1].B)))->b3 );

			GPIO_WRITE(led->pin_set.R2 , ((BIT8*)(&(led->RGB_mat[x][y2].R)))->b3 );
			GPIO_WRITE(led->pin_set.B2 , ((BIT8*)(&(led->RGB_mat[x][y2].B)))->b3 );

			GPIO_WRITE(led->pin_set.CLK,HIGH); GPIO_WRITE(led->pin_set.CLK,LOW);
		}
		enable_Y(led,y_line);
		GPIO_WRITE(led->pin_set.LAT,HIGH); GPIO_WRITE(led->pin_set.LAT,LOW);
	}

}


void scan_led_mat_4bit_32x32(LED_matrix * led)
{
	int x,y,y1,y2,y_line ;
	for(y_line = 0 ; y_line < 16; y_line++ ){
		for(x=0 ; x < 32 ; x++){
			y1 = y_line;
			y2 = y_line + 16;

			GPIO_WRITE(led->pin_set.R1 , ((BIT8*)(&(led->RGB_mat[x][y1].R)))->b4 );
			GPIO_WRITE(led->pin_set.B1 , ((BIT8*)(&(led->RGB_mat[x][y1].B)))->b4 );

			GPIO_WRITE(led->pin_set.R2 , ((BIT8*)(&(led->RGB_mat[x][y2].R)))->b4 );
			GPIO_WRITE(led->pin_set.B2 , ((BIT8*)(&(led->RGB_mat[x][y2].B)))->b4 );

			GPIO_WRITE(led->pin_set.CLK,HIGH); GPIO_WRITE(led->pin_set.CLK,LOW);
		}
		enable_Y(led,y_line);
		GPIO_WRITE(led->pin_set.LAT,HIGH); GPIO_WRITE(led->pin_set.LAT,LOW);
	}

}


void scan_led_mat_5bit_32x32(LED_matrix * led)
{
	int x,y,y1,y2,y_line ;
	for(y_line = 0 ; y_line < 16; y_line++ ){
		for(x=0 ; x < 32 ; x++){
			y1 = y_line;
			y2 = y_line + 16;

			GPIO_WRITE(led->pin_set.R1 , ((BIT8*)(&(led->RGB_mat[x][y1].R)))->b5 );
			GPIO_WRITE(led->pin_set.B1 , ((BIT8*)(&(led->RGB_mat[x][y1].B)))->b5 );

			GPIO_WRITE(led->pin_set.R2 , ((BIT8*)(&(led->RGB_mat[x][y2].R)))->b5 );
			GPIO_WRITE(led->pin_set.B2 , ((BIT8*)(&(led->RGB_mat[x][y2].B)))->b5 );

			GPIO_WRITE(led->pin_set.CLK,HIGH); GPIO_WRITE(led->pin_set.CLK,LOW);
		}
		enable_Y(led,y_line);
		GPIO_WRITE(led->pin_set.LAT,HIGH); GPIO_WRITE(led->pin_set.LAT,LOW);
	}

}


void scan_led_mat_6bit_32x32(LED_matrix * led)
{
	int x,y,y1,y2,y_line ;
	for(y_line = 0 ; y_line < 16; y_line++ ){
		for(x=0 ; x < 32 ; x++){
			y1 = y_line;
			y2 = y_line + 16;

			GPIO_WRITE(led->pin_set.R1 , ((BIT8*)(&(led->RGB_mat[x][y1].R)))->b6 );
			GPIO_WRITE(led->pin_set.B1 , ((BIT8*)(&(led->RGB_mat[x][y1].B)))->b6 );

			GPIO_WRITE(led->pin_set.R2 , ((BIT8*)(&(led->RGB_mat[x][y2].R)))->b6 );
			GPIO_WRITE(led->pin_set.B2 , ((BIT8*)(&(led->RGB_mat[x][y2].B)))->b6 );

			GPIO_WRITE(led->pin_set.CLK,HIGH); GPIO_WRITE(led->pin_set.CLK,LOW);
		}
		enable_Y(led,y_line);
		GPIO_WRITE(led->pin_set.LAT,HIGH); GPIO_WRITE(led->pin_set.LAT,LOW);
	}

}


void scan_led_mat_7bit_32x32(LED_matrix * led)
{
	int x,y,y1,y2,y_line ;
	for(y_line = 0 ; y_line < 16; y_line++ ){
		for(x=0 ; x < 32 ; x++){
			y1 = y_line;
			y2 = y_line + 16;

			GPIO_WRITE(led->pin_set.R1 , ((BIT8*)(&(led->RGB_mat[x][y1].R)))->b7 );
			GPIO_WRITE(led->pin_set.B1 , ((BIT8*)(&(led->RGB_mat[x][y1].B)))->b7 );

			GPIO_WRITE(led->pin_set.R2 , ((BIT8*)(&(led->RGB_mat[x][y2].R)))->b7 );
			GPIO_WRITE(led->pin_set.B2 , ((BIT8*)(&(led->RGB_mat[x][y2].B)))->b7 );

			GPIO_WRITE(led->pin_set.CLK,HIGH); GPIO_WRITE(led->pin_set.CLK,LOW);
		}
		enable_Y(led,y_line);
		GPIO_WRITE(led->pin_set.LAT,HIGH); GPIO_WRITE(led->pin_set.LAT,LOW);
	}

}


// perform the series functions: scan_led_mat_<n>bit_32x32(LED_matrix *)
// with certain time delay
//
void scan_led_mat_for_microsec(LED_matrix * led, uint16_t micro_second, Scan_action_ptr scan_act)
{
	struct timeval start;
	struct timeval now;

	gettimeofday(&start,NULL);
	while(1){
		gettimeofday(&now,NULL);
		uint16_t time_pass_us = (uint16_t)((long)now.tv_sec - (long)start.tv_sec ) * 1000000 + ( (long) now.tv_usec - (long)start.tv_usec );
		if( time_pass_us >= micro_second ) break;
		else{
			scan_act(led);
			usleep(micro_second >> 2);
		}
	}
}
