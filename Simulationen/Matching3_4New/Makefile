CFLAGS = -O6 -g
CC = g++
LIBS = -lm

perc:perc.o rnglong.o 
	$(CC) $(CFLAGS) -o perc $(LIBS) perc.o rnglong.o

perc.o:perc.c++ rnglong.h lattice.h lattice.c++ Makefile
	$(CC) $(CFLAGS) -c perc.c++

rnglong.o:rnglong.c rnglong.h Makefile
	$(CC) $(CFLAGS) -c rnglong.c

