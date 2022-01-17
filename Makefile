all: build run

run:
	./lab3 -a

build:
	g++ -c main.cpp
	g++ -o lab3 main.o

clean:
	rm -rf *.o ./lab3
