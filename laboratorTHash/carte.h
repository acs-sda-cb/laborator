#include <string.h>
#include "lg.h"

/* Detalii de preprocesare */
#ifndef _CARTEH_
#define _CARTEH_

typedef struct {
	char titlu[50];
	char autor[30];
	char editura[30];
}Carte;

int codHash(void *elem);
void AfisareCarte(void *elem);
int ComparaCarte(void *elem1, void *elem2);
ListaG GenerareListaCarti(char *numeFisier);

#endif