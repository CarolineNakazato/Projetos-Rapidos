#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main() {
	char nomeTime[5][21], ordemAlfabetica[5][21], quemVenceu[21], aux[21];
	int resp, i, k = 1, j, maiorAbate,totalAbates, pos, maior, totalObj = 0, objCasa, objVisitante;
	int tabela[4][4], pontos[4] = { 0, 0, 0, 0 }, abates[4] = { 0, 0, 0, 0 };

	printf("---------------- Campeonato de LOL --------------------\n");

	printf("Escolha uma opcao:\n");
	printf("1) Cadastrar times.\n");
	printf("2) Gerar campeonato.\n");
	printf("3) Sair.\n");

	scanf("%i", &resp);

	while (resp != 3) {
	
		switch (resp)
		{
		case 1:
			while (k < 3) {
				printf("Digite o nome do time %i: \n", k);
				getchar();
				scanf("%s", nomeTime[k - 1]);
				k++;
			}
			break;

		case 2:
			for (i = 0; i < 1; i++) {
				for (j = i+1; j < 2; j++) {
					printf("Digite se foi time da casa ou o time visitante. \n");

					getchar();
					scanf("%s", quemVenceu);

					if (strcmp(quemVenceu, "timedacasa") == 0) {
						pontos[i] += 2;
						pontos[j] += 1;
					}
					else {
						pontos[j] += 2;
						pontos[i] += 1;
					}

					printf("Digite a quantidade de abates do time da casa e do time visitante, respectivamente:\n");

					scanf("%i", &abates[i]);
					scanf("%i", &abates[j]);

					printf("Digite a quantidade de objtivos concluidos do time da casa e do time visitante, respectivamente:\n");

					scanf("%i", &objCasa);
					scanf("%i", &objVisitante);
					totalObj += objCasa + objVisitante;
				}
			}

			
			for (j = 0; j < 2; j++) {
			maior = pontos[0];
			pos = 0;
				for (i = 0; i < 2; i++) { 
					if (pontos[i] > maior) {
						maior = pontos[i];
						pos = i;
					}
				}
				printf("Time %s com %i pontos.\n", nomeTime[pos], maior);
				pontos[pos] = 0;
			}


			totalAbates = 0;
			maiorAbate = abates[0];
			pos = 0;

			for (i = 0; i < 2; i++) {
				if (abates[i] > maiorAbate) {
					maiorAbate = abates[i];
					pos = i;
				}
				totalAbates += abates[i];
			}
			printf("Time com mais abates %s com %i abates\n", nomeTime[pos], maiorAbate);
			printf("Total de abates: %i\n", totalAbates);

			printf("Total de objetivos: %i\n", totalObj);

			for (i = 0; i < 1; i++) {
				for (j = 0; j < 1-i; j++) {
					if (strcmp(nomeTime[j],nomeTime[j+1])>0)
					{
						strcpy(aux,nomeTime[j]);
						strcpy(nomeTime[j + 1], nomeTime[j]);
						strcpy(nomeTime[j], aux);
					}
				}
			}

			printf("Nome dos times em ordem alfabetica: \n", nomeTime[j]);
			for (j = 0; j < 2; j++) {
				printf("Time %s.\n", nomeTime[j]);
			}

			break;

		default:
			break;
		}
		printf("Escolha uma opcao:\n");
		printf("1) Cadastrar times.\n");
		printf("2) Gerar campeonato.\n");
		printf("3) Sair.\n");

		scanf("%i", &resp);
	}

	system("pause");
}
