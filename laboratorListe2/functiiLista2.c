#include "lista2.h"

/* Aloca un element de tip Celula2 si returneaza pointerul aferent */
Lista2 AlocCelula2(void *x) {
    Lista2 aux = (Lista2) malloc(sizeof(Celula2));
    if (!aux) {
        return NULL;
    }

    aux->info = x;
    aux->pre = aux->urm = NULL;

    return aux;
}

/* Creeaza santinela pentru lista folosita */
Lista2 InitLista2() {
    Lista2 aux = (Lista2) malloc(sizeof(Celula2));
    if (!aux) {
        return NULL;
    }

    aux->info = NULL;
    aux->pre = aux->urm = aux;

    return aux;
}

/* Citeste de la tastatura numere de adaugat in lista */
Lista2 CitireLista2(int *dimLista) {
    Lista2 L = NULL, aux, ultim;
    int x;
    int *elem;
    char ch;
    *dimLista = 0;
    
    printf("Introduceti numerele de adaugat in lista:\n");
    while (scanf("%i", &x) == 1) {   /* se citesc numere pana cand se citeste un caracter */
        elem = (int *) malloc(sizeof(int));
        *elem = x;
        aux = AlocCelula2(elem);

        if (L == NULL) {
            L = InitLista2();
            aux->urm = aux->pre = L;
            L->pre = L->urm = aux;

        } else {
            aux->urm = L;
            aux->pre = L->pre;
            L->pre->urm = aux;
            L->pre = aux;
        }

        (*dimLista)++;
    }

    return L;
}

/* Afisare continut lista */
void AfisareLista2(Lista2 L, TFAfis afisElem) {
    Lista2 p = L->urm;    

    printf("Lista: [");
    while (p != L) {         /* parcurgere pentru liste dublu inlantuite */
        afisElem(p->info);   
        p = p->urm;
    }
    printf("]\n");
}

void DistrugeLista2(ALista2 aL, TFElib stergeElem) {
    Lista2 p = (*aL)->urm, aux;
    while (p != *aL) {
        aux = p;
        p = p->urm;
        stergeElem(aux->info);
        free(aux);
    }

    stergeElem((*aL)->info);
    free(*aL);
}