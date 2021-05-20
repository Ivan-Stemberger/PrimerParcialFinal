#ifndef INFORMES_H_
#define INFORMES_H_
#include "Recaudacion.h"
#include "Contribuyente.h"

int listarContribuyentes(Contribuyente* list[], Recaudacion* listRecaudacion[],int len, int lenRecaudacion);
int listarRecaudaciones(Contribuyente* list[], Recaudacion* listRecaudacion[],int len, int lenRecaudacion);
void imprimirContribuyente(Contribuyente* contribuyente);
void imprimirListadoContribuyentes(Contribuyente* contribuyente, Recaudacion* recaudacion);
void imprimirListadoRecaudaciones(Contribuyente* contribuyente, Recaudacion* recaudacion);
void imprimirRecaudacion(Recaudacion* recaudacion);
void recaudacionesSaldadas(Recaudacion* listRecaudaciones[],int len);
void recaudacionesRefinanciadas(Contribuyente* listContribuyente[], Recaudacion* listRecaudacion[], int len, int lenRecaudacion);
void informarDatosContribuyentes(Contribuyente* listContribuyente[], Recaudacion* listRecaudacion[], int len, int lenRecaudacion);
void contribuyentesFebrero(Contribuyente* listContribuyente[], Recaudacion* listRecaudacion[], int len, int lenRecaudacion);
void imprimir_nombreYCuil(Contribuyente* contribuyente);
#endif /* INFORMES_H_ */
