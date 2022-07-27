#include "hash.h"

/* Initializare Tabela Hash */
TH *InitTH(size_t M, TFHash funcHash) {
    TH *h = (TH *) malloc(sizeof(TH));             /* Alocare memorie Tabela Hash */
    if (!h) {
        printf("Eroare alocare Tabela Hash.\n");   
        return NULL;
    }

    h->v = (ListaG *) calloc(M, sizeof(ListaG));   /* Alocare memorie vector Tabela Hash */
    if (!h->v) {
        printf("Eroare alocare vector de pointeri ListaG in Tabela Hash.\n");
        free(h);
        return NULL;
    }

    h->M = M;
    h->funcHash = funcHash;
    return h;
}

/* Inserare element in Tabela Hash */
int InserareTH(TH *h, void *elem, TFCmp funcCmp) {
    int rezultat, cod;
    ListaG p;
    
    cod = h->funcHash(elem);
    for (p = h->v[cod]; p != NULL; p = p->urm) {
        if (funcCmp(p->info, elem) == 1) {
            return 1;
        }
    }

    rezultat = InserareLG((h->v) + cod, elem);   /* reminder: (a->v) + cod <=> &a->v[cod] */

    return rezultat;
}

/* Afisare valori din Tabela Hash */
void AfisareTH(TH *h, TFAfis afisareElem) {
    int i;
    ListaG p, elem;

    for (i = 0; i < h->M; i++) {                               /* iterare prin toate codurile generate de functia de codificare */
        p = h->v[i];                                           /* Pointare catre primul element din fiecare codificare */

        if (p) {                                               /* Daca exista elemente pe codificare ... */
            printf("Lista codificarii %d:\n", i);
            for (elem = p; elem != NULL; elem = elem->urm) {   /* Parcurgere toate elementele */   
                afisareElem(elem->info);
            }
            printf("\n");
        }
    }
}

void DistrugeTH(TH **aH, TFElib elibMem) {
    ListaG *p, elem, aux;

    for (p = (*aH)->v; p < (*aH)->v + (*aH)->M; p++) {   /* Nota jos */
        elem = *p;
        while (elem) {                                   /* Iterare prin lista */
            aux = elem;
            elem = elem->urm;
            elibMem(aux->info);
            free(aux);
        }
    }

    free((*aH)->v);
    free(*aH);
}

/* Nota:
    Iteratia se face lucrand cu aritmetica pe pointeri. Setam pointerul pe prima pozitie din vector
    si parcurgem pana la ultima pozitie din vector, (adica adresa v) + (nr. elemente v).
    De revazut PCLP I si PCLP II */