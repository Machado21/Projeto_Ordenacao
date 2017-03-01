#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prototipos.h"

int main()
{
	int i, n = 1;
	int numeros_100[100];
	int numeros_1000[1000];
	int numeros_10000[10000];
	char numeros[10000];
	char* numero;
	FILE* arquivo;

	/** Menu Principal **/
	printf("\n\t|| Projeto Ordenacao ||\n");
	do {
		printf("1 - Gerar Arquivo\n");
		printf("2 - Ordenar Arquivo\n");
		printf("3 - Sair\n");
		scanf("%d", &n);
		if (n == 3)
		{                   /* saída do programa */
			break;
		}
		if (n == 1) {
			geraArquivo();  /* Gera arquivos com numeros desordenados */
			printf("Arquivos Gerados com sucesso !!!\n");
		}
		else if (n == 2) {
			arquivoOrdenadoBubbleSort100();
			arquivoOrdenadoBubbleSort1000();
			printf("\n");


		}
		printf("\n3 - Deseja Voltar ao Menu Principal ???\n\n");
		scanf("%d", &n);
	} while (n == 3);
	system("pause");
	return 0;
}
