#include "lista.h"

int main(){
    int lg = 0;
    Lista L = NULL;

    L = CitireLista(&lg);
    printf("Dimensiune lista: %d\n", lg);
    AfisareLista(L);
    
    DistrugeLista(&L);
    return 0;
}