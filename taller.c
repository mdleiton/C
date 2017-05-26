#include <stdio.h>
#include <string.h>
#define MAXIMO 30

char * encriptar(char nuv_fra[MAXIMO],int num);

int  main(){
    int llave;
    char cadena[MAXIMO];

    printf("\t\t\t\t\tCIFRADO CICLICO:\n");
    printf("Introducir mensaje: ");
    fgets(cadena,100,stdin);
    printf("ingrese la llave numerica: ");
    scanf("%d",&llave);
    printf("\nLa frase encriptado es:\n%s\n", encriptar(cadena, llave));
    return 0;
}

char *  encriptar(char cadena[MAXIMO],int llave){
    int i=0;
    int dif;
    while(cadena[i]!='\0'){
	if(cadena[i]>='A' && cadena[i]<='Z'){
		if((dif=cadena[i]+llave-'Z')>0){
			cadena[i]='A'+dif-1;
		}else{
        		cadena[i]=cadena[i]+llave;
        	}
	}
	i++;
    }
    return cadena;  
}

