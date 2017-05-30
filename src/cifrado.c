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
//////////////////////////////////////////////////
char* cifradoAutollave(char* mensaje, char* llave)
{
//GENERAR TABULA RECTA
    char tabula_recta[MAX_ROWS][MAX_COLS];
    int pos , row , col;
     
    for( row=0; row < MAX_ROWS; row++){
        pos = 0;
        for( col=0; col < MAX_COLS; col++){
            if('A'+row+col > 'Z' && row > 0){
                tabula_recta[row][col] = 'A'+ pos;
                pos++;
            }
        else if('A' + row + col == 'Z')
            tabula_recta[row][col] = 'Z';
        else
            tabula_recta[row][col] = 'A'+row+col;
        }
    }
     
// GENERAR NUEVA CONTRASEÑA A COMPARAR
int l=0;
char nuevcont[MAX];
int i=0;
while(contrasena[i]!='\0'){ 
        if (mensaje[i]==32){
	nuevcont[i]=mensaje[i];}
	else{     
	nuevcont[i]=contrasena[l];l++;
	}
	i++;
}
nuevcont[i]=contrasena[i-1];

int j=0;
int k= i+1;
for (k;mensaje[k]!='\0';k++){
 if(mensaje[j]==32){j++;}
	nuevcont[k]=mensaje[j];
j++;
}


//GENERAR EL CODIGO CODIFICADO
 i=0;
int tempfil, tempcol=0;
char codigo[MAX]={0};
for (i;mensaje[i]!='\0';i++){
	if (mensaje[i]==32){
		codigo[i]=mensaje[i];i++;}

	for(col=0; col<MAX_COLS; col++){
		if(tabula_recta[col][0]==mensaje[i]){
			tempfil=col;
		}
		if(tabula_recta[0][col]==nuevcont[i]){
			tempcol=col;
		}	
	}
	codigo[i]=tabula_recta[tempfil][tempcol];
}



//printf("\n%s\n",mensaje);
//printf("\n%s\n",nuevcont);

//printf("\n%s\n",codigo)
printf("Mensaje encriptado:      ");
mensaje=codigo;
return mensaje;
//return codigo;
 
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
for (i;i<26;i++){
	nuevoabc[i]=abecedario[j];
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
