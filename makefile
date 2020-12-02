FLAGS = -Wall -g
LIBOBJECTS = power.o basicMath.o
AR= ar
CC = gcc

all: main

main: libmyBank.a main.o
	$(CC) $(FLAGS) main.o libmyBank.a -o main

libmyBank.a: myBank.o
		$(AR) -rcs libmyBank.a myBank.o

main.o: main.c myBank.h
		$(CC) $(FLAGS) -c main.c myBank.h

myBank.o: myBank.c
		$(CC) $(FLAGS) -c myBank.c

.PHONY: clean all 

clean: 							
	rm -f *.o all *.a main
