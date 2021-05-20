#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Informes.h"
#include "Tipo.h"
#include "Recaudacion.h"
#include "Contribuyente.h"
#include "Validaciones.h"

int listarContribuyentes(Contribuyente* list[], Recaudacion* listRecaudacion[],int len, int lenRecaudacion)
{
	int i;
	int j;
	int error = 0;

	if(list != NULL && listRecaudacion != NULL && len > 0 && lenRecaudacion > 0)
	{
		printf("id || nombre || apellido || cuil || id Recaudacion\n");
		fflush(stdout);

		for(i=0;i<len;i++)
		{
			for(j=0;j<lenRecaudacion;j++)
			{
				if((*listRecaudacion[j]).idContribuyente == (*list[i]).id)
				{
					imprimirListadoContribuyentes(list[i], listRecaudacion[j]);
				}
			}

		}
		error = 1;
	}
	return error;
}

int listarRecaudaciones(Contribuyente* list[], Recaudacion* listRecaudacion[],int len, int lenRecaudacion)
{
	int i;
	int posicion;
	int error = 0;

	if(list != NULL && listRecaudacion != NULL && len > 0 && lenRecaudacion > 0)
	{
		printf("id || id contribuyente || tipo || importe || estado || cuil contribuyente || nombre contribuyente\n");
		fflush(stdout);
		for(i=0;i<lenRecaudacion;i++)
		{
			if(strcmp((*listRecaudacion[i]).estado,"Saldado") == 0)
			{
				posicion = encontrar_Contribuyente(list,len,(*listRecaudacion[i]).idContribuyente);

				imprimirListadoRecaudaciones(list[posicion], listRecaudacion[i]);
			}

		}
		error = 1;
	}

	return error;

}


void imprimirContribuyente(Contribuyente* contribuyente)
{
	printf("%d, %s, %s, %s\n",(*contribuyente).id,(*contribuyente).nombre,(*contribuyente).apellido,(*contribuyente).cuil);
	fflush(stdout);
}


void imprimirListadoContribuyentes(Contribuyente* contribuyente, Recaudacion* recaudacion)
{
	printf("%d, %s, %s, %s\n, %d",(*contribuyente).id,(*contribuyente).nombre,(*contribuyente).apellido,(*contribuyente).cuil,(*recaudacion).id);
	fflush(stdout);
}

void imprimirListadoRecaudaciones(Contribuyente* contribuyente, Recaudacion* recaudacion)
{
	printf("%d, %d, %d, %f, %s, %s, %s", (*recaudacion).id,(*recaudacion).idContribuyente,(*recaudacion).tipo.id,(*recaudacion).importe,(*recaudacion).estado,(*contribuyente).cuil,(*contribuyente).nombre);
	fflush(stdout);
}

void imprimirRecaudacion(Recaudacion* recaudacion)
{
	printf("%d, %d, %d, %d, %f,%s\n",(*recaudacion).id,(*recaudacion).idContribuyente,(*recaudacion).mes,(*recaudacion).tipo.id, (*recaudacion).importe,(*recaudacion).estado);
	fflush(stdout);
}

void recaudacionesRefinanciadas(Contribuyente* listContribuyente[], Recaudacion* listRecaudacion[], int len, int lenRecaudacion)
{
	int i;
	int j;
	int recaudaciones = 0;
	int recaudacionesFinal = 0;
	Contribuyente* contribuyenteAux;

	if(listContribuyente!=NULL && listRecaudacion!=NULL && len>0 && lenRecaudacion>0)
	{
		for(i=0;i<len;i++)
		{
			for(j=0;i<lenRecaudacion;i++)
			{
				if((*listRecaudacion[j]).idContribuyente == (*listContribuyente[i]).id && strcmp((*listRecaudacion[j]).estado,"Refinanciado")== 0)
				{
					recaudaciones++;
				}
			}
			if(recaudaciones > recaudacionesFinal)
			{
				recaudacionesFinal = recaudaciones;
				contribuyenteAux = listContribuyente[i];
			}
		}

		printf("ID || Nombre || Apellido || CUIL\n");
		fflush(stdout);
		imprimirContribuyente(contribuyenteAux);
	}

}

void recaudacionesSaldadas(Recaudacion* listRecaudaciones[],int len)
{
	int i;
	int cantidad = 0;

	if(listRecaudaciones!= NULL && len<0)
	{
		for(i=0;i<len;i++)
		{
			if(strcmp((*listRecaudaciones[i]).estado,"Saldado")==0 && (*listRecaudaciones[i]).importe > 1000)
			{
				cantidad++;
			}
		}
		printf("La cantidad de recaudaciones mayores a 1000 es: %d",cantidad);
		fflush(stdout);
	}

}

void informarDatosContribuyentes(Contribuyente* listContribuyente[], Recaudacion* listRecaudacion[], int len, int lenRecaudacion)
{
	int i;
	int j;
	int tipo;

	if(listContribuyente!=NULL && listRecaudacion!=NULL && len>0 && lenRecaudacion>0)
	{
		do
		{
			printf("Indique el tipo de recaudacion\n"
					"1)ARBA\n"
					"2)IIBB\n"
					"3)GANANCIAS\n");
			scanf("%d",&tipo);
		}while(tipo<1 && tipo>3);


		for(i=0;i<len;i++)
		{
			for(j=0;j<lenRecaudacion;j++)
			{
				if((*listRecaudacion[j]).tipo.id == tipo && (*listRecaudacion[j]).idContribuyente == (*listContribuyente[i]).id)
				{
					imprimirContribuyente(listContribuyente[i]);
				}
			}
		}
	}

}

void contribuyentesFebrero(Contribuyente* listContribuyente[], Recaudacion* listRecaudacion[], int len, int lenRecaudacion)
{
	int i;
	int j;

	if(listContribuyente!=NULL && listRecaudacion!=NULL && len>0 && lenRecaudacion>0)
	{
		printf("Nombre || CUIL\n");

		for(i=0;i<len;i++)
		{
			for(j=0;j<lenRecaudacion;j++)
			{
				if((*listRecaudacion[j]).mes == 2 && (*listRecaudacion[j]).idContribuyente == (*listContribuyente[i]).id)
				{
					imprimir_nombreYCuil(listContribuyente[i]);
				}
			}
		}
	}
}

void imprimir_nombreYCuil(Contribuyente* contribuyente)
{
			printf("%s, %s\n",(*contribuyente).nombre,(*contribuyente).cuil);
			fflush(stdout);
}
