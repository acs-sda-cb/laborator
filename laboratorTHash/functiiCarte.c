#include "carte.h"
#include "lg.h"

/* Codificare pe baza autorului */
int codHash(void *elem) {
    Carte *carte = (Carte *) elem;   
    char *autor = carte->autor;
    return *autor - 'A';               /* produce codificarea dupa prima litera a autorului */
}

/* Afisare carte */
void AfisareCarte(void *elem) {
    Carte *carte = (Carte *) elem;
    printf("%s - %s - %s\n", carte->autor, carte->titlu, carte->editura);
}

/* Compara doua elemente de tipul carte, folosit pentru inserare */
int ComparaCarte(void *elem1, void *elem2) {
    Carte *carte1 = (Carte *) elem1;
    Carte *carte2 = (Carte *) elem2;

    if (strcmp(carte1->titlu, carte2->titlu) != 0) {       /* Verificare daca cartile sunt diferite */
        return 0;
    }

	if (strcmp(carte1->autor, carte2->autor) != 0) {       /* */
        return 0;
    }

	if (strcmp(carte1->editura, carte2->editura) != 0) {   /* */
        return 0;
    }
		
	return 1;
}

/* Generare lista generica pe baza 'carti.txt' */
ListaG GenerareListaCarti(char *numeFisier) {
	char *line = NULL;
	size_t len = 0;
	ListaG L = NULL;
    FILE *f = fopen(numeFisier, "rt");

	if (f == NULL) {
        printf("Eroare deschidere fisier.\n");
        return NULL;
    }

	while (getline(&line, &len, f) != -1) {
		char *autor = strtok(line, ":");
		char *titlu = strtok(NULL, ":");
		char *editura = strtok(NULL, ":");

		if (editura[strlen(editura) - 1] == '\n') {
            editura[strlen(editura) - 1] = '\0';
        }

		Carte *carte = (Carte *) malloc(sizeof(Carte));   /* Creare zona de memorie pentru inserare in lista */
		if (carte == NULL) {
            return L;
        }

		strcpy(carte->autor, autor);
		strcpy(carte->titlu, titlu);
		strcpy(carte->editura, editura);
		InserareLG(&L, carte);
    }
    
    free(line);
	fclose(f);
    return L;
}	