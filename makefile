lab5: main.o
	cc main.o -o lab5
main.o: main.c number.c number.h
	cc -c main.c number.c

