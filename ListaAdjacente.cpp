
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>
#define TOTALVERTICES 8

typedef struct mapa {
	int lugar;
	char rua[50];
	int metros;
	struct mapa* prox;
}MAPA;

MAPA lista[TOTALVERTICES + 1];

void Imprimir(MAPA *lista);
void Inserir_Aresta(MAPA *lista, int posicao, int lugar, char rua[], int metros);

int main(int argc, char *argv[]) {

	int i;

	// Inicialização da lista. 
	for (i = 1; i <= TOTALVERTICES; i++) {
		lista[i].lugar = 0;
		strcpy(lista[i].rua, "rua 0");
		lista[i].metros = 0;
		lista[i].prox = NULL;
	}

	Inserir_Aresta(lista, 0, 0, "rua 0", 50);
	Inserir_Aresta(lista, 0, 1, "rua 2", 50);
	Inserir_Aresta(lista, 1, 1, "rua 1", 75);

	Imprimir(lista);
	system("pause");
}


void Imprimir(MAPA *lista) {
	int i;
	MAPA * tmp;
	for (i = 0; i <= 3; i++) {
		tmp = lista[i].prox;

		while (tmp != NULL) {
			printf("posicao = %d, lugar = %d, rua = %s, metros = %d\n", i, tmp->lugar, tmp->rua, tmp->metros);
			//printf("%d  ", tmp->lugar);
			tmp = tmp->prox;
		}
		printf("\n");
	}
}

void Inserir_Aresta(MAPA *lista, int posicao, int lugar, char rua[], int metros) {
	MAPA *aux;
	MAPA *tmp;

	aux = (MAPA*)malloc((int)sizeof(MAPA));    //retorno de um ponteiro genérico.
	aux->lugar = lugar;
	strcpy(aux->rua, rua);
	aux->metros = metros;
	aux->prox = NULL;

	lista[posicao].lugar++;
	if (lista[posicao].prox == NULL) // Caso a lista estiver vazia - Insere.	
		lista[posicao].prox = aux;
	else {
		printf("lista[posicao].prox = %d\n", lista[posicao].prox->lugar);
		tmp = lista[posicao].prox;
		if (tmp->lugar > lugar) { //da erro aqui quando tira do global como se tmp estivesse null mas nao esta deve ter lixo
			aux->prox = tmp;
			lista[posicao].prox = aux;
		} 		          //insere os vértices ordenados
		else if (tmp->prox == NULL) {
			aux->prox = tmp->prox;
			tmp->prox = aux;
		}
		else {
			while ((tmp->prox != NULL) && (tmp->prox->lugar < lugar))
				tmp = tmp->prox;
			aux->prox = tmp->prox;
			tmp->prox = aux;
		}
	}
}
