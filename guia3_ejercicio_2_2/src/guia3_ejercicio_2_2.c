/*
 ============================================================================
 Name        : guia3_ejercicio_2_2.c
 Author      : tomaskromer
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 2 Guia 3
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

int main(void) {
	FILE *fp;
	char buffer;
	int cantEspacios;
	int bytesLeidos;
	int rep,i;
	int auxiliar;

	i = 0;
	rep = 0;

	while(rep==0)
	{
		cantEspacios = 0;

		printf("\nIngrese el nombre del archivo que quiere leer\n");
		printf("\n0. file.txt\n");
		printf("\n1. lorem_ipsum.txt\n");
		scanf("%d\n", &auxiliar);

		if(auxiliar == 0)
		{
			fp = fopen("file.txt", "r");
			if (!fp)
			{
				printf("¡No se pudo abrir el archivo %s!", "file.txt");
				break;
			}
		}
		else if(auxiliar == 1)
		{
			fp = fopen("lorem_ipsum.txt", "r");
			if (!fp)
			{
				printf("¡No se pudo abrir el archivo %s!", "lorem_ipsum.txt");
				break;
			}
		}
		else
		{
			printf("\nOpcion invalidad\n");
			break;
		}

		fseek(fp, 0, SEEK_SET);

		while(!feof(fp))
		{
			printf("\nPASO\n");
			bytesLeidos = fread(&buffer, sizeof(char), sizeof(buffer), fp);
			cantEspacios = buffer == ' ' ? cantEspacios + 1 : cantEspacios;
		}

		if(auxiliar == 0)
		{
			printf("\nLa cantidad de espacios en el archivo %s es de %d espacios.\n", "file.tx", cantEspacios);
		}
		else if(auxiliar == 1)
		{
			printf("\nLa cantidad de espacios en el archivo %s es de %d espacios.\n", "lorem_ipsum.txt", cantEspacios);
		}
		fclose(fp);
		printf("\nSe leyeron %d\n", bytesLeidos);

		printf("\nSi desea repetir el procedimiento con otro archivo ingrese '0'.\n");
		scanf("%d\n", &rep);
		scanf("%c\n", &buffer);
	}

	printf("\nGRACIAS POR USAR EL CODIGO\n");

	return 0;
}
