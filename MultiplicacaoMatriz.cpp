#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#define LinhaA 2
#define LinhaB 2
#define ColunaA 2
#define ColunaB 2
// so eh possivel multiplicar duas matrizes se a LinhaA for igual a LinhaB

void main() {
	//multiplicacao de matriz
	int A[LinhaA][ColunaA];
	int B[LinhaB][ColunaB];
	int C[LinhaA][ColunaB];
	int linha, coluna, soma=0, i, k, j;

	printf("---------------- Multiplicao de Matrizes --------------------\n");

	printf("Digite os valores da matriz A: \n");
	for (linha = 0; linha < LinhaA; linha++) {
		for (coluna = 0; coluna < ColunaB; coluna++)
			scanf("%i",&A[linha][coluna]);
	}
	
	printf("Digite os valores da matriz B: \n");
	for (linha = 0; linha < LinhaA; linha++) {
		for (coluna = 0; coluna < ColunaB; coluna++)
			scanf("%i", &B[linha][coluna]);
	}

	for (i = 0; i < LinhaB; i++) {
		for (j = 0; j < ColunaA; j++) {
			for (k = 0; k < LinhaA; k++){ //linhaA == ColunaB
				soma +=  (A[i][k] * B[k][j]);
			}
			
			C[i][j] = soma;
			soma = 0;
		}
	}

	//printa Matriz C
	printf("Matriz C Resultante: \n");
	for (linha = 0; linha < LinhaA; linha++) {
		for (coluna = 0; coluna < ColunaB; coluna++)
			printf("%i ", C[linha][coluna]);
		printf("\n");
	}

	/*
	//Printa Matriz A
	printf("Matriz A: \n");
	for (linha = 0; linha < LinhaA; linha++) {
		for (coluna = 0; coluna < ColunaA; coluna++)
			printf("%i ", A[linha][coluna]);
		printf("\n");
	}

	//Printa Matriz B
	printf("Matriz B: \n");
	for (linha = 0; linha < LinhaB; linha++) {
		for (coluna = 0; coluna < ColunaB; coluna++)
			printf("%i ", B[linha][coluna]);
		printf("\n");
	}*/

	system("pause");
}
