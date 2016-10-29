CC=gcc
CFLAG=-lbcm2835
INCL=-I./ -I../include/ 

test: test_matrix.c
	$(CC) -c test_matrix.c $(INCL) $(CFLAG)
	$(CC) led_matrix.o test_matrix.o scan_action.o -o test01 $(CFLAG)

objs:
	cd ../src/;make
	cp ../src/*.o ./

all_clean:
	cd ../src/;make clean
	rm *.o

clean:
	rm *.o;rm test01
