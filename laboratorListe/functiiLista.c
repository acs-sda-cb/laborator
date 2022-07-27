#include "lista.h"

/* Aloca un element de tip Celula si returneaza pointerul aferent */
Lista AlocCelula(int elem) {
    Lista aux = (Lista) malloc(sizeof(Celula));   /* alocare */
    if (aux) {                                    /* aux != NULL */
        aux->info = elem;
        aux->urm = NULL;
    }
    return aux;                                   /* returnare adresa sau NULL */
}

/* Citeste de la tastatura numere de adaugat in lista */
Lista CitireLista(int *dimLista) {
    Lista L = NULL, aux, ultim;
    int x;
    char ch;
    *dimLista = 0;
    
    printf("Introduceti numerele de adaugat in lista:\n");
    while (scanf("%i", &x) == 1) {   /* se citesc numere pana cand se citeste un caracter */
        
        aux = AlocCelula(x);
        if (!aux) {                  /* aux == NULL, !aux != NULL */
            return L;
        }

        if (L == NULL) {             /* initializare cap de lista */
            L = aux;
        } else {                     /* adaugare celula la final de lista */
            ultim->urm = aux;
        }

        ultim = aux;                 /* pointerul pentru ultima celula este actualizat */
        (*dimLista)++;
    }

    return L;
}

/* Afisare continut lista */
void AfisareLista(Lista L) {
    printf("Lista: [");
    while (L) {                   /* L != NULL */
        printf("%d ", L->info);   
        L = L->urm;
    }
    printf("]\n");
}

/* Dezalocare memorie lista */
void DistrugeLista(ALista aL) {
    Lista aux;
    while (*aL) {           /* *aL != NULL, dereferentiere adresa aL */
        aux = *aL;
        *aL = (*aL)->urm;   
        free(aux);
    }
}