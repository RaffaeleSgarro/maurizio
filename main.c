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
			fpo = fopen("classe_ordinata.txt", "w");

			ordina_voto_CRESCENTE(N, classe);
			printf("Gli studenti in ordine CRESCENTE in base al voto sono: \n");
			stampa_classe(N, classe);

			ordina_voto_DECRESCENTE(N, classe);
			printf(
				"Gli studenti in ordine DECRESCENTE in base al voto sono: \n");
			stampa_classe(N, classe);
		}
		printf("Vuoi rieseguire il programma? S o N \n");

	} while (getch() != 'n');
}

int leggi_classe(FILE* A, struct studente* B) {
	int i;
	i = 0;

	while (fscanf(A, "%s%s%d", B[i].cognome, B[i].nome, &B[i].voto) != EOF)
	{
		i = i + 1;
	}
	return i;

}

void ordina_voto_CRESCENTE(int A, struct studente* B) {
	int i, j, imin;

	for (i = 0; i < A - 1; i++) {
		imin = i;

		for (j = 0; j < A; j++)

			if (B[j].voto < B[imin].voto)
				imin = j;

		scambia(&B[i], &B[imin]);
	}
}

void ordina_voto_DECRESCENTE(int A, struct studente* B) {
	int i, j, imax;

	for (i = 0; i < A - 1; i++) {
		imax = i;

		for (j = i + 1; j < A; j++)

			if (B[j].voto > B[imax].voto)
				imax = j;

		scambia(&B[i], &B[imax]);
	}
}

void scambia(struct studente* A, struct studente* B) {
	struct studente temp;
	temp = *A;
	*A = *B;
	*B = temp;
}

void stampa_classe(int A, struct studente* B) {
	int i;
	for (i = 0; i < A; i++) {
		printf("%s %s %d", B[i].cognome, B[i].nome, &B[i].voto);
		printf("\n");
	}

}
