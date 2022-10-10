#include <stdio.h>
#include <stdlib.h>

typedef int (*TFCmp)(int, int);

typedef struct Heap {
    int nrMax, nrElem;
    int *v;
    TFCmp comp;
} *THeap;

THeap AlocaHeap(int nrMax, TFCmp comp);
int RelMinHeap(int valParinte, int valCopil);
int RelMaxHeap(int valParinte, int valCopil);
void AfisareHeap(THeap h, int pos);
void DistrugeHeap(THeap *ah);