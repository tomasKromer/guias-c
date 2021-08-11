/*
 ============================================================================
 Name        : entradaysalida.c
 Author      : tomaskromer
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ejercicio_1a(void);
void ejercicio_1b(void);
void ejercicio_1c(void);
void ejercicio_1d(void);
void ejercicio_1e(void);
void ejercicio_1f(void);
void ejercicio_1g(void);
void ejercicio_1h(void);
void ejercicio_1i(void);
void ejercicio_1j(void);

//ejercicio 2
void ejercicio_2_1(void);
void ejercicio_2_2(void);
void ejercicio_2_3(void);

//ejercicio control
void ejercicio_control_1(void);
void ejercicio_control_2(void);

int main(void)
{
/*
	//Ejercicio 1
	ejercicio_1a();
	ejercicio_1b();
	ejercicio_1c();
	ejercicio_1d();
	ejercicio_1e();
	ejercicio_1f();
	ejercicio_1g();
	ejercicio_1h();
	ejercicio_1i();
	ejercicio_1j();

	//Ejercicio 2
	ejercicio_2_1();
	ejercicio_2_2();
	ejercicio_2_3();

	//Ejercicio Control
	ejercicio_control_1();*/
	ejercicio_control_2();

	return EXIT_SUCCESS;
}

void ejercicio_1a(void)
{
	int i, j;
	float x;
	double dx;

	printf("Ejercicio 1a\n");

	i = 102;
	j = -56;
	x = 12.687;
	dx = 0.000000025;

	printf("i: %.4d j: %.4d x: %14.8e dx: %14.8e", i, j, x, dx);
}

void ejercicio_1b(void)
{
	int i, j;
	float x;
	double dx;

	printf("\nEjercicio 1b\n");

	i = 102;
	j = -56;
	x = 12.687;
	dx = 0.000000025;

	printf("i: %.4d \nj: %.4d \nx: %14.8e \ndx: %14.8e", i, j, x, dx);
}

void ejercicio_1c(void)
{
	int i = 102;
	int j = -56;
	long ix = -158693157400;
	unsigned u = 35460;
	float x = 12.687;

	printf("\nEjercicio 1c\n");

	printf("i: %.5d \nj: %.5d \nix: %.12ld \nu: %.5u \n x:%10.5f", i, j, ix, u, x);
}

void ejercicio_1d(void)
{
	int i = 102;
	int j = -56;
	long ix = -158693157400;
	unsigned u = 35460;
	float x = 12.687;

	printf("\nEjercicio 1d\n");

	printf("i: %.5d j: %.5d ix: %.12ld \n\nu: %.5u \n x:%10.5f", i, j, ix, u, x);
}

void ejercicio_1e(void)
{
	int i = 102;
	unsigned u = 35460;
	char c = 'C';

	printf("\nEjercicio 1e\n");

	printf("i: %.6d\tu: %.6u\tc: %c", i, u, c);
}

void ejercicio_1f(void)
{
	int j = -56;
	unsigned u = 35460;
	float x = 12.687;

	printf("\nEjercicio 1f\n");

	printf("j: %.5d\tu: %.5u\tx: %05.11f", j, u, x);
}

void ejercicio_1g(void)
{
	int j = -56;
	unsigned u = 35460;
	float x = 12.687;

	printf("\nEjercicio 1g\n");

	printf("j: %-5d\tu: %-5u\tx: %-5.11f", j, u, x);
}

void ejercicio_1h(void)
{
	int j = -56;
	unsigned u = 35460;
	float x = 12.687;


	printf("\nEjercicio 1h\n");

	printf("j: %+-5d\tu: %5u\tx: %+-5.11f", j, u, x);
}

void ejercicio_1i(void)
{
	int j = -56;
	unsigned u = 35460;
	float x = 12.687;


	printf("\nEjercicio 1i\n");


	printf("j: %+-.5d\tu: %-.5u\tx: %-5.11f", j, u, x);
}

void ejercicio_1j(void)
{
	int j = -56;
	unsigned u = 35460;
	float x = 12.687;

	printf("\nEjercicio 1j\n");

	printf("j: %+-.5d\tu: %-.5u\tx: %+-5.1f", j, u, x);
}

void ejercicio_2_1(void)
{
	char nombre[30];

	printf("\nIngrese su nombre:\n");
	scanf("%s", nombre);

	printf("\n Bienvenido %s\n", nombre);
}

void ejercicio_2_2(void)
{
	float valor1;
	float valor2;

	printf("\nIngrese su valor 1:\n");
	scanf("%f", &valor1);

	printf("\nIngrese su valor 2:\n");
	scanf("%f", &valor2);

	printf("\n x1 = %1.1f x2 = %1.1f\n", valor1, valor2);
}


void ejercicio_2_3(void)
{
	int valor1;
	int valor2;

	printf("\nIngrese su valor 1:\n");
	scanf("%d", &valor1);

	printf("\nIngrese su valor 2:\n");
	scanf("%d", &valor2);

	printf("\nSuma = %d\n", valor1 + valor2);
}

void ejercicio_control_1(void)
{
	int invertirCaracteres = 0;
	int i;
	char bufferDatos[80];
	int out = 0;

	while(out != -1)
	{
		for(i=0;i<80;i++)
		{
			bufferDatos[i] = '\n';
		}

		scanf("%c", &bufferDatos[0]);
		printf("\nIngrese su texto de maximo 80 caracteres (cuando desee termina ingrese un enter):\n");
		for(i=0; i<80; i++)
		{
			scanf("%c", &bufferDatos[i]);
			if(bufferDatos[i] == '\n')
			{
				invertirCaracteres = i;
				break;
			}
		}

		printf("\nEl texto invertido es:\n");
		for(i=invertirCaracteres;i>=0; i--)
		{
			printf("%c",bufferDatos[i]);
		}
		printf("\n\n");
		printf("\nSi desea repetir ingrese un numero distinto de -1:\n");
		scanf("%d",&out);
	}
}

/*
int calculo(int interes,int n)
{
	int result;

	result = 0;

	if(n != -1)
	{
		result = (1 + (interes/100))^n;
		return result + calculo(interes, n-1);
	}

	return result;
}*/

#define TIEMPO 30//En años
#define INTERES 6//Interes anual

int potenciacion(int anios)
{
	int partialSum;
	int k;

	partialSum = 0;

	for(k=1;k<anios;k++)
	{
		partialSum = ((1+(INTERES/100))^k) + partialSum;

	}

	return partialSum;
}

void ejercicio_control_2(void)
{
	int dinero;
	int dineroTotal;
	int dineroBuscado = 0;
	int dineroNecesario = 0;
	int valorInteres;
	int acumulado[TIEMPO - 1];
	int i;

	printf("\nIngrese el dinero: \n");
	scanf("%d", &dinero);

	valorInteres = potenciacion(TIEMPO);

	while(dineroBuscado < 100000)
	{
		dineroBuscado = dineroNecesario * valorInteres;
		dineroNecesario++;
	}

	for(i=1;i<TIEMPO;i++)
	{
		acumulado[i-1] = dinero * potenciacion(i);
		printf("---------------------------------------------------------------\n");
		printf("Dinero %d -------------  Años %d ------ Acumulado %d ----------\n", dinero, i, acumulado[i-1]);
	}

	dineroTotal = dinero * valorInteres;

	printf("-----------------------------------------------------\n");
	printf("Dinero para 100mil en 30 años $ %d --------------------\n", dineroNecesario);

	printf("-----------------------------------------------------\n");
	printf("Con $ %d dolares en 30 años son $ %d ------- ", dinero,dineroTotal);
}
