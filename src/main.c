#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/cifrado.h"
#include "../include/codificacion.h"
#define MAXIMO 1024

int validarllave(char llave[MAXIMO]);
char validartipo(char tipo[]);
void validarCadena(char cadena[MAXIMO]);
int llave ;
char llavec[MAXIMO]={0};
char cadena[MAXIMO]={0};
char tipo[10]={0};
char tipoValido;
char alfabetonuevo[MAXIMO]={0};

int  main(int argc, char *argv[] ){

    if(argc <= 1){
    	printf("TIPO DE CIFRADO: ");
	    scanf("%s",tipo);
	    tipoValido=validartipo(tipo);
	    switch(tipoValido){
	    	case 'C':
                fflush( stdin );
                printf("\t\t\t\t\tCIFRADO CICLICO: \n\n");
	    		printf("ingrese la llave numerica: ");
			    scanf("%s",llavec);
		        llave= validarllave(llavec);
                fflush( stdin );
                printf("Introducir mensaje:");
                scanf(" %500[^\n]",cadena);
                validarCadena(cadena);
                printf("La cadena encriptado es:\n %s \n", cifradoCiclico(cadena, llave));
		        printf("\nMensaje cifrado en morse:\n %s \n", claveMorse( cadena));
	    		break;
	    	case 'A':
	    		printf("\n\t\t\t\t\tCIFRADO AUTOLLAVE\n");
                printf("Introducir texto:");
                scanf(" %500[^\n]",cadena);
                validarCadena(cadena);
                fflush( stdin );
                printf("Introducir contrasena para cifrar:");
                scanf(" %500[^\n]",alfabetonuevo);
                validarCadena(alfabetonuevo);
                printf("TEXTO SIN ENCRIPTAR: \t %s \n",alfabetonuevo);
                printf("TEXTO ENCRIPTADO: %s \n",cifradoAutollave(cadena,alfabetonuevo));
	    		break;
	    	case 'P':
                printf("\n\t\t\t\t\tCIFRADO CONTRASENA\n");
                printf("Introducir texto:");
                scanf(" %500[^\n]",cadena);
                validarCadena(cadena);
                fflush( stdin );
                printf("Introducir nuevo alfabeto para cifrar:");
                scanf(" %500[^\n]",alfabetonuevo);
                validarCadena(alfabetonuevo);
                printf("TEXTO SIN ENCRIPTAR: \t %s \n",alfabetonuevo);
                printf("TEXTO ENCRIPTADO: %s \n ",cifradoContrasena(cadena,alfabetonuevo));
	    		break;
	    }
	}else if (argc<=3){
	    printf("\nle falto un argumento \n la cantidad correcta de argumentos: 3 \n llave  \n cadena  \n tipo de cicfrado  \n");
	}else if (argc<=4){
        tipo[0]=toupper(argv[3][1]);
		tipoValido=validartipo(tipo);
        validarCadena(argv[2]);
	    if (atoi(argv[1])!=0 && tolower(tipoValido)=='c' ){
            printf("\t\t\t\t\tCIFRADO CICLICO: \n\n");
            printf("La cadena encriptado es:\n %s \n", cifradoCiclico(argv[2], atoi(argv[1])));
            printf("\nMensaje cifrado en morse:\n %s \n", claveMorse( argv[2]));
        }else if(atoi(argv[1])!=0){
                printf("contrasena ingresa incorrecta debe ser texto \n usted ingreso : %s \n " ,argv[1]);
        }else{
            switch(toupper(tipoValido)){
                case 'A':
                    printf("\n\t\t\t\t\tCIFRADO AUTOLLAVE\n");
                    printf("TEXTO SIN ENCRIPTAR: \t %s \n",argv[2]);
                    printf("TEXTO ENCRIPTADO: %s \n",cifradoAutollave(argv[2],argv[1]));
                    break;
                case 'P':
                    printf("\n\t\t\t\t\tCIFRADO CONTRASENA\n");
                    printf("TEXTO SIN ENCRIPTAR: \t %s \n",argv[2]);
                    printf("TEXTO ENCRIPTADO: %s \n ",cifradoContrasena(argv[2],argv[1]));
                    break;
                }
            }
        
	}else{
		printf("no ingreso la cantidad correcta de argumentos: 3 \n llave  \n cadena  \n tipo de cifrado \n");
	}
	return 0;
}





/* implementacion de cierta funciones */
char validartipo(char tipo[]){
    int bandera=0;
    while(bandera == 0)
    {
        if(strlen(tipo)>1 ){
            printf("\n\nDebe ingresar solo una letra!");
            printf("\nIngrese el tipo de cifrado correctamente: ");
            scanf("%s", tipo);
        }else if ( tipo[0]!='C' && tipo[0] != 'A' && tipo[0] != 'P'){
        	printf("\n\nla letra ingresada es incorrecta!");
            printf("\nIngrese el tipo de cifrado correctamente: ");
            scanf("%s", tipo);
        }else{
        	bandera=1;
        }
    }
    return tipo[0];


}
void validarCadena(char cadena[MAXIMO]){
    while(strlen(cadena)<1){
        printf("Introducir mensaje correcto:");
        fflush( stdin );
        scanf(" %1024[^\n]", tipo);
        
    }
}
int validarllave(char llave[MAXIMO]){
    int llaveNum=0;
    while(llaveNum == 0)
    {
        llaveNum = atoi(llave);
        if(llaveNum == 0){
            printf("\n\nLlave numérica incorrecta!");
            printf("\nIngrese la llave numérica: ");
            scanf("%s", llave);
        }
    }
    return llaveNum;
}


