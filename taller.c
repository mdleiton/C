#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXIMO 1200

char * encriptar(char nuv_fra[MAXIMO],int num);
char * morse(char cadena[MAXIMO]);

int  main(int argc, char *argv[] ){
    int llave;
    char cadena[MAXIMO];
    printf("\t\t\t\t\tCIFRADO CICLICO:\n");
    if(argc <= 1){
	    printf("Introducir mensaje: ");
	    fgets(cadena,100,stdin);
	    printf("ingrese la llave numerica: ");
	    scanf("%d",&llave);
	    printf("\nLa cadena encriptado es:\n%s\n", encriptar(cadena, llave));
	}else if (argc<=2){
	    printf("\nle falto un argumento \n la cantidad correcta de argumentos: 2 \n llave  n cadena \n");
	}else if (argc<=3){
	    printf("\nMensaje cifrado:\n%s\n", encriptar( argv[2], atoi(argv[1])));
	    printf("\nMensaje cifrado en morse:\n%s\n", morse( argv[2]));
	}else{
		printf("no ingrese la cantidad correcta de argumentos: \n llave  \n cadena \n");
	}
	return 0;
}

char *  encriptar(char cadena[MAXIMO],int llave){
    int i=0;
    int dif;
    /* si la llave es negativa y mayor a 26 */
    if(llave < 0){
		llave=(-1*llave)%26;
		llave=(-1*llave);
		while(cadena[i]!='\0'){
			if(cadena[i]>='A' && cadena[i]<='Z'){
				if((dif=cadena[i]+llave-'A')<=0){
					cadena[i]='Z'+dif;
				}else{
					cadena[i]+=llave;
				}
			}else if(cadena[i]>='a' && cadena[i]<='z'){
				if((dif=cadena[i]+llave-'a')<=0){
					cadena[i]='z'+dif;
				}else{
					cadena[i]+=llave;
				}
			}
			i++;
		}
    }else{
	   	llave=llave % 26;
		while(cadena[i]!='\0'){
			if(cadena[i]>='A' && cadena[i]<='Z'){
				if((dif=cadena[i]+llave-'Z')>0){
					cadena[i]='A'+dif-1;
				}else{
					cadena[i]+=llave;
				}
			}else if(cadena[i]>='a' && cadena[i]<='z'){
				if((dif=cadena[i]+llave-'z')>0){
					cadena[i]='a'+dif-1;
				}else{
					cadena[i]+=llave;
				}
			}
			i++;
		}
    }
    return cadena;
}

char * morse(char cadena[MAXIMO]){
	int i=0;
    char letra[MAXIMO]={0};
    while(cadena[i]!='\0'){
	        
		if (cadena[i] == 65){strncat(letra,"· —    ",30);}//a
		if (cadena[i] == 66){strncat(letra,"— · · ·    ",30);}//b
		if (cadena[i] == 67){strncat(letra,"— · — ·    ",30);}///c
		if (cadena[i] == 68){strncat(letra,"— · ·    ",30);}//d
		if (cadena[i] == 69){strncat(letra,".    ",30);}//e
		if (cadena[i] == 70){strncat(letra,"· · — ·    ",30);}//f
		if (cadena[i] == 71){strncat(letra,"— — ·    ",30);}//g
		if (cadena[i] == 72){strncat(letra,"· · · ·    ",30);}//h
		if (cadena[i] == 73){strncat(letra,"· ·    ",30);}//i
		if (cadena[i] == 74){strncat(letra,"· — — —    ",30);}//j
		if (cadena[i] == 75){strncat(letra,"— · —    ",30);}//k
		if (cadena[i] == 76){strncat(letra,"· — · ·    ",30);}//l
		if (cadena[i] == 77){strncat(letra,"— —    ",30);}//m
		if (cadena[i] == 78){strncat(letra,"— ·    ",30);}//n
		if (cadena[i] == 79){strncat(letra,"— — —    ",30);}//o
		if (cadena[i] == 80){strncat(letra,"· — — ·    ",30);}//p
		if (cadena[i] == 81){strncat(letra,"— — · —    ",30);}//q
		if (cadena[i] == 82){strncat(letra,"· — ·    ",30);}//r
		if (cadena[i] == 83){strncat(letra,"· · ·    ",30);}//s
		if (cadena[i] == 84){strncat(letra,"—    ",30);}//t
		if (cadena[i] == 85){strncat(letra,"· · —    ",30);}//u
		if (cadena[i] == 86){strncat(letra,"· · · —    ",30);}//v
		if (cadena[i] == 87){strncat(letra,"· — —    ",30);}//w
		if (cadena[i] == 88){strncat(letra,"— · · —    ",30);}//x
		if (cadena[i] == 89){strncat(letra,"— · — —    ",30);}//y
		if (cadena[i] == 90){strncat(letra,"— — · .    ",30);}//z

		if (cadena[i] == 97){strncat(letra,"· —    ",30);}//A
		if (cadena[i] == 98){strncat(letra,"— · · ·    ",30);}//b
		if (cadena[i] == 99){strncat(letra,"— · — ·    ",30);}///c
		if (cadena[i] == 100){strncat(letra,"— · ·    ",30);}//d
		if (cadena[i] == 101){strncat(letra,".    ",30);}//e
		if (cadena[i] == 102){strncat(letra,"· · — ·    ",30);}//f
		if (cadena[i] == 103){strncat(letra,"— — ·    ",30);}//g
		if (cadena[i] == 104){strncat(letra,"· · · ·    ",30);}//h
		if (cadena[i] == 105){strncat(letra,"· ·    ",30);}//i
		if (cadena[i] == 106){strncat(letra,"· — — —    ",30);}//j
		if (cadena[i] == 107){strncat(letra,"— · —    ",30);}//k
		if (cadena[i] == 108){strncat(letra,"· — · ·    ",30);}//l
		if (cadena[i] == 109){strncat(letra,"— —    ",30);}//m
		if (cadena[i] == 110){strncat(letra,"— ·    ",30);}//n
		if (cadena[i] == 111){strncat(letra,"— — —    ",30);}//o
		if (cadena[i] == 112){strncat(letra,"· — — ·    ",30);}//p
		if (cadena[i] == 113){strncat(letra,"— — · —    ",30);}//q
		if (cadena[i] == 114){strncat(letra,"· — ·    ",30);}//r
		if (cadena[i] == 115){strncat(letra,"· · ·    ",30);}//s
		if (cadena[i] == 116){strncat(letra,"—    ",30);}//t
		if (cadena[i] == 117){strncat(letra,"· · —    ",30);}//u
		if (cadena[i] == 118){strncat(letra,"· · · —    ",30);}//v
		if (cadena[i] == 119){strncat(letra,"· — —    ",30);}//w
		if (cadena[i] == 120){strncat(letra,"— · · —    ",30);}//x
		if (cadena[i] == 121){strncat(letra,"— · — —    ",30);}//y
		if (cadena[i] == 122){strncat(letra,"— — · .    ",30);}//z

		if (cadena[i] == 48){strncat(letra,"— — — — —    ",30);}//0
		if (cadena[i] == 49){strncat(letra,". — — — —    ",30);}//1
		if (cadena[i] == 50){strncat(letra,"· · — — —    ",30);}//2
		if (cadena[i] == 51){strncat(letra,"· · · — —    ",30);}//3
		if (cadena[i] == 52){strncat(letra,"· · · · —    ",30);}//4
		if (cadena[i] == 53){strncat(letra,"· · · · ·    ",30);}//5
		if (cadena[i] == 54){strncat(letra,"— · · · ·    ",30);}//6
		if (cadena[i] == 55){strncat(letra,"— — · · ·    ",30);}//7
		if (cadena[i] == 56){strncat(letra,"— — — · ·    ",30);}//8
		if (cadena[i] == 57){strncat(letra,"— — — — ·    ",30);}//9

		if (cadena[i] == 32){strncat(letra,"/    ",30);}//espacio
		if (cadena[i] == 46){strncat(letra," — · — · —    ",30);}//.
		if (cadena[i] == 44){strncat(letra,"— · — · — —    ",30);}//,		
		i++;
    }
    cadena=letra;
    return cadena;





}

