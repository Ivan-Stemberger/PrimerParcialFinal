#ifndef RECAUDACION_H_
#define RECAUDACION_H_
#include "Tipo.h"
#include "Contribuyente.h"

typedef struct
{
    int id;
    int idContribuyente;
    int mes;
    Tipo tipo;
    float importe;
    char estado[14];
}Recaudacion;


int initRecaudacion(Recaudacion* listaRecaudaciones[],int len);
int agregarRecaudacion(Recaudacion* list[], int len, int id, int mes, int tipo, float importe);
int alta_Recaudacion(Recaudacion* list[], Contribuyente* listContribuyente[], int len, int lenContribuyente);
int bajaContribuyente(Contribuyente* list[], Recaudacion* listRecaudacion[],int len, int lenRecaudacion);
void borrarRecaudacion(Recaudacion* recaudacion);
int encontrar_Recaudacion(Recaudacion* list[], int len,int id);
int refinanciar(Recaudacion* list[], Contribuyente* listContribuyente[], int lenRecaudacion, int lenContribuyente);
int saldarRecaudacion(Recaudacion* list[], Contribuyente* listContribuyente[], int lenRecaudacion, int lenContribuyente);
void setIdContribuyente(Recaudacion* Recaudacion,int id);
void setMes(Recaudacion* Recaudacion,int mes);
void setTipo(Recaudacion* Recaudacion,int tipo);
void setImporte(Recaudacion* Recaudacion,float importe);
#endif /* RECAUDACION_H_ */
