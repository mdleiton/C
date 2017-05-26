#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXIMO 120

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
