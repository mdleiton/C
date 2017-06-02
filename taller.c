#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "./src/cifrado.c"
#include "./src/codificacion.c"
#define MAXIMO 1024

int validarllave(char llave[MAXIMO]);
char validartipo(char tipo[]);

int  main(int argc, char *argv[] ){
    int llave ;
    char llavec[MAXIMO];
    char cadena[MAXIMO];
    memset(cadena,0,MAXIMO);
    char tipo[10];
    char tipoValido;
    if(argc <= 1){
    	printf("TIPO DE CIFRADO: ");
	    scanf("%s",tipo);
	    tipoValido=validartipo(tipo);
	    switch(tipoValido){
	    	case 'C':
	    		printf("\t\t\t\t\tCIFRADO CICLICO:\n");
	    		printf("ingrese la llave numerica: ");
			    scanf("%s",llavec);
		        llave= validarllave(llavec);
		        memset(llavec,0,MAXIMO);

			    printf("Introducir mensaje: ");
			    fgets(cadena,MAXIMO,stdin);
		        printf("\nLa cadena encriptado es:\n%s\n", cifradoCiclico(cadena, llave));
		        printf("\nMensaje cifrado en morse:\n%s\n", claveMorse( cadena));
	    		break;
	    	case 'A':
	    		printf("\nAUTOLLAVE\n");
	    		break;
	    	case 'P':
	    		printf("con contrasena");
	    		break;
	    }
	}else if (argc<=3){
	    printf("\nle falto un argumento \n la cantidad correcta de argumentos: 3 \n llave  \n cadena  \n tipo de cicfrado  \n");
	}else if (argc<=4){
		tipoValido=validartipo(argv[3]);
	    llave= validarllave(argv[1]);
        printf("\nMensaje cifrado:\n%s\n", cifradoCiclico( argv[2], llave));
        printf("\nMensaje cifrado en morse:\n%s\n", claveMorse( argv[2]));
	}else{
		printf("no ingreso la cantidad correcta de argumentos: 3 \n llave  \n cadena  \n tipo de cicfrado \n");
	}
	return 0;
}

char validartipo(char tipo[]){
    int bandera=0;
    while(bandera == 0)
    {
        if(strlen(tipo)>1 ){
            printf("\n\nDebe ingresar solo una letra!");
            printf("\nIngrese el tipo de cifrado correctamente: ");
            scanf("%s", tipo);
            tipo[0]=tolower(tipo[0]);
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



