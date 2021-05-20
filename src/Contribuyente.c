#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contribuyente.h"
#include "Validaciones.h"

int initContribuyente(Contribuyente* list[], int len)
{
    int i;

    for(i=0;i<len;i++)
    {

    	list[i] = (Contribuyente*)malloc(sizeof(Contribuyente));

    	(*list[i]).id = 0;
        strcpy((*list[i]).nombre,"");
        strcpy((*list[i]).apellido,"");
        strcpy((*list[i]).cuil,"");

    }

    return 1;
}

int alta_Contribuyente(Contribuyente* list[], int len)
{
    char aux[51];
    char nombre[51];
    char apellido[51];
    char cuil[14];
    int error = 0;

	if(list != NULL && len>0)
	{
		do
		{
			printf("Por favor introduzca el nombre.\n");
			fflush(stdout);
			scanf("%s",aux);
			if(soloLetras(aux))
			{
				strcpy(nombre,aux);
			}
		}while(!soloLetras(aux));

		do
		{
			printf("Por favor introduzca el apellido.\n");
			fflush(stdout);
			scanf("%s",aux);
			if(soloLetras(aux))
			{
				strcpy(apellido,aux);
			}
		}while(!soloLetras(aux));

		do
		{
			printf("Por favor introduzca el cuil.\n");
			fflush(stdout);
			scanf("%s",aux);
			if(validarCuil(aux))
			{
				strcpy(cuil,aux);
			}
		}while(!validarCuil(aux));

		agregarContribuyente(list, len, nombre, apellido, cuil);

		error = 1;
	}


    return error;
}



int agregarContribuyente(Contribuyente* list[], int len, char nombre[],char apellido[],char cuil[])
{
    int i;
    int error = 0;

    if(list != NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if((*list[i]).id == 0)
            {
                (*list[i]).id = i+1000;
                setNombre(list[i],nombre);
                setApellido(list[i],apellido);
                setCuil(list[i],cuil);
                error = 1;
            }
        }
    }
    return error;
}

int encontrar_Contribuyente(Contribuyente* list[], int len,int id)
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

int modificar_Contribuyente(Contribuyente* list[],int len)
{
    int id;
    int opcion;
    int posicion;
    int error = 0;
    char aux[51];

    printf("Por favor introduzca el ID del contribuyente que desea modificar.\n");
    fflush(stdout);
    scanf("%d",&id);

    if(encontrar_Contribuyente(list, len, id) != 0)
    {
        posicion = encontrar_Contribuyente(list, len, id);

        printf("Indique que campo desea modificar\n"
        "1)Nombre.\n"
        "2)Apellido.\n"
        "3)Cuil.\n");
        fflush(stdout);

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
            {
                do
                {
                    printf("Por favor ingrese el nuevo nombre");
                    fflush(stdout);
                    scanf("%s",aux);
                }while(!soloLetras(aux));
                setNombre(list[posicion],aux);
                error = 1;
                break;

            }
            case 2:
            {
                do
                {
                    printf("Por favor ingrese el nuevo apellido");
                    fflush(stdout);
                    scanf("%s",aux);
                }while(!soloLetras(aux));
                setApellido(list[posicion],aux);
                error = 1;
                break;
            }
            case 3:
            {
                do
                {
                    printf("Por favor ingrese el nuevo nombre");
                    fflush(stdout);
                    scanf("%s",aux);
                }while(!soloLetras(aux));
                setNombre(list[posicion],aux);
                error = 1;
                break;
            }
        }
    }

    return error;

}

void borrarContribuyente(Contribuyente* contribuyente)
{
    (*contribuyente).id = 0;
    setNombre(contribuyente,"");
    setApellido(contribuyente,"");
    setCuil(contribuyente,"");
}

void setNombre(Contribuyente* contribuyente,char nombre[])
{
    strcpy((*contribuyente).nombre,nombre);

}

void setApellido(Contribuyente* contribuyente,char apellido[])
{

    strcpy((*contribuyente).apellido,apellido);

}

void setCuil(Contribuyente* contribuyente,char cuil[])
{
    strcpy((*contribuyente).cuil,cuil);
}

