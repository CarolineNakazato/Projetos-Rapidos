#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#define DIM 16
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>


typedef struct {
	char var_nome[20];
	int tipo;
	int valor;
}variavel;

typedef struct node {
	variavel info;
	struct node * link;
}no;

void cria_vazia(no * PRI[]);
int inserir(no * PRI[], variavel v);
int Hash(char s[]);
no * buscar(no * PRI[], char nome[]);
void imprime(no * PRI[]);

void main() {
	no * PRI[MAX];
	int t, i;
	variavel v, teste[5] = { {"alfa",0,5},
							 {"x",0,12},
							 { "xy",0,-5 }, 
							 { "xwe",0,5 }, 
							 { "y",0,4 } };
	no * end;
	char nome[20];

	cria_vazia(PRI);

	for (i = 0; i < 5; i++) {
		t = inserir(PRI, teste[i]);//v
	}

	end = buscar(PRI, nome);
	if (end == NULL) {
		printf("Nao existe info.\n");
	}

	imprime(PRI);

	system("pause");

}
void cria_vazia(no * PRI[]){
	int i; 
	for (i = 0; i < MAX; i++)
		PRI[i] = NULL;
}

int inserir(no * PRI[], variavel v) {
	int p;
	no * novo = (no*)malloc(sizeof(no));
	if (novo == NULL)
		return 0;
	novo->info = v;
	p = Hash(v.var_nome);
	novo->link = PRI[p];
	PRI[p] = novo;
	return 1;

}

int Hash(char s[]) {
	int n = strlen(s);
	n = n % MAX;
	return n;
}

no * buscar(no * PRI[], char nome[]) {
	no*x;
	int p;
	p = Hash(nome);
	x = PRI[p];
	while (x != NULL) {
		if (strcmp(x->info.var_nome, nome) == 0)
			return x;
		x = x->link;
	}
	return NULL;
}

void imprime(no * PRI[]) {
	int nLista = 0;
	for (nLista = 0; nLista < MAX; nLista++) {
		printf("Lista %d: ",nLista);
		while (PRI[nLista] != NULL) {
			printf(" %d ", PRI[nLista]->info.valor);
			PRI[nLista] = PRI[nLista]->link;	
		}
		printf("\n");
	}
}