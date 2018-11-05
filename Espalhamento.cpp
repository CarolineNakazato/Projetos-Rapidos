#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#define DIM 16
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>
#include <ctype.h>

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
void imprime2(no * PRI[], variavel * v);
void executa_exp(no * PRI[], char exp[]);

void main() {
	no * PRI[MAX];
	int t, i;
	variavel v, teste[5] = { { "alfa\0",0,5 },
	{ "x\0",0,12 },
	{ "xy\0",0,-5 },
	{ "abcde\0",0,6 },
	{ "y\0",0,4 } };
	no * end;
	char nome[20], exp[100];

	cria_vazia(PRI);

	for (i = 0; i < 5; i++) {
		t = inserir(PRI, teste[i]);//v
	}
	strcpy(nome,"alfa\0");
	end = buscar(PRI, nome);
	if (end == NULL) {
		printf("Nao existe info.\n");
	}
	//printf("nome = %d.\n",end->info.valor);

	imprime2(PRI,teste);
	
	printf("Digite a expressao\n");
	scanf("%s", exp);

	executa_exp(PRI, exp);

	imprime2(PRI);

	system("pause");

}
void cria_vazia(no * PRI[]) {
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
	//printf(" x = %d \n", x->info.valor);
	while (x != NULL) {
		//printf(" x->info.valor = %d \n", x->info.valor);
		if (strcmp(x->info.var_nome, nome) == 0) {
			//printf(" entra = %d \n", x->info.valor);
			return x;
		}
		x = x->link;
	}
	return NULL;
}

void imprime(no * PRI[]) {
	int nLista = 0;
	for (nLista = 0; nLista < MAX; nLista++) {
		printf("Lista %d: ", nLista);
		while (PRI[nLista] != NULL) {
			printf(" %d ", PRI[nLista]->info.valor);
			PRI[nLista] = PRI[nLista]->link;
		}
		printf("\n");
	}
}

void imprime2(no * PRI[], variavel * v) {
	no*x;
	int p,i, j;
	int val[MAX][MAX];

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			val[i][j] = NULL;
		}
	}
	for (i = 0; i < 5; i++) {
		j = 0;
		x = buscar(PRI, v[i].var_nome);
		p = Hash(v[i].var_nome);
		while (val[p][j] != NULL) {
			j++;
		}
		val[p][j] = x->info.valor;
		//printf("Lista %d: %d\n", p, x->info.valor);
	}
	for (i = 0; i < MAX; i++) {
		printf("Lista %d: ", i);
		for (j = 0; j < MAX; j++) {
			if (val[i][j] != NULL) {
				printf(" %d ", val[i][j]);
			}
		}
		printf("\n");
	}
}
void executa_exp(no * PRI[], char exp[]) {
	char *t;
	char res[20], op1[20], op2[20], opc;
	t = exp;
	no * r;
	no * p1;
	no * p2;

	//onde fica o resultado
	int i = 0;
	while (isalpha(*t)) {
		res[i++] = *t;
		t++;
	}
	res[i] = '\0';

	//ignora igual
	t++;

	//onde fica o operando 1
	i = 0;
	while (isalpha(*t)) {
		op1[i++] = *t;
		t++;
	}
	op1[i] = '\0';

	//pega qual operação será feita
	opc = *t;
	t++;

	//onde fica o operando 2
	i = 0;
	while (isalpha(*t)) {
		op2[i++] = *t;
		t++;
	}
	op2[i] = '\0';

	//descobre qual o valor de qual variavel
	//printf("res =  %s\n", res);
	//printf("op1 =  %s\n", op1);
	//printf("op2 =  %s\n", op2);

	r = buscar(PRI, res);
	//printf(" %d ", r->info.valor);
	p1 = buscar(PRI, op1);
	p2 = buscar(PRI, op2);

	//descobre qual operação
	switch (opc)
	{
	case '+':
		r->info.valor = p1->info.valor + p2->info.valor;
		break;
	case '-':
		r->info.valor = p1->info.valor - p2->info.valor;
		break;
	default:
		break;
	}
}