#include <stdio.h>
#include <string.h>
#define MAXIMO 26

char * encriptar(char nuv_fra[MAXIMO],int num);

int main(){
    int llave;
    char cadena[MAXIMO];

    printf("\t\t\t\t\tCIFRADO CICLICO:\n");
    printf("Introducir mensaje: ");
    fgets(cadena,100,stdin);

    //while(getchar()!='\n');
    printf("ingrese la llave numerica: ");
    scanf("%d",&llave);
    //while(getchar()!='\n');
    printf("\nLa frase encriptado es:\n%s\n", encriptar(cadena, llave));
    return 0;
}

char *  encriptar(char cadena[MAXIMO],int llave){
    int i=0;
    while(cadena[i]!='\0'){
        cadena[i]=cadena[i]+llave;
        i++;
    }
    return cadena;  
}


