#include <stdio.h>
#include <conio.h>
#include <string.h>

#pragma warning(disable : 4996)

struct studente {
	char cognome[15];
	char nome[10];
	int voto;
};

int leggi_classe(FILE*, struct studente*);
void ordina_voto_CRESCENTE(int, struct studente*);
void ordina_voto_DECRESCENTE(int, struct studente*);
void ordine_alfabetico(int, struct studente*);
void scambia(struct studente*, struct studente*);
void stampa_classe(int, struct studente*);

void main() {
	int N;
	FILE *fpi, *fpo;
	struct studente classe[30];
	do {
		fpi = fopen("classe.txt", "r");
		if (fpi == NULL)
			printf("Il file non e' presente");
		else {
			N = leggi_classe(fpi, classe);

			ordina_voto_CRESCENTE(N, classe);
			printf("Gli studenti in ordine CRESCENTE in base al voto sono: \n");
			stampa_classe(N, classe);

			ordina_voto_DECRESCENTE(N, classe);
			printf("Gli studenti in ordine DECRESCENTE in base al voto sono: \n");
			stampa_classe(N, classe);

			ordine_alfabetico(N, classe);
			printf("Gli studenti in ordine ALFABETICO sono: \n");
			stampa_classe(N, classe);
		}
		printf("Vuoi rieseguire il programma? S o N \n");

	} while (getch() != 'n');
}

int leggi_classe(FILE* A, struct studente* B) {
	int i = 0;

	while (fscanf(A, "%s%s%d", B[i].cognome, B[i].nome, &B[i].voto) != EOF)
	{
		i = i + 1;
	}
	return i;
}

void ordine_alfabetico(int lunghezza, struct studente* studenti) {
	for (int stop = lunghezza - 1; stop > 0; stop--) {
		for (int i = 0; i < stop; i++) {
			if (strcmp(studenti[i].cognome, studenti[i + 1].cognome) > 0) {
				scambia(&studenti[i], &studenti[i + 1]);
			}
		}
	}
}

/*
 * Use selection sort for this
 */
void ordina_voto_CRESCENTE(int lunghezza, struct studente* studenti) {
	int i, j, imin;
	for (i = 0; i < lunghezza - 1; i++) {
		imin = i;
		for (j = i; j < lunghezza; j++) {
			if (studenti[j].voto < studenti[imin].voto) {
				imin = j;
			}
		}
		scambia(&studenti[i], &studenti[imin]);
	}
}

void ordina_voto_DECRESCENTE(int lunghezza, struct studente* studenti) {
	for (int stop = lunghezza - 1; stop > 0; stop--) {
		for (int i = 0; i < stop; i++) {
			if (studenti[i].voto < studenti[i + 1].voto) {
				scambia(&studenti[i], &studenti[i + 1]);
			}
		}
	}
}

void scambia(struct studente* A, struct studente* B) {
	struct studente temp;
	temp = *A;
	*A = *B;
	*B = temp;
}

void stampa_classe(int lunghezza, struct studente* studenti) {
	for (int i = 0; i < lunghezza; i++) {
		printf("%s, %s: %d\n", studenti[i].cognome, studenti[i].nome, studenti[i].voto);
	}
	printf("\n");
}
