CC = g++
CFLAGS = -std=c++11 -g
LDFLAGS =

.PHONY: all clean


all: main

main: main.o solver.o cache.o
	$(CC) $(LDFLAGS) $^ -o $@

main.o: main.cpp solver.h cache.h
	$(CC) $(CFLAGS) -c $< -o $@

solver.o: solver.cpp solver.h cache.h
	$(CC) $(CFLAGS) -c $< -o $@

cache.o: cache.cpp cache.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm main *.o
