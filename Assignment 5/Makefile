CC = gcc
args = -O -Wall -lm

all:: testCubic

quad.o: quad.c
	$(CC) $(args) -o quad.o quad.c

cubic.o: cubic.c
	$(CC) $(args) -o cubic.o cubic.c

testQuad: quad.o
	./quad.o image-quad.svg 0 10 40 275 150 30 260 275

testCubic: cubic.o
	./cubic.o image-cubic.svg 0 10 0.5 45 150 45 25 255 275 255 150

clean::
	rm quad.o cubic.o
