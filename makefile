myBank.o: myBank.c
	gcc -Wall -g -c myBank.c -o myBank.o

libmyBank.a: myBank.o
	ar -rcs libmyBank.a myBank.o

mains: main.o libmyBank.a
	gcc -Wall -g -o mains main.o libmyBank.a

main.o: main.c myBank.h
	gcc -Wall -g -c main.c

.PHONY: clean all

all: libmyBank.a mains myBank.o main.o

clean:
	rm -f *.o *.a *.so mains maind
