CFLAGS=
OUT=vector vector4

all: vector vector4

vector: main_vector.o vector.o
		$(CC) $(CFLAGS) -o vector main_vector.c vector.c
		rm -rf main_vector.o vector.o

vector4: main_vector4.o vector4.o
		$(CC) $(CFLAGS) -o vector4 main_vector4.c vector4.c
		rm -rf main_vector4.o vector4.o

debug: CFLAGS+=-DDEBUG_ON
debug: build

main_vector.o: main_vector.c vector.h
		$(CC) $(CFLAGS) -c main_vector.c

vector.o: vector.c vector.h
		$(CC) $(CFLAGS) -c vector.c

main_vector4.o: main_vector4.c vector4.h
		$(CC) $(CFLAGS) -c main_vector4.c

vector4.o: vector4.c vector4.h
		$(CC) $(CFLAGS) -c vector4.c

clean:
		rm -rf *.o $(OUT)

