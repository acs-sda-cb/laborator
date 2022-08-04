#include <stdio.h>
#include <stdlib.h>

typedef struct nod {
    int info;
    struct nod *st, *dr;
} Nod, *Arb, **AArb;

Arb AlocareFrunza(int elem);
Arb AlocareNod(int elem, Arb st, Arb dr);
Arb ConstArbore(int v[], int pos, int dimVec);
void RSD(Arb a);
void PrintareArbore(Arb arbore, int spatiu);
int NrNoduri(Arb arbore);
int NrNiveluri(Arb arbore);
void DistrugeArb(AArb adrArbore);