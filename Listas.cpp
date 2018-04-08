#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>

typedef struct tno no;

struct tno {
	int info;
	struct tno *prox;

};

void inserirInicio(int n, tno **inicio); //insere no comeco da lista
void inserirFinal(int n, tno **inicio);  // insere no final da lista
void inserirK(int n, int posicao, tno **inicio); //insere valor na posicao desejada
void inserirDepois(int x, int n, tno **inicio);  // insere um novo valor depois de outro valor desejado
void inserirAntes(int x, int n, tno **inicio);   // insere um novo valor antes de outro valor desejado
void inserirOrdenado(int n, tno **inicio); // insere um valor na lista de forma crescente

void excluirInicio(tno **inicio); //exclui um elemento do inicio
void excluirFinal(tno **inicio);  //exclui um elemento do fim
void excluirK(int posicao, tno **inicio); //exclui elemento de uma posicao desejada
int excluirDepois(int n, tno **inicio);   // exclui um novo valor depois de outro valor desejado
int excluirAntes(int n, tno **inicio);    // exclui um novo valor antes de outro valor desejado

void imprime(tno *inicio);
void imprimeInicio(tno *inicio); //imprime o primeiro elemento
void imprimeFinal(tno *inicio);  //imprime ultimo elemento
void imprimeK(int posicao, tno *inicio); //imprime valor na posicao desejada

int tamanho(tno *inicio); // retona a quantidade de nos na lista
int soma(tno *inicio);    // soma todos os valores dos nos
int existe(int valor, tno *inicio);  // verifica se um valor pertence a lista

void copia(tno *inicio, tno **nova); //copia a lista inicio para a nova lista
void inverte(tno **inicio);			 //inverte a lista
void concatena(tno **A, tno *B);	 // junta a lista B com a lista A
int iguais(tno *A, tno *B);			 // verifica se as listas sao iguais retorna 1 se sim e 0 se nao
tno *uniao(tno *A, tno *B);			 //faz a uniao entr duas listas (exclui valores repetidos)
tno *interseccao(tno *A, tno *B);	 // faz a interseccao de duas listas (exclui os valores diferentes)
void ordenar(tno **inicio);

void main() {
	tno *lista = NULL;
	tno *novaLista = NULL;
	tno *listaUnida = NULL;
	tno *listaInter = NULL;
	int n = 10;


	/**inserirInicio(2, &lista);
	inserirFinal(4, &lista);
	printf("-----lista Original -----\n");
	imprime(lista);

	inserirOrdenado(1, &lista);
	printf("-----lista 1 ele-----\n");
	imprime(lista);


	inserirOrdenado(3, &lista);

	printf("-----lista 2 ele-----\n");
	imprime(lista);

	inserirOrdenado(5, &lista);
	**/
	inserirInicio(n, &lista);
	inserirInicio(15, &lista);
	inserirInicio(16, &lista);

	inserirFinal(1, &lista);
	inserirFinal(2, &lista);

	inserirK(3, 0, &lista);
	inserirK(5, 1, &lista);

	printf("-----lista-----\n");
	imprime(lista);

	ordenar(&lista);

	printf("-----lista ordenada-----\n");
	imprime(lista);
	/**
	inserirDepois(6, 2, &lista);
	inserirDepois(7, 15, &lista);
	inserirDepois(8, 0, &lista);

	inserirAntes(0, 3, &lista);
	inserirAntes(11, 16, &lista);
	inserirAntes(9, 99, &lista);

	imprimeInicio(lista);
	imprimeFinal(lista);

	imprimeK(4, lista);
	imprimeK(11, lista);
	imprimeK(12, lista);

	if (existe(n, lista) == 1) {
	printf("o valor %d existe na lista.\n", n);
	}
	else {
	printf("o valor %d nao existe na lista.\n", n);
	}

	if (existe(8, lista) == 1) {
	printf("o valor %d existe na lista.\n", 8);
	}
	else {
	printf("o valor %d nao existe na lista.\n", 8);
	}

	copia(lista, &novaLista);
	printf("-----lista nova-----\n");
	imprime(novaLista);


	listaUnida = uniao(lista, novaLista);
	printf("-----lista Unida-----\n");
	imprime(listaUnida);

	inserirInicio(9, &novaLista);
	inserirInicio(8, &novaLista);

	listaUnida = uniao(lista, novaLista);
	printf("-----lista Unida-----\n");
	imprime(listaUnida);


	listaInter = interseccao(lista, novaLista);
	printf("-----lista Interseccao-----\n");
	imprime(listaInter);

	inserirInicio(9, &novaLista);
	inserirInicio(8, &novaLista);

	listaInter = interseccao(lista, novaLista);
	printf("-----lista Interseccao-----\n");
	imprime(listaInter);

	if (iguais(lista, novaLista) == 1) {
	printf("As listas sao iguais.\n", n);
	}
	else {
	printf("As listas sao diferentes.\n", n);
	}

	inverte(&novaLista);
	printf("-----lista invertida-----\n");
	imprime(novaLista);

	if (iguais(lista, novaLista) == 1) {
	printf("As listas sao iguais.\n", n);
	}
	else {
	printf("As listas sao diferentes.\n", n);
	}

	concatena(&lista, novaLista);
	printf("-----lista concatenada-----\n");
	imprime(lista);

	printf("exclui\n");
	excluirInicio(&lista);
	excluirFinal(&lista);
	excluirK(2, &lista);
	printf("valor excluido = %d\n", excluirDepois(6, &lista));
	printf("valor excluido = %d\n", excluirDepois(16, &lista));
	printf("valor excluido = %d\n", excluirDepois(9, &lista));
	printf("valor excluido = %d\n", excluirAntes(0, &lista));
	printf("valor excluido = %d\n", excluirAntes(1, &lista));
	printf("valor excluido = %d\n", excluirAntes(23, &lista));
	imprime(lista);

	printf("tamanho = %d\n", tamanho(lista));
	printf("soma = %d\n", soma(lista));

	**/
	system("pause");

}

void inserirInicio(int n, tno **inicio) {
	tno(*novo) = (tno*)malloc(sizeof(tno));
	if (!(novo)) {
		printf("sem memoria\n");
	}
	else {
		novo->info = n;
		novo->prox = (*inicio);
		(*inicio) = novo;
		//printf("inserir inicio n = %d\n", novo->info);
	}


}
void inserirFinal(int n, tno **inicio) {
	if ((*inicio) != NULL) {
		//printf("entrando %d\n", n);

		if ((*inicio)->prox != NULL) {
			inserirFinal(n, &((*inicio)->prox));
		}
		else {
			tno(*novo) = (tno*)malloc(sizeof(tno));
			if (!(novo)) {
				printf("sem memoria\n");
			}
			else {
				novo->info = n;
				novo->prox = NULL;
				(*inicio)->prox = novo;
				//printf("passou insere final %d\n", novo->info);
			}
		}
	}
	else {
		inserirInicio(n, &(*inicio));
	}
}

void imprime(tno *inicio) {
	if (inicio != NULL) {
		printf("%d\n", inicio->info);
		imprime(inicio->prox);
	}
}

void inserirK(int n, int posicao, tno **inicio) {
	if (posicao == 0)
	{
		inserirInicio(n, &((*inicio)));
	}
	else {

		tno *aux;
		tno(*novo) = (tno*)malloc(sizeof(tno));
		if (!(novo)) {
			printf("sem memoria\n");
		}
		else {
			novo->info = n;
			int cont = 0;
			while (cont < posicao - 1)
			{

				(*inicio) = (*inicio)->prox;
				cont++;
			}
			aux = (*inicio)->prox;
			(*inicio)->prox = novo;
			novo->prox = aux;
		}
	}
}

void excluirInicio(tno **inicio) {
	tno *aux = (*inicio)->prox;
	free(*inicio);
	(*inicio) = aux;

}

void excluirFinal(tno **inicio) {
	if (((*inicio)->prox) != NULL) {
		excluirFinal(&((*inicio)->prox));
	}
	else {
		(*inicio) = NULL;
		free(*inicio);
	}
}

void excluirK(int posicao, tno **inicio) {
	if (posicao == 0)
	{
		excluirInicio(&(*inicio));
	}
	else {
		int cont = 0;
		while (cont < posicao - 1)
		{

			(*inicio) = (*inicio)->prox;
			cont++;
		}
		tno *aux = ((*inicio)->prox)->prox;
		free((*inicio)->prox);
		(*inicio)->prox = aux;
	}
}

int tamanho(tno *inicio) {
	int n = 0;
	while (inicio != NULL) {
		inicio = inicio->prox;
		n++;
	}
	return n;
}

void inserirDepois(int x, int n, tno **inicio) {
	if ((*inicio) != NULL) {
		if ((*inicio)->info != n) {
			inserirDepois(x, n, &((*inicio)->prox));
		}
		else {
			tno(*novo) = (tno*)malloc(sizeof(tno));
			if (!(novo)) {
				printf("sem memoria\n");
			}
			else {
				novo->info = x;
				tno *aux = (*inicio)->prox;
				(*inicio)->prox = novo;
				novo->prox = aux;
			}
		}
	}
	else {
		printf("Nao existe o valor %d na lista\n", n);
	}

}

void inserirAntes(int x, int n, tno **inicio) {
	if ((*inicio)->info == n) {
		inserirInicio(x, &(*inicio));
	}
	else {
		if ((*inicio)->prox != NULL) {
			if (((*inicio)->prox)->info != n) {
				inserirAntes(x, n, &((*inicio)->prox));
			}
			else {
				tno(*novo) = (tno*)malloc(sizeof(tno));
				if (!(novo)) {
					printf("sem memoria\n");
				}
				else {
					novo->info = x;
					tno *aux = ((*inicio)->prox);
					(*inicio)->prox = novo;
					novo->prox = aux;
				}
			}
		}
		else {
			printf("Nao existe o valor %d na lista\n", n);
		}
	}
}

int excluirDepois(int n, tno **inicio) {
	int i = 0;
	if ((*inicio) != NULL) {
		if ((*inicio)->info != n) {
			i = i + excluirDepois(n, &((*inicio)->prox));
		}
		else {
			if ((*inicio)->prox == NULL) {
				printf("Nao existe proximo\n");
			}
			else {
				tno *aux = ((*inicio)->prox)->prox;
				i = ((*inicio)->prox)->info;
				free((*inicio)->prox);
				(*inicio)->prox = aux;
				//printf("deu certo %d\n", i);
				return i;
			}
		}
	}
	else {
		printf("Nao existe o valor %d na lista\n", n);
	}
	return i;
}

int excluirAntes(int n, tno **inicio) {
	int i = 0;
	if ((*inicio)->info == n) {
		printf("Nao existe anterior\n");
	}
	else {
		if ((*inicio)->prox != NULL) {
			if (((*inicio)->prox)->info != n) {
				i = i + excluirAntes(n, &((*inicio)->prox));
			}
			else {

				tno *aux = ((*inicio)->prox);
				i = (*inicio)->info;
				free(*inicio);
				(*inicio) = aux;
				//printf("deu certo %d\n", i);
				return i;
			}
		}
		else {
			printf("Nao existe o valor %d na lista\n", n);
		}
	}
	return i;
}

void imprimeInicio(tno *inicio) {
	printf("primeiro valor = %d\n", inicio->info);
}

void imprimeFinal(tno *inicio) {
	if (inicio->prox != NULL) {
		imprimeFinal(inicio->prox);
	}
	else {
		printf("ultimo valor = %d\n", inicio->info);
	}
}

void imprimeK(int posicao, tno *inicio) {
	int tam = tamanho(inicio);
	if (posicao == 0)
	{
		imprimeInicio(inicio);
	}
	else {
		if (tam < posicao) {
			printf("Nao existe posicao na lista\n");
		}
		else {
			int cont = 0;
			while (cont < posicao - 1) {
				inicio = inicio->prox;
				cont++;
			}
			printf("valor da posicao %d = %d\n", posicao, inicio->info);
		}
	}
}

int soma(tno *inicio) {
	int s = 0;
	while (inicio != NULL) {
		s += inicio->info;
		inicio = inicio->prox;
	}
	return s;
}

int existe(int valor, tno *inicio) {
	int ret = 0;
	while (inicio != NULL) {
		if (inicio->info == valor) {
			ret = 1;
		}
		inicio = inicio->prox;
	}
	return ret;
}

void copia(tno *inicio, tno **nova) {
	if (inicio != NULL) {
		inserirFinal(inicio->info, &(*nova));
		copia(inicio->prox, &((*nova)));
	}
}

void inverte(tno **inicio) {
	tno *aux = NULL;
	while ((*inicio) != NULL) {
		inserirInicio((*inicio)->info, &aux);
		(*inicio) = (*inicio)->prox;
	}
	copia(aux, &(*inicio));
}

void concatena(tno **A, tno *B) {
	while (B != NULL) {
		inserirFinal(B->info, &(*A));
		B = B->prox;
	}

}

int iguais(tno *A, tno *B) {
	int ret = 1, i, tamA = tamanho(A), tamB = tamanho(B);
	if (tamA != tamB) {
		ret = 0;
	}
	else {
		while (A != NULL) {
			if (A->info != B->info) {
				ret = 0;
			}
			A = A->prox;
			B = B->prox;
		}
	}
	return ret;

}

tno *uniao(tno *A, tno *B) {
	tno *ret = NULL;
	copia(A, &ret);
	while (B != NULL) {
		if (existe(B->info, ret) == 0) {
			inserirFinal(B->info, &ret);
		}
		B = B->prox;
	}
	return ret;
}

tno *interseccao(tno *A, tno *B) {
	tno *ret = NULL;
	while (B != NULL) {
		if (existe(B->info, A) == 1) {
			inserirFinal(B->info, &ret);
		}
		B = B->prox;
	}
	return ret;
}

void inserirOrdenado(int n, tno **inicio) {
	int cont = 0;
	tno *aux = NULL;
	copia((*inicio), &aux);
	if ((*inicio) == NULL) {
		inserirInicio(n, &(*inicio));
	}
	else {
		if (n < (aux)->info) {
			inserirInicio(n, &(*inicio));
		}
		else {
			while ((aux)->prox != NULL) {
				if ((n >(aux)->info) && (n < (aux->prox)->info)) {
					cont++;
					inserirDepois(n, (aux)->info, &(*inicio));
				}

				(aux) = (aux)->prox;
			}
			if (cont == 0) {
				inserirFinal(n, &(*inicio));
			}
		}
	}
}
void ordenar(tno **inicio) {
	tno *aux = NULL;
	while ((*inicio) != NULL) {
		inserirOrdenado((*inicio)->info, &(aux));
		(*inicio) = (*inicio)->prox;

	}
	copia(aux, &(*inicio));
}