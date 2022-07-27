#include <stdio.h>
#include <stdlib.h>

#define ListaVida(L) (L->urm != L)

typedef struct celula2 {
  void *info;              
  struct celula2 *pre, *urm;
} Celula2, *Lista2, **ALista2;

typedef void (*TFAfis)(void *);         /* functie afisare un element */
typedef void (*TFElib)(void *);         /* functie eliberare un element */

Lista2 AlocCelula2(void *x);
Lista2 InitLista2();
Lista2 CitireLista2(int *dimLista);
void AfisareLista2(Lista2 L, TFAfis afisElem);
void DistrugeLista2(ALista2 aL, TFElib stergeElem);