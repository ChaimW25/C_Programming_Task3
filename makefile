all: stringProg

stringProg: main.o str_ex3.o
	gcc -Wall -g main.o str_ex3.o -o stringProg
main.o: main.c str_ex3.h
	gcc -Wall -g -c main.c
str_ex3.o: str_ex3.c str_ex3.h
	gcc -Wall -g -c str_ex3.c
.PHONY: clean

clean:
	rm -f *.o stringProgi
