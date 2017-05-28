#include "../include/cifrado.h"

char* cifradoCiclico(char* mensaje, int llave){
	int i=0;
    int dif;
    /* si la llave es negativa y mayor a 26 */
    if(llave < 0){
		llave=(-1*llave)%26;
		llave=(-1*llave);
		while(mensaje[i]!='\0'){
			if(mensaje[i]>='A' && mensaje[i]<='Z'){
				if((dif=mensaje[i]+llave-'A')<=0){
					mensaje[i]='Z'+dif+1;
				}else{
					mensaje[i]+=llave;
				}
			}else if(mensaje[i]>='a' && mensaje[i]<='z'){
				if((dif=mensaje[i]+llave-'a')<=0){
					mensaje[i]='z'+dif+1;
				}else{
					mensaje[i]+=llave;
				}
			}
			i++;
		}
    }else{
	   	llave=llave % 26;
		while(mensaje[i]!='\0'){
			if(mensaje[i]>='A' && mensaje[i]<='Z'){
				if((dif=mensaje[i]+llave-'Z')>0){
					mensaje[i]='A'+dif-1;
				}else{
					mensaje[i]+=llave;
				}
			}else if(mensaje[i]>='a' && mensaje[i]<='z'){
				if((dif=mensaje[i]+llave-'z')>0){
					mensaje[i]='a'+dif-1;
				}else{
					mensaje[i]+=llave;
				}
			}
			i++;
		}
    }
    return mensaje;
}

char* cifradoAutollave(char* mensaje, char* llave);
char* cifradoContrasena(char* mensaje, char* llave );