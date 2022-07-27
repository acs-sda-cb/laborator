#include <stdio.h>
#include <stdlib.h>

typedef struct celGenerica {
    void *info;
    struct celGenerica *urm;
}CelulaG, *ListaG, **AListaG;
/* La fel ca in laboratorul 1, numai ca retinem 'void' in loc de 'int' */

ListaG AlocCelulaG(void *elem);
int InserareLG(AListaG aL, void *elem);
ListaG CitireLG(int *dimLista);
void AfisareLG(ListaG L, void (*afisareElem)(void *));
void DistrugeLG(AListaG aL, void (*stergeElem)(void *));