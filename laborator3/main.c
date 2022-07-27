#include "lg.h"
#include "hash.h"
#include "carte.h"

/* Generare Tabela Hash pe baza fisierului 'carti.txt' */
TH *GenerareHash(ListaG listaCarti) {
    TH *h = NULL;
    ListaG celCarte;                                     /* celula Carte */
    Carte *carte;
    int rezultat;

    size_t M = ('Z' - 'A');                              /* Dimensiune maxima posibila, toate literele */

    h = InitTH(M, codHash);
    if (!h) {   
        return NULL;
    }

    for (celCarte = listaCarti; celCarte != NULL; celCarte = celCarte->urm) {
        carte = (Carte *) malloc(sizeof(Carte));
        if (carte == NULL) {
            return h;
        }

        memcpy(carte, celCarte->info, sizeof(Carte));    /* copiere informatie carte */
        rezultat = InserareTH(h, carte, ComparaCarte);   /* inserare carte in Tabela Hash */
        if (rezultat == 0) {
            free(carte);
            return h;
        }
    }

    return h;
}

int main() {
    ListaG listaCarti = GenerareListaCarti("carti.txt");
    if (!listaCarti) {
		printf("Lista nu a putut fi generata.\n");
        return 0;
	}

    printf("=========== LISTA CARTI ===========\n");
    AfisareLG(listaCarti, AfisareCarte);

    TH *h = GenerareHash(listaCarti);
    if (!h) {
        printf("Tabela hash nu a putut fi generata.\n");
        return 0;
    }

    printf("\n\n=========== TABELA HASH ===========\n");
    AfisareTH(h, AfisareCarte);

    DistrugeLG(&listaCarti, free);
    DistrugeTH(&h, free);

    return 0;
}