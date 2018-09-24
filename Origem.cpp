#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#define N 50;
#define bloco 25;

typedef struct {
	int ra;
	char nome[20];
	float nota;
} aluno;

void bubble(aluno x[], int t) {
	int i, j;
	aluno aux; 
	int teste = 1; 
	for (i = 0; i < t - 1 && teste; i++) {
		teste = 0;
		for (j = 0; j < t - i - 1; j++) {
			if (x[j].ra > x[j + 1].ra) {
				teste = 1;
				aux = x[j]; 
				x[j] = x[j + 1];
				x[j+1] = aux;
			}
		}
	}
}

void sobra(FILE *arq1, FILE *arq2, FILE *arq3, int j, int jj, int c, long  tamanho, int k, aluno tab[], int comp_corrida, int ini_c)
{

	while (j< jj) {
		tab[k++] = tab[j++];
		c++;
	}

	fwrite(&tab[2 * 25], tamanho, 25, arq3);

	while (c< comp_corrida) {
		fseek(arq1, ini_c*tamanho, 0);
		fread(&tab[jj - 25], tamanho, 25, arq1);
		fwrite(&tab[2 * 25], tamanho, 25, arq3);
		ini_c = ini_c + bloco;
		c = c + bloco;
	}


}

void intercala(FILE *arq1, FILE *arq2, FILE *arq3, int comp_corrida)
{
	aluno tab[50];
	long tamanho = sizeof(aluno);
	int ini_c1, ini_c2, c1, c2, i, j, k;
	int nn = 0;

	do {

		i = bloco; j = 2 * bloco; k = 2 * bloco;
		c1 = 0; c2 = 0;
		ini_c1 = nn * comp_corrida;
		nn = nn + 1;
		ini_c2 = nn * comp_corrida;
		nn = nn + 1;
		do {
			if (i == 25) {
				fseek(arq1, ini_c1*tamanho, 0);
				fread(&tab[0], tamanho, 25, arq1);
				ini_c1 = ini_c1 + bloco;
				i = 0;
			}
			if (j == 2 * 25) {
				fseek(arq1, ini_c2*tamanho, 0);
				fread(&tab[25], tamanho, 25, arq1);
				ini_c2 = ini_c2 + bloco;
				j = bloco;
			}

			do {

				if (tab[i].ra < tab[j].ra) {
					tab[k] = tab[i];
					k = k + 1;
					i = i + 1;
					c1 = c1 + 1;
				}
				else
				{
					tab[k] = tab[j];
					k = k + 1;
					j = j + 1;
					c2 = c2 + 1;
				}
			} while ((k<3 * 25) && (i<25) && (j<2 * 25));

			if (k == 3 * 25) {
				fwrite(&tab[2 * 25], tamanho, 25, arq3);
				k = 2 * bloco;
			}

		} while ((c1< comp_corrida) && (c2<comp_corrida));


		if (c2< comp_corrida)
			sobra(arq1, arq2, arq3, j, 2 * 25, c2, tamanho, k, tab, comp_corrida, ini_c2);

		if (c1<comp_corrida)
			sobra(arq1, arq2, arq3, i, 25, c1, tamanho, k, tab, comp_corrida, ini_c1);

	} while (nn*comp_corrida < 50);



}

void main() {
	FILE *arq,*arq2, *arq3;
	aluno ord1[50], ord2[50], ord3[100];
	int i,j;
	
	// Abre um arquivo TEXTO para LEITURA
	arq = fopen("DADOS1.DAT", "rb");
	if (arq == NULL)  // Se houve erro na abertura
	{
		printf("Problemas na abertura do arquivo\n");
		//return;
	}
	else {
		i = 0;
		while ((!feof(arq))&&(i<50))
		{
			// Lê uma linha (inclusive com o '\n')
			fread(&ord1[i], sizeof(aluno), 50, arq);
			//printf("ra =  %d nome =  %s nota = %f\n", ord1[i].ra, ord1[i].nome, ord1[i].nota);
			i++;
		}
		fclose(arq);
	}


	arq2 = fopen("DADOS2.DAT", "rb");
	if (arq2 == NULL)  // Se houve erro na abertura
	{
		printf("Problemas na abertura do arquivo 2\n");
		//return;
	}
	else {
		j = 0;
		printf("-----2------\n");
		while ((!feof(arq2)) && (j<50))
		{
			// Lê uma linha (inclusive com o '\n')
			fread(&ord2[j], sizeof(aluno), 50, arq2);
			
			printf("ra =  %d nome =  %s nota = %f\n", ord2[j].ra, ord2[j].nome, ord2[j].nota);
			printf("j =  %d \n", j);
			j++;
		}
		fclose(arq2);
	}


	bubble(ord1, 50);
	bubble(ord2, 50);



	if ((arq = fopen("DADOS1.DAT", "wb")) == NULL) /* Abre arquivo bin�rio para escrita */
	{
		printf("Erro na abertura do arquivo\n");
	}
	else {
		for (i = 0; i < 50; i++)
			fwrite(&ord1[i], sizeof(aluno), 50, arq);
		fclose(arq);
	}

	if ((arq2 = fopen("DADOS2.DAT", "wb")) == NULL) /* Abre arquivo bin�rio para escrita */
	{
		printf("Erro na abertura do arquivo\n");
	}
	else {
		for (i = 0; i < 50; i++)
			fwrite(&ord2[i], sizeof(aluno), 50, arq2);
		fclose(arq2);
	}

	intercala(arq, arq2, arq3, 75);

	arq3 = fopen("DADOS3.DAT", "rb");
	if (arq == NULL)  // Se houve erro na abertura
	{
		printf("Problemas na abertura do arquivo\n");
		//return;
	}
	else {
		i = 0;
		while ((!feof(arq3)) && (i<100))
		{
			// Lê uma linha (inclusive com o '\n')
			fread(&ord3[i], sizeof(aluno), 100, arq3);
			printf("ra =  %d nome =  %s nota = %f\n", ord3[i].ra, ord3[i].nome, ord3[i].nota);
			i++;
		}
		fclose(arq);
	}
	system("pause");
}