/**
------------------Exercicios Estrutura de Dados A (Ponteiros)-----------------------
1. Declare uma variável inteira n e um ponteiro ptrn para essa variável. Atribua um
valor para n. A seguir, imprima o valor de n a partir de ptrn. Imprima também o
endereço de n e de ptrn.
2. A partir do exercício anterior, incremente o valor de n usando apenas o ponteiro
ptrn. Imprima o novo valor de n para confirmar se está correto.
3. Declare duas variáveis inteiras m e n e dois ponteiros para elas. Atribua valores
para as variáveis. Descubra qual o maior valor, acessando-as somente através dos
ponteiros. Imprima esse valor.
4. Descubra (e imprima) o valor da maior variável do exercício anterior, através da
função maior, cujos parâmetros devem m e n.
5. Descubra (e imprima) o valor da maior variável do exercício anterior, através da
função maior, cujos parâmetros devem os ponteiros para m e n.
**/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>

void maior(int *p, int *l);
void maior2(int p, int l);

void main() {
	int n, m, *ptrm, *ptrn;
	n = 10;
	m = 12;

	ptrn = &n;
	ptrm = &m;
	
	*ptrn = *ptrn +1;
	printf("%d %d %d \n", *ptrn, &n, &ptrn);

	maior(ptrm, ptrn);
	//maior(&n, &m);

	//maior2(*ptrm, *ptrn);
	//maior2(n, m);

system("pause");

}
void maior(int *p, int *l) {
	if (*p >= *l) {
		printf("maior valor eh %d\n", *p);
	}
	else {
		printf("maior valor eh %d\n", *l);
	}
}
void maior2(int p, int l) {
	if (p >= l) {
		printf("maior valor eh %d\n", p);
	}
	else {
		printf("maior valor eh %d\n", l);
	}
}