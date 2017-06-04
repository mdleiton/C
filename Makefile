
all: cifradolib codificacion.o main.o ejecutable

cifradolib:
	gcc -Wall -shared -fPIC -o lib/libcifrado.so src/cifrado.c

codificacion.o:
	gcc -Wall -c  src/codificacion.c -o obj/codificacion.o 

main.o:
	gcc -Wall -c  -Iinclude/ src/main.c -o obj/main.o

ejecutable:
	gcc -Wall -o  bin/cifrador  -Iinclude/ obj/*.o lib/libcifrado.so

.PHONY: clean
clean:
	rm -rf obj/* bin/* lib/*
