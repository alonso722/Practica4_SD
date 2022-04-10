/*
Codigo Cliente implementado de Suma
En este codigo se usa una estructura clave que cuenta con dos variables enteras 
El objetivo principal de este codigo es realizar una conexion y pasar por medio
de la estructura antes hablada 2 valores enteros y al final retornara el resultado
*/
#include "suma.h"


void
suma_prog_1(char *host,int a,int b)
{
	CLIENT *clnt;
	int  *result_1;
	dupla_int  suma_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, SUMA_PROG, SUMA_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	suma_1_arg.a=a;//asignamos el valor
	suma_1_arg.b=b;
	result_1 = suma_1(&suma_1_arg, clnt);//retorno del resultado
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else
	{
		printf("La suma es: %d\n",*result_1);
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 
}


int
main (int argc, char *argv[])
{
	char *host;
	int a,b;
	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	long arga=strtol(argv[2],NULL,10);//conversion de catacteres a entero
	long argb=strtol(argv[3],NULL,10);
	a =arga;//asignacion de valores
	b =argb;
	printf("El valor de a es %d\n",a);
	printf("El valor de b es %d\n",b);
	suma_prog_1 (host,a,b);//insersion de variables en los parametros
exit (0);
}
