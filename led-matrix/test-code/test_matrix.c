#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<sys/time.h>
#include<led_matrix.h>





int main(int argc,char *argv[]){

	// initialize a LED_matrix
	//
	LED_matrix led;
	if(create_led_mat(&led, 32,32, NULL) == -1){
		printf("error at create led\n");
		return 0;
	}
	GPIO_INIT();
	init_led_mat(&led);


	uint8_t **mat01 = malloc(sizeof(uint8_t*) * 32);
	int x,y;
	for(x=0 ;x<32 ;x++ ){
		mat01[x] = malloc(sizeof(uint8_t) * 32);
	}
	for(x=0 ;x<32 ;x++ ){
		for(y=0 ;y<32 ;y++ ){
			mat01[x][y] = (x==y+1)?(1):(0);
		}
	}

	// test for copy mat function //
	//
	printf("test for copy mat to led\n");
	copy_mat_to_R_LED_mat(&led, mat01,0,0,32,32);
	copy_mat_to_G_LED_mat(&led, mat01,0,0,32,32);
	copy_mat_to_B_LED_mat(&led, mat01,0,0,32,32);

	// test for print mat function //
	printf("===============================\n");
	printf("test for print RGB mat in led matrix\n");
	printf("===============================\n");
	print_led_mat_content(&led);


	// test for init the pin set of the led matrix //
	printf("=================================\n");
	printf("LED matrix pin set initialize.\n");
	printf("=================================\n");


	// test for scan action 
	struct timeval now;
	struct timeval pre;
	struct timeval start;
	gettimeofday(&start,NULL);



	printf("START test scan action: \n");
	printf("this function calcul the estimated time: \n");
	while(1){
		gettimeofday(&pre,NULL);

		scan_led_mat_0bit_32x32(&led);

		gettimeofday(&now,NULL);
		long time_val = 1000000*(now.tv_sec - start.tv_sec) + now.tv_usec - start.tv_usec;
		printf("time val: %u\n",now.tv_usec - pre.tv_usec);
		if(time_val >= 5000000){
			break;
		}
	}

	//gettimeofday(&start,NULL);
	//while(1){
	//	gettimeofday(&pre,NULL);

	//	scan_led_mat_for_microsec(&led,16000,scan_led_mat_0bit_32x32);

	//	gettimeofday(&now,NULL);
	//	long time_val = 1000000*(now.tv_sec - start.tv_sec) + now.tv_usec - start.tv_usec;
	//	printf("time val: %u\n",now.tv_usec - pre.tv_usec);
	//	if(time_val >= 5000000){
	//		break;
	//	}
	//}


	printf("%d\n",((BIT8*)(&(led.RGB_mat[0][1].R)))->b0);
	printf("%d\n",((BIT8*)(&(led.RGB_mat[0][1].R)))->b1);
	printf("%d\n",((BIT8*)(&(led.RGB_mat[0][1].R)))->b2);
	printf("%d\n",((BIT8*)(&(led.RGB_mat[0][1].R)))->b3);
	printf("%d\n",((BIT8*)(&(led.RGB_mat[0][1].R)))->b4);
	printf("%d\n",((BIT8*)(&(led.RGB_mat[0][1].R)))->b5);
	printf("%d\n",((BIT8*)(&(led.RGB_mat[0][1].R)))->b6);
	printf("%d\n",((BIT8*)(&(led.RGB_mat[0][1].R)))->b7);

	// test for release the led matrix
	printf("=============================\n");
	printf("TEST for the release_led_mat()\n");
	printf("=============================\n");
	release_led_mat(&led);
	printf("release_led_mat(): success!!\n");
	return 0;
}
