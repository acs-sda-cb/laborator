#include "lista2.h"

void afisareInt(void *elem) {
    int *aux = elem;
    printf("%d ", *aux);
}

int main() {
    Lista2 L = NULL;
    int lg = 0;

    L = CitireLista2(&lg);
    printf("Dimensiune lista: %d\n", lg);
    AfisareLista2(L, afisareInt);

    DistrugeLista2(&L, free);
    return 0;
}