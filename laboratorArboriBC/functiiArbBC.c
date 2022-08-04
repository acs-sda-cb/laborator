#include "arbBC.h"

/* Aloca un element de tip Arb si returneaza pointerul aferent */
Arb AlocareFrunza(int elem) {
    Arb aux = (Arb) malloc(sizeof(Nod));
    if (!aux) {
        return NULL;
    }

    aux->info = elem;
    aux->st = aux->dr = NULL;

    return aux;
}

/* Aloca un element de tip Arb si construieste un nou arbore cu arbore 'aux' */
Arb AlocareNod(int elem, Arb st, Arb dr) {
    Arb aux = (Arb) malloc(sizeof(Nod));
    if (!aux) {
        return NULL;
    }

    aux->info = elem;
    aux->st = st;
    aux->dr = dr;

    return aux;
}

int InserareABC(Arb *arbore, int elem) {
    Arb p;
    
    Arb aux = AlocareFrunza(elem);
    if (!aux) {
        return 0;
    }

    if (!(*arbore)) {
        *arbore = aux;        
        return 1;
    }

    p = *arbore;
    while (p) {
        if (elem == p->info) {
            return 0;
        }

        else if (elem > p->info) {
            if (!p->dr) {
                p->dr = aux;
                return 1;
            }
            p = p->dr;
        }

        else if (elem < p->info) {
            if (!p->st) {
                p->st = aux;
                return 1;
            }
            p = p->st;
        }
    }
}

/* Parcurgere Radacina - Stanga - Dreapta */
void RSD(Arb a) {
	if (!a) {
        printf("-"); 
        return;
    }
	
    if (!a->st && !a->dr) {          /* conditie frunza */
        printf(" %d ", a->info);      
        return;
    }
	
    printf(" %d ", a->info);
	printf("(");
	
    RSD(a->st);                      /* apelare recursiva */
	printf(",");
	
    RSD(a->dr);                      /* apelare recursiva */
	printf(")");
}

/* Printare arbore */
void PrintareArbore(Arb arbore, int spatiu) {
    if (arbore == NULL) {
        return;
    }
    
    spatiu += 10;
    
    PrintareArbore(arbore->dr, spatiu);
    printf("\n");

    for (int i = 10; i < spatiu; i++)
        printf(" ");
    printf("%d\n", arbore->info);
 
    PrintareArbore(arbore->st, spatiu);
}

/* Functie care exploreaza arborele si returneaza numarul de noduri */
int NrNoduri(Arb arbore) {
    if (!arbore) {
        return 0;
    }

    int nrSt = NrNoduri(arbore->st);
    int nrDr = NrNoduri(arbore->dr);     

    return 1 + nrSt + nrDr;
}

/* Functie care exploreaza arborele si returneaza inaltimea arborelui */
int NrNiveluri(Arb arbore) {
    if (!arbore) {
        return 0;
    }

    int nivSt = NrNiveluri(arbore->st);
    int nivDr = NrNiveluri(arbore->dr);
                                            
    return 1 + (nivSt >= nivDr ? nivSt : nivDr);     /* if (nivSt >= nivDr) nivSt else nivDr, sau o functie de maxim intre 2 numere*/
}                                                      

/* Dezalocare memorie arbore */
void DistrugeArb(AArb adrArbore) {
    if (!(*adrArbore)) {
        return;
    }

    DistrugeArb(&(*adrArbore)->st);
    DistrugeArb(&(*adrArbore)->dr);

    free(*adrArbore);
}