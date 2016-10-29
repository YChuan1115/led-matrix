CC=gcc
CFLAG=-lbcm2835
INCL=-I../include

all:led_matrix.o scan_action.o lib_uart.o

led_matrix.o: led_matrix.c
	$(CC) -c led_matrix.c $(INCL) $(CFLAG) 

scan_action.o: scan_action.c
	$(CC) -c scan_action.c $(INCL) $(CFLAG) 

lib_uart.o: lib_uart.c
	$(CC) -c lib_uart.c $(INCL) $(CFLAG) 

clean:
	rm *.o
