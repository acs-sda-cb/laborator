#include "arbBC.h"

int main() {
    int v[] = {5, 3, 1, 4, 7, 8, 6};
    int nrNoduri = sizeof(v)/sizeof(v[0]);
    Arb arbore = NULL;
    
    for (int i = 0; i < nrNoduri; i++) {
        InserareABC(&arbore, v[i]);
    }
    PrintareArbore(arbore, 0);
    
    RSD(arbore);
    printf("\n");

    DistrugeArb(&arbore);
    return 0;
}