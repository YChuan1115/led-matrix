#ifndef LIB_UART_H
#define LIB_UART_H

#include<sys/types.h>
#include<sys/stat.h>
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<fcntl.h>
#include<termios.h>
#include<string.h>
#include<sys/select.h>


struct serial_port{
	char device[20];
	uint16_t baud_rate;
	int fd;
	struct termios old_os;
	struct termios new_os;
};


int open_serial(struct serial_port * ser_port, int timeout);
int close_serial(struct serial_port * ser_port);


int nonblock_read_tty(struct serial_port * ser_port, char * buff, uint8_t len);
int nonblock_readline_tty(struct serial_port * ser_port, char * buff, uint8_t len);
int nonblock_read_stdin(char * buff, uint8_t len);

#endif
