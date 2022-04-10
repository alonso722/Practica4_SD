/*
Codigo Server implementado en suma
en este accedemos por medio de la variable argp que apunta a una estructura y de ahi
obtenemos los valores para proceder a obtener el resultado y volver a mandarlo.
*/
#include "suma.h"

int *
suma_1_svc(dupla_int *argp, struct svc_req *rqstp)
{
	static int  result;

	printf("EL procedimiento fue llamado de manera exitosa\n");
	printf("Parametros: %d %d\n",argp->a,argp->b);//accedemos a los valores de
	//la estructura y los mostramos en pantalla
	result=argp->a+argp->b;//suma
	printf("REtornando %d\n",result);
//enviamos el resultado
return &result;
}
