#include <stdio.h>
#include <stdlib.h>

/* Detalii de preprocesare */
#ifndef _LGH_
#define _LGH_

typedef struct celGenerica {
    void *info;
    struct celGenerica *urm;
}CelulaG, *ListaG, **AListaG;

typedef int (*TFElem)(void *);          /* functie prelucrare element */
typedef int (*TFCmp)(void *, void *);   /* functie de comparare doua elemente */
typedef void (*TFAfis)(void *);         /* functie afisare un element */
typedef void (*TFElib)(void *);         /* functie eliberare un element */ 

ListaG AlocCelulaG(void *elem);
int InserareLG(AListaG aL, void *elem);
ListaG CitireLG(int *dimLista);
void AfisareLG(ListaG L, TFAfis afisareElem);
void DistrugeLG(AListaG aL, TFElib stergeElem);

#endif