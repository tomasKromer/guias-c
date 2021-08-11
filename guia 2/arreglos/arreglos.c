/*
 * arreglos.c
 *
 *  Created on: 10 ago. 2021
 *      Author: kromer
 */

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

enum _tipoOrdenamiento
{
	Menor_a_Mayor,
	Mayor_a_Menor,
	VA_Menor_a_Mayor,
	VA_Mayor_a_Menor
};
typedef enum _tipoOrdenamiento Ordenamiento_t;

void ordenar(float a[],int n,Ordenamiento_t tipoOrdenamiento);

//Ejercicio 1
void ejercicio1();
//Ejercicio 3
void ejercicio3();



int main()
{
	//ejercicio1();
	ejercicio3();

	return 0;
}

int cantCartas;

void cartaVa(int cartasRepetido[][],int puntosJugador)
{
	int i,j;
	int dec;

	do
	{
		i = rand() % 4;
		j = rand() % 12;
	}while((cartasRepetido[i][j] == 1) && (cantCartas < 48));

	cantCartas++;

	cartasRepetido[i][j] = 1;

	switch(i)
	{
	case 0:
		printf("\nSalio un %d de corazones\n",j);
		break;
	case 1:
		printf("\nSalio un %d de rubi\n",j);
		break;
	case 2:
		printf("\nSalio un %d de trebol\n",j);
		break;
	case 3:
		printf("\nSalio un %d de pica\n",j);
		break;
	default:
		printf("\nACA NO DEBERIAMOS ESTAR\n");
		break;
	}

	if(j==0)
	{
		printf("\nPara el As, quiere que sea 1 o 11\n");
		printf("\nIngrese '0' para valor 1.\n Ingrese cualqueir valor para 11.\n");
		scanf("%d", &dec);
		if(dec == 0)
		{
			puntosJugador = puntosJugador + 1;
		}
		else
		{
			puntosJugador = puntosJugador + 11;
		}
	}
	else
	{
		if(j>=10)
		{
			puntosJugador = puntosJugador + 10;
		}
		else
		{
			puntosJugador = puntosJugador + j;
		}
	}
}


void ejercicio3()
{
	int puntosJugadorA = 0,puntosJugadorB = 0;
	int cartasRepetido[4][12] ={0};
	int comenzar = 0;
	int i,j;
	int dec;
	time_t t;
	int repitioJ1;
	int repJ1;
	int repitioJ2;
	int repJ2;
	int perdA,perdB;
	int ganA,ganB;

	repitioJ1 = 1;
	repitioJ2 = 1;

	cantCartas = 0;

	srand((unsigned) time(&t));

	while(comenzar == 0)
	{
		printf("\nCOMIENZA EL JUEGO\n");

		printf("\n1er Carta Jugador 1\n");

		cartaVa(cartasRepetido, puntosJugadorA);

		printf("\n1er Carta Jugador 2\n");

		cartaVa(cartasRepetido, puntosJugadorB);

		printf("\n2da Carta Jugador 1\n");

		cartaVa(cartasRepetido, puntosJugadorA);

		printf("\n2da Carta Jugador 2\n");

		cartaVa(cartasRepetido, puntosJugadorB);

		ganA = (puntosJugadorA == 21);
		ganB = (puntosJugadorB == 21);
		perdA = (puntosJugadorA > 21);
		perdB = (puntosJugadorB > 21);

		if(perdA || perdB)
		{
			if(perdA)
			{
				printf("\nPerdio jugador A, Gano B\n");
			}
			else if(perdB)
			{
				printf("\nPerdio jugador B, Gano A\n");
			}
		}
		else if(ganA || ganB)
		{
			if(ganA && ganB)
			{
				printf("\nEMPATE!!!!\n");
			}
			else if(ganA)
			{
				printf("\nGano jugador A, Perdio B\n");
			}
			else if(ganB)
			{
				printf("\nGano jugador B, Perdio A\n");
			}
		}
		else
		{
			do{
				if(repitioJ1)
				{
					printf("\nJugador 1 desea una carta mas? '0' si desea repetir\n");
					scanf("%d", repJ1);
					if(repJ1)
					{
						cartaVa(cartasRepetido, puntosJugadorA);
						ganA = (puntosJugadorA == 21);
						perdA = (puntosJugadorA > 21);
						if(perdA)
						{
							printf("\nPerdio jugador A, Gano B\n");
						}
						else if(ganA)
						{
							printf("\nGano jugador A, perdio B\n");
						}
					}
					else
					{
						repitioJ1 = 0;
					}
				}

				if(repitioJ2)
				{
					printf("\nJugador 2 desea una carta mas? '0' si desea repetir\n");
					scanf("%d", repJ2);
					if(repJ2)
					{
						cartaVa(cartasRepetido, puntosJugadorB);
						ganB = (puntosJugadorB == 21);
						perdB = (puntosJugadorB > 21);
						if(perdB)
						{
							printf("\nPerdio jugador B, Gano A\n");
						}
						else if(ganB)
						{
							printf("\nGano jugador B, perdio A\n");
						}
					}
					else
					{
						repitioJ2 = 0;
					}
				}

			}while((repitioJ1==1) || (repitioJ2 == 1));
		}
	}
}


void ejercicio1()
{
	float a[]={4.7, -8.0, -2.3, 11.4, 12.9, 5.1, 8.8, -0.2, 6.0, -14.7};
	int i;
	int dec = 0;
	Ordenamiento_t ord;

	while(dec == 0)
	{
		printf("\nElija el tipo de ordenamiento\n");
		printf("\n0.Menor_a_Mayor\n1.Mayor_a_Menor\n2.VA_Menor_a_Mayor\n3.VA_Mayor_a_Menor\n");
		scanf("%d",&ord);

		printf("\nArreglo Original\n");
		for(i=0;i<(sizeof(a)/sizeof(float));i++)
		{
			printf("%f\t", a[i]);
		}

		ordenar(a,(sizeof(a)/sizeof(float)),ord);

		printf("\nArreglo Ordenado %d\n");
		for(i=0;i<(sizeof(a)/sizeof(float));i++)
		{
			printf("%f\t", a[i]);
		}

		printf("\nSi desea repetir ingrese 0\n");
		scanf("%d",&ord);
	}
}

bool ordenar_mayor_menor(float a, float b)
{
	return (b > a);
}

bool ordenar_menor_mayor(float a, float b)
{
	return (a > b);
}

void ordenar(float a[],int n,Ordenamiento_t tipoOrdenamiento)
{
	int i,j;
	float temp;

	for (i=1; i<n; i++)
	{
		for (j=0 ; j< n - 1; j++)
		{
			switch(tipoOrdenamiento)
			{
			case Menor_a_Mayor:
			{
				if(ordenar_menor_mayor(a[j], a[j+1]))
				{
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
			}
				break;
			case Mayor_a_Menor:
			{
				if(ordenar_mayor_menor(a[j], a[j+1]))
				{
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
			}
				break;
			case VA_Menor_a_Mayor:
			{

				if(ordenar_menor_mayor(fabs(a[j]), fabs(a[j+1])))
				{
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}

			}
				break;
			case VA_Mayor_a_Menor:
			{
				if(ordenar_mayor_menor(fabs(a[j]), fabs(a[j+1])))
				{
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
			}
				break;
			default:
				break;
			}
		}
	}
}
