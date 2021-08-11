/*
 ============================================================================
 Name        : guia_3.c
 Author      : tomaskromer
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

enum {
	Goles,
	Victorias,
	Derrotas
};

typedef struct
{
	char nombre[20];
	int pg;
	int pp;
	int pe;
	int goles;
}equipo_t;

void ordenar(int ord, int cantEquipos, equipo_t * equipos);

int main(void) {

	int dec=0;
	int i,j;
	int cantEquipos;
	equipo_t * equipos, * movilidad;
	char aux;
	int ord;
	int malNombre;

	malNombre = 0;

	printf("\nBienvenido al programa de carga de equipos\n");
	printf("\nDiga cuantos equipos quiere agregar.\n");
	scanf("%d", &cantEquipos);

	equipos = malloc(cantEquipos * sizeof(equipo_t));

	movilidad = equipos;

	while(dec==0)
	{

		for(i=0;i<cantEquipos;i++)
		{
			printf("\nCargue los datos de los equipos\n");
			printf("\nEl nombre del equipo n° %d\n", i);

			scanf("%c",&aux);
			scanf("%c",&aux);
			j=0;
			while(aux != '\n')
			{
				movilidad->nombre[j] = aux;
				scanf("%c",&aux);
				j++;
			}
			if(j==0)
			{
				printf("\nError en el ingreso de nombres\n");
				malNombre = 1;
				break;
			}
			printf("\nAgregar los partidos ganados por el equipo\n");
			scanf("%d",&movilidad->pg);

			printf("\nAgregar los partidos empatados por el equipo\n");
			scanf("%d",&movilidad->pe);

			printf("\nAgregar los partidos perdidos por el equipo\n");
			scanf("%d",&movilidad->pp);

			printf("\nAgregar los goles convertidos por el equipo\n");
			scanf("%d",&movilidad->goles);

			movilidad = (equipo_t *) ((int *) movilidad + sizeof(equipo_t));
		}

		if(!malNombre)
		{
			printf("\nElijan como ordenar.\n");
			printf("0. Goles.\n");
			printf("1. Victorias.\n");
			printf("2. Derrotas.\n");
			scanf("%d", &ord);

			ordenar(ord, cantEquipos, equipos);

			movilidad = equipos;
			printf("\n---------------------TABLA----------------------");
			printf("\nNombre\t PG\t PE\t PP\t G-----------------------\n");
			for(i=0;i<cantEquipos;i++)
			{
				printf("%s\t %d\t %d\t %d\t %d\n", movilidad->nombre, movilidad->pg, movilidad->pe, movilidad->pp, movilidad->goles);

				movilidad = (equipo_t *) ((int *) movilidad + sizeof(equipo_t));
			}
		}


		printf("\nSi desea repetir el proceso ingrese '0'\n");
		scanf("%d",&dec);

		if(dec == 0)
		{
			printf("\nDiga cuantos equipos quiere agregar.\n");
			scanf("%d", &cantEquipos);
			equipos = realloc(equipos, cantEquipos * sizeof(equipo_t));
		}
	}

	printf("\nGRACIAS POR UTILIZAR EL PROGRAMA\n");

	free(equipos);
	return EXIT_SUCCESS;
}

void ordenar(int ord, int cantEquipos, equipo_t * equipos)
{
	int i;
	int j;
	equipo_t mov;
	equipo_t * aux;

	aux = equipos;

	for(i=1;i<cantEquipos;i++)
	{
		for(j = 0 ; j < cantEquipos -1; j++)
		{
			switch(ord)
			{
			case Goles:
			{
				if(aux[j].goles < aux[j+1].goles)
				{
					mov = aux[j];
					aux[j] = aux[j+1];
					aux[j+1] = mov;
				}
			}
				break;
			case Victorias:
			{
				if(aux[j].pg < aux[j+1].pg)
				{
					mov = aux[j];
					aux[j] = aux[j+1];
					aux[j+1] = mov;
				}
			}
				break;
			case Derrotas:
				if(aux[j].pp < aux[j+1].pp)
				{
					mov = aux[j];
					aux[j] = aux[j+1];
					aux[j+1] = mov;
				}
				break;
			default:
				break;
			}
		}
	}
}
