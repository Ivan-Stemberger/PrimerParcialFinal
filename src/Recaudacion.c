#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tipo.h"
#include "Contribuyente.h"
#include "Recaudacion.h"
#include "Validaciones.h"
#include "Informes.h"


int initRecaudacion(Recaudacion* list[], int len)
{
    int i;

    for(i=0;i<len;i++)
    {
    	list[i] = (Recaudacion*)malloc(sizeof(Recaudacion));

        (*list[i]).id = 0;
        (*list[i]).idContribuyente = 0;
        (*list[i]).mes = 0;
        (*list[i]).tipo.id = 0;
        (*list[i]).importe = 0;
        strcpy((*list[i]).estado,"");

    }

    return 1;
}


int alta_Recaudacion(Recaudacion* list[], Contribuyente* listContribuyente[], int len, int lenContribuyente)
{
    char aux[51];
    int id;
    int mes;
    int tipo;
    int importe;
    int error = 1;
    int flag = 0;

    if(list!=NULL && listContribuyente!=NULL && len>0 && lenContribuyente>0)
    {
    	do
            {
                printf("Por favor introduzca el ID del contribuyente.\n");
                fflush(stdout);
                scanf("%s",aux);
                if(esNumerico(aux) && encontrar_Contribuyente(listContribuyente,lenContribuyente,atoi(aux)))
                {
                	id = atoi(aux);
                	flag = 1;

                }
            }while(flag!=1);



            do
            {
                printf("Por favor introduzca el mes.\n");
                fflush(stdout);
                scanf("%s",aux);
                if(validacionMes(aux))
                {
                    mes = atoi(aux);

                }
            }while(!validacionMes(aux));


            do
            {
                 printf("Por favor introduzca el tipo.\n"
                        "1) ARBA.\n"
                        "2) IIBB.\n"
                        "3) GANANCIAS\n");
                 fflush(stdout);
                scanf("%d",&tipo);

            }while(tipo<1 || tipo>3);

            do
            {
                printf("Por favor introduzca el importe.\n");
                fflush(stdout);
                scanf("%s",aux);
                if(esNumerico(aux))
                {
                    importe = atof(aux);
                }
            }while(!esNumerico(aux));

            agregarRecaudacion(list, len, id, mes, tipo, importe);

            error = 0;


    }


    return error;
}



int agregarRecaudacion(Recaudacion* list[], int len, int id, int mes, int tipo, float importe)
{
    int i;
    int error = 0;

    if(list != NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if((*list[i]).id != 0)
            {
                (*list[i]).id = i + 100;
                setIdContribuyente(list[i],id);
                setMes(list[i], mes);
                setTipo(list[i],tipo);
                setImporte(list[i],importe);
                error = 1;
            }
        }
    }
    return error;
}

int encontrar_Recaudacion(Recaudacion* list[], int len,int id)
{
    int i;
    int found = 0;

    for(i=0;i<len;i++)
    {
        if((*list[i]).id == id)
        {
            found = i;
        }
    }
    return found;
}

int bajaContribuyente(Contribuyente* list[], Recaudacion* listRecaudacion[],int len, int lenRecaudacion)
{
    int id;
    int i;
    int opcion;
    int posicion;
    int error = 0;
    //char aux[51];

    printf("Por favor introduzca el ID del contribuyente que desea dar de baja.\n");
    fflush(stdout);
    scanf("%d",&id);

    if(encontrar_Contribuyente(list, len, id) != 0)
    {
        printf("ID Recaudacion || ID Contribuyente || Mes || Tipo || Importe || Estado\n");
    	for(i=0;i<lenRecaudacion;i++)
        {
        	if((*listRecaudacion[i]).idContribuyente == id)
        	{
        		imprimirRecaudacion(listRecaudacion[i]);
        	}
        }

    	printf("Por favor confirme si quiere eliminar al contribuyente y sus recaudaciones.\n"
    			"1) Si\n"
    			"2) No\n");
    	fflush(stdout);
    	scanf("%d",&opcion);

    	if(opcion == 1)
    	{
    		posicion = encontrar_Contribuyente(list, len, id);
    		for(i=0;i<lenRecaudacion;i++)
    		{
				if((*listRecaudacion[i]).idContribuyente == id)
				{
					borrarRecaudacion(listRecaudacion[i]);
				}
    		}

			borrarContribuyente(list[posicion]);
			error = 1;
    	}


    }
    return error;

}

void borrarRecaudacion(Recaudacion* recaudacion)
{
	(*recaudacion).id = 0;
	(*recaudacion).idContribuyente = 0;
	(*recaudacion).mes = 0;
	(*recaudacion).tipo.id = 0;
	(*recaudacion).importe = 0;
	strcpy((*recaudacion).estado,"");
}
int refinanciar(Recaudacion* list[], Contribuyente* listContribuyente[], int lenRecaudacion, int lenContribuyente)
{

	int id;
	int recaudacion;
	int contribuyente;
	char aux[4];
	int confirmacion;
	int refinanciado = 0;

	if(list !=NULL && listContribuyente != NULL && lenRecaudacion>0 && lenContribuyente>0)
	{
		do
		{
			printf("Por favor introduzca el ID de la recaudacion a refinanciar.\n");
			fflush(stdout);
			scanf("%s",aux);
		}while(esNumerico(aux));

		id = atoi(aux);

		recaudacion = encontrar_Recaudacion(list,lenRecaudacion,id);
		contribuyente = encontrar_Contribuyente(listContribuyente,lenContribuyente,(*list[recaudacion]).idContribuyente);

		imprimirContribuyente(listContribuyente[contribuyente]);

		do
		{
			printf("Por favor confirme si quiere refinanciar.\n"
					"1) Si\n"
					"2) No\n");
			fflush(stdout);
			scanf("%d",&confirmacion);
		}while(confirmacion != 1 && confirmacion != 2);

		if(confirmacion == 1)
		{
			strcpy((*list[recaudacion]).estado,"Refinanciar");
			fflush(stdout);
			refinanciado = 1;
		}

	}

	return refinanciado;
}

int saldarRecaudacion(Recaudacion* list[], Contribuyente* listContribuyente[], int lenRecaudacion, int lenContribuyente)
{

	int id;
	int recaudacion;
	int contribuyente;
	char aux[4];
	int confirmacion;
	int saldado = 0;

	if(list !=NULL && listContribuyente != NULL && lenRecaudacion>0 && lenContribuyente>0)
	{
		do
		{
			printf("Por favor introduzca el ID de la recaudacion a saldar.\n");
			fflush(stdout);
			scanf("%s",aux);
		}while(esNumerico(aux));

		id = atoi(aux);

		recaudacion = encontrar_Recaudacion(list,lenRecaudacion,id);
		contribuyente = encontrar_Contribuyente(listContribuyente,lenContribuyente,(*list[recaudacion]).idContribuyente);
		printf("id  ||  nombre  ||  apellido  ||  cuil\n");
		fflush(stdout);

		imprimirContribuyente(listContribuyente[contribuyente]);

		do
		{
			printf("Por favor confirme si quiere saldar esta recaudacion.\n"
					"1) Si\n"
					"2) No\n");
			fflush(stdout);
			scanf("%d",&confirmacion);
		}while(confirmacion != 1 && confirmacion != 2);

		if(confirmacion == 1)
		{
			strcpy((*list[recaudacion]).estado,"Saldado");
			saldado = 1;
		}

	}

	return saldado;
}


void setIdContribuyente(Recaudacion* Recaudacion,int id)
{
    (*Recaudacion).idContribuyente = id;

}

void setMes(Recaudacion* Recaudacion,int mes)
{
    (*Recaudacion).mes = mes;

}

void setTipo(Recaudacion* Recaudacion,int tipo)
{

    (*Recaudacion).id = tipo;

}

void setImporte(Recaudacion* Recaudacion,float importe)
{
    (*Recaudacion).importe = importe;

}


