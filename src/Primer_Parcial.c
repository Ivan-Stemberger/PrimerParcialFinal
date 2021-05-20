#include <stdio.h>
#include <stdlib.h>
#include "Contribuyente.h"
#include "Recaudacion.h"
#include "Tipo.h"
#include "Informes.h"
#define len 1


int main()
{

    int opcion;
    Contribuyente* listaContribuyentes[len];
    Recaudacion* listaRecaudaciones[len];
    initContribuyente(listaContribuyentes, len);
    initRecaudacion(listaRecaudaciones, len);

    do
    {


    	printf("Elija una de las siguientes opciones.\n"
               "1) Alta de contribuyente.\n"
               "2) Modificar datos del contribuyente.\n"
               "3) Baja de contribuyente.\n"
               "4) Recaudacion.\n"
               "5) Refinanciar Recaudacion.\n"
               "6) Saldar recaudacion.\n"
               "7) Imprimir contribuyentes.\n"
               "8) Imprimir recaudacion.\n"
               "9) Informes.\n"
               "10)Salir\n\n");
    	fflush(stdout);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
            {
                if(alta_Contribuyente(listaContribuyentes, len))
                {
                    printf("El contribuyente ha sido cargado.\n");
                    fflush(stdout);
                }

                break;
            }
            case 2:
            {
                if(modificar_Contribuyente(listaContribuyentes,len))
                {
                    printf("El contribuyente ha sido modificado.\n");
                    fflush(stdout);
                }
                break;
            }
            case 3:
            {
                if(bajaContribuyente(listaContribuyentes,listaRecaudaciones,len,len))
                {
                    printf("El contribuyente ha sido eliminado.\n");
                    fflush(stdout);
                }
                break;
            }
            case 4:
            {
                if(alta_Recaudacion(listaRecaudaciones,listaContribuyentes,len,len))
                {
                    printf("La recaudacion se ha cargado exitosamente.\n");
                    fflush(stdout);
                }
                break;
            }
            case 5:
            {
            	if(refinanciar(listaRecaudaciones,listaContribuyentes,len,len))
            	{
            		printf("La refinanciacion ha sido exitosa.\n");
            		fflush(stdout);
            	}
                break;
            }
            case 6:
            {
            	if(saldarRecaudacion(listaRecaudaciones,listaContribuyentes,len,len))
            	{
            		printf("La recaudación ha sido saldada.\n");
            		fflush(stdout);
            	}
                break;
            }
            case 7:
            {
            	listarContribuyentes(listaContribuyentes,listaRecaudaciones,len, len);
                break;
            }
            case 8:
            {
            	listarRecaudaciones(listaContribuyentes,listaRecaudaciones,len, len);

                break;
            }
            case 9:
            {
            	printf("Elija un informe.\n"
            			"1)Contribuyentes con mas recaudaciones saldadas.\n"
            			"2) Cantidad de recaudaciones saldadas con un importe mayor a 1000.\n"
            			"3) Informar los contribuyentes por tipo de recaudacion.\n"
            			"4) Nombre y CUIL de los contribuyentes que pagaron en Febrero.\n");
            	fflush(stdout);
            	scanf("%d",&opcion);

            	switch(opcion)
            	{
					case 1:
					{
						recaudacionesRefinanciadas(listaContribuyentes,listaRecaudaciones, len, len);
						break;
					}
					case 2:
					{
						recaudacionesSaldadas(listaRecaudaciones,len);
						break;
					}
					case 3:
					{
						informarDatosContribuyentes(listaContribuyentes,listaRecaudaciones,len,len);
						break;
					}
					case 4:
					{
						contribuyentesFebrero(listaContribuyentes,listaRecaudaciones,len,len);
						break;
					}

            	}

            	break;
            }
        }

    }while(opcion!=10);

    return 0;
}
