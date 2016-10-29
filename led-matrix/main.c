#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/time.h>
#include<signal.h>
#include<pthread.h>
#include<lib_uart.h>

#include<led_matrix.h>
#include<scan_action.h>


/// pthread function 
void * led_matrix_run(void *args);
void * get_audio_info(void *data);


// signal function 
void ctrl_c_sig_func(int sig);


//
void draw_channel(int ch, int val, LED_matrix *led);
int get_7_vals(int *vals, char * msg);
/////////////////////////////////////


// system control flag
int run_flag = 1;

char message[200];
int vals[7];
char __buff[200];

int main(int argc,char *argv[]){

	signal(SIGINT, ctrl_c_sig_func );

	//
	// initialization of LED Matrix
	//
	run_flag = 1;
	LED_matrix led;
	if(create_led_mat(&led, 32,32, NULL) == -1){
		printf("error at create led\n");
		return -1;
	}

	//
	// GPIO init
	//
	GPIO_INIT();
	init_led_mat(&led);


	/*
	 * START : pthread of led_matrix scanning
	 * */

	pthread_t led_matrix_run_pthread;
	if(pthread_create(&led_matrix_run_pthread, NULL, led_matrix_run, (void *) &led)){
		printf("Error : pthread create led_matrix_fun.\n");
		return 1;
	}

	pthread_t get_audio_info_pth;
	if(pthread_create(&get_audio_info_pth, NULL, get_audio_info, NULL )){
		printf("Error : pthread create led_matrix_fun.\n");
		return 1;
	}


	while(run_flag){
		// read the audio information from arduino via uart
		strcpy(__buff, message);
		get_7_vals(vals, __buff); 
		int ch ;
		for(ch=0 ;ch<7 ;ch++ ){
			draw_channel(ch, vals[ch], &led);
			//printf("%d ", vals[ch]);
		}
		//printf("\n");
		// draw the line via channel

	}


	pthread_join(led_matrix_run_pthread,NULL);
	pthread_join(get_audio_info_pth, NULL);


	return 0;
}



void * led_matrix_run(void *args)
{
	LED_matrix * led = (LED_matrix *) args;
	while(run_flag){
		scan_led_mat_for_microsec(led,16000,scan_led_mat_0bit_32x32);
	}
	return NULL;
}



void ctrl_c_sig_func(int sig)
{
	run_flag = 0;
	signal(SIGINT, SIG_DFL);
}


void * get_audio_info(void *data)
{
	static char buff[100];
	int len = 0;

	// open the tty usb0
	struct serial_port usb_tty;
	strcpy(usb_tty.device, "/dev/ttyUSB0");
	if(-1 == open_serial(&usb_tty, 0))
	{
		printf("ERROR: open /dev/ttyUSB0\n");
		return NULL;
	}

	while(run_flag )
	{
		struct timeval start;
		struct timeval now;
		char ch = '\n';

		// send 
		int res = write(usb_tty.fd, &ch, 1);

		// start to receive 
		while(run_flag){
			gettimeofday(&start,NULL);
			res = read(usb_tty.fd, buff + len, 1);
			if(res >= 0){
				len+= res;
				if(buff[len-1] == 10){
					if(buff[0] != 's') break;
					strcpy(message,buff+1);
					usleep(100);
					break;
				}
			}

			gettimeofday(&now,NULL);
			int delta_time = 1000000 * (now.tv_sec - start.tv_sec) + (now.tv_usec - start.tv_usec);
			if(delta_time > 10000){
				printf("timeout\n");
				break;
			}
		}
		// clean buff
		while(len--) buff[len] = 0; len = 0;
		usleep(10000);
	}

	close_serial(&usb_tty);
	return NULL;
}



int get_7_vals(int *vals, char * msg){

	char buff[200];
	char * sptr;
	int i = 0;

	if(msg[0] == 0) return -1;
	strcpy(buff,msg);
	vals[0] = atoi(strtok(buff," "));
	for(i=1 ; i < 7 ;i++ ){
		sptr = strtok(NULL," ");
		if(sptr == NULL) return -1;
		vals[i] = atoi(sptr);
	}
	return 0;
}


void draw_channel(int ch, int val, LED_matrix * led)
{
	int x,y;
	int y_edge = val / 32;
	int x_start, x_end;
	switch(ch)
	{
		case 0:
			x_start = 0;
			x_end = 4;
			break;
		case 1:
			x_start = 5;
			x_end = 9;
			break;
		case 2:
			x_start = 10;
			x_end = 14;
			break;
		case 3:
			x_start = 15;
			x_end = 19;
			break;
		case 4:
			x_start = 20;
			x_end = 23;
			break;
		case 5:
			x_start = 24;
			x_end = 27;
			break;
		case 6:
			x_start = 28;
			x_end = 31;
			break;
		default:
			return ;
			break;
	}

	for(x=x_start ;x <= x_end ; x++ )
		for(y=0 ;y < 32; y++ )
			led->RGB_mat[x][y].R = (y < y_edge)?(1):(0);
}

