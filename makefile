CC=g++
CCFLAGS=-Wall
OBJS= pa1.o verify.o

all: pa1.x 

pa1.x: $(OBJS) new
	$(CC) $(CCFLAGS) $(OBJS) -std=c++11 -o pa1.x  -pthread
	./pa1.x 0 4 5 4 a b c

pa1.o: pa1.cpp 
	$(CC) $(CCFLAGS) -std=c++11 -c pa1.cpp -pthread

verify.o: verify.cpp
	$(CC) $(CCFLAGS) -std=c++11 -c verify.cpp -pthread

new:

clean:
	rm *.o *.x out.txt
