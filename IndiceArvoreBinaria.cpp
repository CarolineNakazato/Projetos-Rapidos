#define _CRT_SECURE_NO_WARNINGS
//#define N 25
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>

typedef struct {
	int ra;
	char nome[20];
	int idade;
	float nota;
}aluno;

typedef struct {
	int chave_ra;
	int pos;
}dados;

typedef struct node {
	dados info;
	struct node * le, *ld;
}no;

void cria_tabela(aluno TAB[], int *N);
void cria_indice_arv(no** raiz, dados a);
int busca(no*raiz, int ra);

void main() {
	no *raiz = NULL;
	aluno TAB[25];
	dados a;
	int N, pos, i, raAtual = 0;

	cria_tabela(TAB, &N);

	for (i = 0; i < N; i++) {
		a.chave_ra = TAB[i].ra;
		a.pos = i;
		cria_indice_arv(&raiz, a);
	}
		
	while (raAtual != -1) {
		printf("\nDigite o ra do aluno:\n");
		scanf("%d", &raAtual);

		pos = busca(raiz, raAtual);
		
		//for (i = 0; i < N; i++) {
		//	printf("Ra: %d\n", TAB[i].ra);
		//}

		if (pos == -1) {
			if(raAtual != -1)
				printf("RA Inexistente.\n");
		
		}
		else {
			printf("\nRa: %d\n", TAB[pos].ra);
			printf("Nome: %s\n", TAB[pos].nome);
			printf("Idade: %d\n", TAB[pos].idade);
			printf("Nota: %.2f\n", TAB[pos].nota);
		}
		
	}

	system("pause");

}

void cria_tabela(aluno TAB[], int *N) {
		int i;
		aluno T[25] = { { 5792,"Joao de barro",18,9.5 },
						{ 3219,"Branca de neve",20,8.5 },
						{ 2354,"Saci perere",19,7.5 },
						{ 8295,"Bela adormecida",21,8.5 },
						{ 6784,"Mikey Mouse",22,9.5 },
						{ 9563,"Peter pan",20,5.5 },
						{ 4235,"Pato donald",19,9.5 }
						};
		printf("Digite quantidade de N.\n");
		scanf("%d", N);
		for (i = 0; i < *N; i++) {
			TAB[i] = T[i];
		}
}

void cria_indice_arv(no** raiz, dados a) {

	no *novo, *ant, *p;
	novo = (no*)malloc(sizeof(no));
	if (novo == NULL) printf("Erro de alocacao.\n");

	novo->info = a;
	novo->le = NULL;
	novo->ld = NULL;
	ant = NULL;
	if (*raiz == NULL) {
		*raiz = novo;
	} else {
		p = *raiz;
		while (p != NULL) {
			ant = p;
			if (a.chave_ra > p->info.chave_ra)	p = p->ld;
			else { p = p->le; }
		}
		if (a.chave_ra > ant->info.chave_ra) ant->ld = novo;
		else ant->le = novo;
	}
}

int busca(no *raiz, int ra) {
	int pos = -1;
	no *p;

	if (raiz != NULL) {
		p = raiz;
		while (p != NULL) {
			if (ra > p->info.chave_ra) {
				p = p->ld; 
			}
			else { 
				if (ra == p->info.chave_ra) {
					//printf("ra = %d\n", ra);
					//printf("p->info.chave_ra = %d\n", p->info.chave_ra);
					//printf("pos = %d\n", p->info.pos);
					return p->info.pos;
				}
				else {
					p = p->le;
				}
			}
		}
	}
	return pos;

}