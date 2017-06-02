#include "../include/codificacion.h"

char* claveMorse(char* mensaje){
	int i=0;
	char letra[strlen(mensaje)];
    while(mensaje[i]!='\0'){
	        
		if (mensaje[i] == 65){strncat(letra,". —    ",30);}//a
		if (mensaje[i] == 66){strncat(letra,"— . . .    ",30);}//b
		if (mensaje[i] == 67){strncat(letra,"— . — .    ",30);}///c
		if (mensaje[i] == 68){strncat(letra,"— . .    ",30);}//d
		if (mensaje[i] == 69){strncat(letra,".    ",30);}//e
		if (mensaje[i] == 70){strncat(letra,". . — .    ",30);}//f
		if (mensaje[i] == 71){strncat(letra,"— — .    ",30);}//g
		if (mensaje[i] == 72){strncat(letra,". . . .    ",30);}//h
		if (mensaje[i] == 73){strncat(letra,". .    ",30);}//i
		if (mensaje[i] == 74){strncat(letra,". — — —    ",30);}//j
		if (mensaje[i] == 75){strncat(letra,"— . —    ",30);}//k
		if (mensaje[i] == 76){strncat(letra,". — . .    ",30);}//l
		if (mensaje[i] == 77){strncat(letra,"— —    ",30);}//m
		if (mensaje[i] == 78){strncat(letra,"— .    ",30);}//n
		if (mensaje[i] == 79){strncat(letra,"— — —    ",30);}//o
		if (mensaje[i] == 80){strncat(letra,". — — .    ",30);}//p
		if (mensaje[i] == 81){strncat(letra,"— — . —    ",30);}//q
		if (mensaje[i] == 82){strncat(letra,". — .    ",30);}//r
		if (mensaje[i] == 83){strncat(letra,". . .    ",30);}//s
		if (mensaje[i] == 84){strncat(letra,"—    ",30);}//t
		if (mensaje[i] == 85){strncat(letra,". . —    ",30);}//u
		if (mensaje[i] == 86){strncat(letra,". . . —    ",30);}//v
		if (mensaje[i] == 87){strncat(letra,". — —    ",30);}//w
		if (mensaje[i] == 88){strncat(letra,"— . . —    ",30);}//x
		if (mensaje[i] == 89){strncat(letra,"— . — —    ",30);}//y
		if (mensaje[i] == 90){strncat(letra,"— — . .    ",30);}//z

		if (mensaje[i] == 97){strncat(letra,". —    ",30);}//A
		if (mensaje[i] == 98){strncat(letra,"— . . .    ",30);}//b
		if (mensaje[i] == 99){strncat(letra,"— . — .    ",30);}///c
		if (mensaje[i] == 100){strncat(letra,"— . .    ",30);}//d
		if (mensaje[i] == 101){strncat(letra,".    ",30);}//e
		if (mensaje[i] == 102){strncat(letra,". . — .    ",30);}//f
		if (mensaje[i] == 103){strncat(letra,"— — .    ",30);}//g
		if (mensaje[i] == 104){strncat(letra,". . . .    ",30);}//h
		if (mensaje[i] == 105){strncat(letra,". .    ",30);}//i
		if (mensaje[i] == 106){strncat(letra,". — — —    ",30);}//j
		if (mensaje[i] == 107){strncat(letra,"— . —    ",30);}//k
		if (mensaje[i] == 108){strncat(letra,". — . .    ",30);}//l
		if (mensaje[i] == 109){strncat(letra,"— —    ",30);}//m
		if (mensaje[i] == 110){strncat(letra,"— .    ",30);}//n
		if (mensaje[i] == 111){strncat(letra,"— — —    ",30);}//o
		if (mensaje[i] == 112){strncat(letra,". — — .    ",30);}//p
		if (mensaje[i] == 113){strncat(letra,"— — . —    ",30);}//q
		if (mensaje[i] == 114){strncat(letra,". — .    ",30);}//r
		if (mensaje[i] == 115){strncat(letra,". . .    ",30);}//s
		if (mensaje[i] == 116){strncat(letra,"—    ",30);}//t
		if (mensaje[i] == 117){strncat(letra,". . —    ",30);}//u
		if (mensaje[i] == 118){strncat(letra,". . . —    ",30);}//v
		if (mensaje[i] == 119){strncat(letra,". — —    ",30);}//w
		if (mensaje[i] == 120){strncat(letra,"— . . —    ",30);}//x
		if (mensaje[i] == 121){strncat(letra,"— . — —    ",30);}//y
		if (mensaje[i] == 122){strncat(letra,"— — . .    ",30);}//z

		if (mensaje[i] == 48){strncat(letra,"— — — — —    ",30);}//0
		if (mensaje[i] == 49){strncat(letra,". — — — —    ",30);}//1
		if (mensaje[i] == 50){strncat(letra,". . — — —    ",30);}//2
		if (mensaje[i] == 51){strncat(letra,". . . — —    ",30);}//3
		if (mensaje[i] == 52){strncat(letra,". . . . —    ",30);}//4
		if (mensaje[i] == 53){strncat(letra,". . . . .    ",30);}//5
		if (mensaje[i] == 54){strncat(letra,"— . . . .    ",30);}//6
		if (mensaje[i] == 55){strncat(letra,"— — . . .    ",30);}//7
		if (mensaje[i] == 56){strncat(letra,"— — — . .    ",30);}//8
		if (mensaje[i] == 57){strncat(letra,"— — — — .    ",30);}//9

		if (mensaje[i] == 32){strncat(letra,"/    ",30);}//espacio
		if (mensaje[i] == 46){strncat(letra," — . — . —    ",30);}//.
		if (mensaje[i] == 44){strncat(letra,"— . — . — —    ",30);}//,		
		i++;
    }
    mensaje=letra;
    return mensaje;

}

