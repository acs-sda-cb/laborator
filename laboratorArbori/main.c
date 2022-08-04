#include "arb.h"

int main() {
    int v[] = {1, 2, 3, 4};
    int nrNoduri = sizeof(v)/sizeof(v[0]);
    Arb arbore = NULL;
    
    arbore = ConstArbore(v, 0, nrNoduri);
    PrintareArbore(arbore, 0);
    
    RSD(arbore);
    printf("\n");

    DistrugeArb(&arbore);
    return 0;
}