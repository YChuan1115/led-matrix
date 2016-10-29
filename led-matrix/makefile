CC=gcc
CFLAG=-lbcm2835 -pthread
INCL=-I./ -I./include/

all:main.o
	cd ./src;make
	cp ./src/*.o ./
	$(CC) *.o -o led-run $(CFLAG) $(INCL)

main.o: main.c
	$(CC) -c main.c $(CFLAG) $(INCL)

clean:
	cd ./src;make clean
	rm *.o;rm led-run
