#define _CRT_SECURE_NO_WARNINGS
#define NAOMEMBRO 0
#define MEMBRO 1
#define INF 99
#define MAXNOS 10
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>

typedef struct tno no;

struct tno {
	int info;
	int peso;
	struct tno *prox;

};

void inserirInicio(int n, int peso, tno **inicio); //insere no comeco da lista
void menorcaminho(int peso[][MAXNOS], int s, int t, int*pd, int precede[]);

int main() {
	tno *lista = NULL;
	int precede[MAXNOS];// = { 0,0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int pd, i, origem, destino;
	int peso[MAXNOS][MAXNOS] = {
		{ INF,2, INF, INF, INF, INF, INF, INF, INF, INF },
		{ INF,INF, INF, 1, INF, INF, INF, INF, INF, INF },
		{ 1,INF, INF, INF, INF, INF, INF, INF, INF, INF },
		{ INF,INF, INF, INF, INF, INF, INF, 1, INF, 4 },
		{ INF,INF, INF, INF, INF, INF, INF, INF, 1, INF },
		{ INF,INF, INF, INF, 2, INF, INF, INF, INF, INF },
		{ INF,INF, INF, INF, INF, 3, INF, INF, INF, INF },
		{ INF,INF, INF, INF, INF, INF, 5, INF, INF, INF },
		{ INF,INF, 3, INF, INF, INF, INF, INF, INF, INF },
		{ INF,INF, INF, INF, INF, 1, INF, INF, INF, INF }
	};

	printf("Digite a origem:\n");
	scanf("%d", &origem);
	printf("Digite o destino:\n");
	scanf("%d", &destino);

	menorcaminho(peso, origem, destino, &pd, precede);
	printf("o peso de menor caminho entre %d e %d  = %d\n", origem, destino, pd);
	printf("Vetor precede\n");
	printf(" [0] [1] [2] [3] [4] [5] [6] [7] [8] [9] \n");
	for (i = 0; i < 10; i++) {
		printf(" %d  ",precede[i]);
	}
	printf("\n");
	system("pause");
	return 0;

}

void inserirInicio(int n, int peso, tno **inicio) {
	tno(*novo) = (tno*)malloc(sizeof(tno));
	if (!(novo)) {
		printf("sem memoria\n");
	}
	else {
		novo->info = n;
		novo->peso = peso;
		novo->prox = (*inicio);
		(*inicio) = novo;
	}
}
void menorcaminho(int peso[][MAXNOS], int s, int t, int*pd, int precede[])
{
	int distancia[MAXNOS];
	int corrente = -1, i = -1, k = 0, dc = INF;
	int perm[MAXNOS];
	int menordist = INF, novadist = INF;
	for (i = 0; i<MAXNOS; i++)
	{
		perm[i] = NAOMEMBRO;
		distancia[i] = INF;
		precede[i] = -1;
	}

	perm[s] = MEMBRO;
	distancia[s] = 0;
	corrente = s;

	while (corrente != t)
	{
		menordist = INF;
		dc = distancia[corrente];

		for (i = 0; i < MAXNOS; i++)
			if (perm[i] == NAOMEMBRO)
			{
				novadist = dc + peso[corrente][i];

				if (novadist < distancia[i])
				{
					distancia[i] = novadist;
					precede[i] = corrente;

				}
				if (distancia[i] < menordist)
				{
					menordist = distancia[i];
					k = i;

				}
			}
		corrente = k;
		perm[corrente] = MEMBRO;

	}
	*pd = distancia[t];

}