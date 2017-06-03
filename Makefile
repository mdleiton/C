all: cifradolib codificacion.o main.o ejecutable

cifradolib:
	gcc -Wall -shared -fPIC -o lib/libcifrado.so src/cifrado.c

codificacion.o:
	gcc -Wall -c  src/codificacion.c -o obj/codificacion.o 

main.o:
	gcc -Wall -c  src/main.c -o obj/main.o

ejecutable:
	gcc -Wall -o bin/cifrador obj/*.o lib/libcifrado.so