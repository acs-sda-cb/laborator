#include "lg.h"

/* Aloca un element de tip Celula si returneaza pointerul aferent */
ListaG AlocCelulaG(void *elem) {
    ListaG aux = (ListaG) malloc(sizeof(CelulaG));
    if (aux) {
        aux->info = elem;
        aux->urm = NULL;
    }
    return aux;
}

/* Inserare elemente in lista, ordinea este cea de la tastatura */
int InserareLG(AListaG aL, void *elem) {
    ListaG p, aux;
    
    aux = AlocCelulaG(elem);
    if (!aux) {
        return 0;
    }
    
    if (!(*aL)) {
        *aL = aux;
        return 1;
    } else {
        for(p = *aL; p->urm != NULL; p = p->urm);
        p->urm = aux;
        return 1;
    }
    return 0;
}

/* Numarul de elemente din lista */
int LungimeLG(ListaG L) {
    size_t lg = 0;

    for(; L != NULL; L = L->urm)   /* parcurgere lista si numarare elemente */
        lg++;

    return lg;
}

/* Citeste de la tastatura numere de adaugat in lista */
ListaG CitireLG(int *dimLista) {
    ListaG L = NULL, aux, ultim;
    int x, *elem;
    char ch;
    *dimLista = 0;
    printf("Introduceti elemente de adaugat in lista:\n");
    while (scanf("%i", &x) == 1) {
        elem = malloc(sizeof(int));
        *elem = x;

        aux = AlocCelulaG(elem);
        if (!aux) {                  
            return L;
        }

        if (L == NULL) {             
            L = aux;
        } else {                    
            ultim->urm = aux;
        }

        ultim = aux;                 
        (*dimLista)++;
    }

    return L;
}

/* Afisare continut lista, primim un pointer la o functie de printare */
void AfisareLG(ListaG L, TFAfis afisareElem) {
    printf("Lista: [");
	while (L) {
        afisareElem(L->info);
        L = L->urm;
    } 
	printf("]\n");
}

/* Dezalocare memorie lista, primim un pointer la o functie de dezalocare */
void DistrugeLG(AListaG aL, TFElib stergeElem) {
    ListaG aux;
    while (*aL) {
        aux = *aL;
        *aL = (*aL)->urm;
        stergeElem(aux->info);
        free(aux);
    }
}