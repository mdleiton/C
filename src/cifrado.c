#include "../include/cifrado.h"
#define MAX_ROWS 26
#define MAX_COLS 26
#define MAX 26

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
//////////////////////////////////////////////////
char* cifradoAutollave(char* mensaje, char* llave)
{
//printf("%s\n",mensaje);
char abecedario[MAX]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char nuevoabc[MAX]={0};
char codigo[MAX]={0};
int i=0;
//printf("\n%s",abecedario);

while(llave[i]!='\0'){     
	nuevoabc[i]=llave[i];
	i++;
}
int j=0;
for (int c=i;c<26;c++){
	nuevoabc[c]=abecedario[j];
	j++;
}
//printf("\n%s",nuevoabc);

int h=0;
while(mensaje[h]!='\0'){
for (int l=0;abecedario[l]!='\0';l++){
if (mensaje[h]==abecedario[l])
{
//printf("\n%d\n abecedario: ",l);
//printf("%c abecedario: ",abecedario[l]);
//printf("%c abecedario: ",nuevoabc[l]);
codigo[h]=nuevoabc[l];
}else if (mensaje[h] == 32){
codigo[h]=mensaje[h];
}
}
h++;
}
//printf("\n%s\n",codigo);
mensaje=codigo;

printf("Mensaje encriptado:      ");
return mensaje;
 
}




//////////////////////////////////////////////
char* cifradoContrasena(char* mensaje, char* llave ){

//printf("%s\n",mensaje);
char abecedario[MAX]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char nuevoabc[MAX]={0};
char codigo[MAX]={0};
int i=0;
//printf("\n%s",abecedario);

while(llave[i]!='\0'){     
	nuevoabc[i]=llave[i];
	i++;
}
int j=0;
for(int d=i;d<26;d++){
	nuevoabc[d]=abecedario[j];
	j++;
}
//printf("\n%s",nuevoabc);

int h=0;
while(mensaje[h]!='\0'){
for(int l=0;abecedario[l]!='\0';l++){
if (mensaje[h]==abecedario[l])
{
//printf("\n%d\n abecedario: ",l);
//printf("%c abecedario: ",abecedario[l]);
//printf("%c abecedario: ",nuevoabc[l]);
codigo[h]=nuevoabc[l];
}else if (mensaje[h] == 32){
codigo[h]=mensaje[h];
}
}
h++;
}
//printf("\n%s\n",codigo);
mensaje=codigo;

printf("Mensaje encriptado:      ");
return mensaje;
}
