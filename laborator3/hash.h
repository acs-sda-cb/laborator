#include "lg.h"

typedef int (*TFHash)(void*);

typedef struct {
    size_t M;
    TFHash funcHash;   /* pointer la functia de codificare Hash */
    ListaG *v;         /* vector cu tipul ListaG */
}TH;

TH *InitTH(size_t M, TFHash funcHash);
int InserareTH(TH *h, void *elem, TFCmp funcCmp);
void AfisareTH(TH *h, TFAfis afisareElem);
void DistrugeTH(TH **aH, TFElib elibMem);