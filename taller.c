#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./src/cifrado.c"
#include "./src/codificacion.c"
#define MAXIMO 1200

int validarllave(char llave[MAXIMO]);

int  main(int argc, char *argv[] ){
    int llave;
    char llavec[MAXIMO];
    char cadena[MAXIMO];
    printf("\t\t\t\t\tCIFRADO CICLICO:\n");
    if(argc <= 1){
	    printf("Introducir mensaje: ");
	    scanf("%s",cadena);
	    printf("ingrese la llave numerica: ");
	    scanf("%s",llavec);
        llave= validarllave(llavec);
        printf("\nLa cadena encriptado es:\n%s\n", cifradoCiclico(cadena, llave));
        printf("\nMensaje cifrado en morse:\n%s\n", claveMorse( cadena));
	}else if (argc<=2){
	    printf("\nle falto un argumento \n la cantidad correcta de argumentos: 2 \n llave  n cadena \n");
	}else if (argc<=3){
	    llave= validarllave(argv[1]);
        printf("\nMensaje cifrado:\n%s\n", cifradoCiclico( argv[2], llave));
        printf("\nMensaje cifrado en morse:\n%s\n", claveMorse( argv[2]));
	}else{
		printf("no ingrese la cantidad correcta de argumentos: \n llave  \n cadena \n");
	}
	return 0;
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



