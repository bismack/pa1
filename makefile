CC=g++
CCFLAGS=-Wall

all: pa1.x

pa1.x: pa1.o
	$(CC) $(CCFLAGS) -o pa1.x pa1.cpp -pthread
	./pa1.x

pa1.o: pa1.cpp
	$(CC) $(CCFLAGS) -c pa1.cpp -pthread

clean:
	rm *.o *.x 
