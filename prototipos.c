#include <stdlib.h>
#include <stdio.h>
#include "prototipos.h"

void BubbleSort(int *vet, int n) {
	int quantTrocas, quantIteracoes;
	quantTrocas = quantIteracoes = 0;
	int i, continua, aux, fim = n;
	do {
		continua = 0;
		for (i = 0; i < fim - 1; i++) {
			if (vet[i] > vet[i + 1]) {
				aux = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = aux;
				continua = i;
				quantTrocas++;
			}
		}
		fim--;
		quantIteracoes++;
	} while (continua != 0);
	printf("Quantidade de Trocas: %d\n", quantTrocas);
	printf("Quantidade de Iteracoes: %d\n", quantIteracoes);

}
void selection_sort(int num[], int tam) {
	int quantTrocas, quantIteracoes;
	quantTrocas = quantIteracoes = 0;
	int i, j, min, aux;
	for (i = 0; i < (tam - 1); i++) {
		min = i;
		for (j = (i + 1); j < tam; j++) {
			if (num[j] < num[min])
				min = j;
		}
		if (i != min) {
			aux = num[i];
			num[i] = num[min];
			num[min] = aux;
			quantTrocas++;
		}
		quantIteracoes++;
	}
	printf("Quantidade de Trocas: %d\n", quantTrocas);
	printf("Quantidade de Iteracoes: %d\n", quantIteracoes);
}
void insertionSort(int vetor[], int tamanho) {

	int i, sel, aux;

	for (i = 1; i < tamanho; i++) {
		sel = i;
		while (sel > 0 && vetor[sel] < vetor[sel - 1]) {
			aux = vetor[sel - 1];
			vetor[sel - 1] = vetor[sel];
			vetor[sel] = aux;
			sel--;
		}
	}
}

void radixsort(int vetor[], int tamanho) {
	int i;
	int *b;
	int maior = vetor[0];
	int exp = 1;

	b = (int *)calloc(tamanho, sizeof(int));

	for (i = 0; i < tamanho; i++) {
		if (vetor[i] > maior)
			maior = vetor[i];
	}

	while (maior / exp > 0) {
		int bucket[10] = { 0 };
		for (i = 0; i < tamanho; i++)
			bucket[(vetor[i] / exp) % 10]++;
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (i = tamanho - 1; i >= 0; i--)
			b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
		for (i = 0; i < tamanho; i++)
			vetor[i] = b[i];
		exp *= 10;
	}

	free(b);
}
// ### GERA ARQUIVO .TXT
void geraArquivo()
{
	int i;
	FILE* arquivo;
	FILE* arquivo1;
	FILE* arquivo2;
	int numeros_100[100];
	int numeros_1000[1000];
	int numeros_10000[10000];
	// ### 100 NUMEROS ###
	geraNumeros(numeros_100, 100, 101);
	arquivo = fopen("100_numeros.txt", "w");
	if (arquivo == NULL) {
		printf("!!! ERRO ao Tentar abrir o arquivo de escrita !!!\n\n");
		exit(0);
	}
	for (i = 0; i < 100; i++) {
		fprintf(arquivo, "%d ", numeros_100[i]);
		printf("%d ", numeros_100[i]);
	}
	printf("\n");
	fclose(arquivo);
	// ### 1000 NUMEROS ###
	geraNumeros(numeros_1000, 1000, 1001);
	arquivo1 = fopen("1000_numeros.txt", "w+");
	if (arquivo1 == NULL) {
		printf("!!! ERRO ao Tentar abrir o arquivo !!!\n\n");
		exit(0);
	}
	for (i = 0; i < 100; i++) {
		fprintf(arquivo1, "%d ", numeros_1000[i]);
		printf("%d ", numeros_1000[i]);
	}
	printf("\n");
	fclose(arquivo1);
	// ### 10000 NUMEROS ###
	geraNumeros(numeros_10000, 10000, 10001);
	arquivo2 = fopen("10000_numeros.txt", "w+");
	if (arquivo2 == NULL) {
		printf("!!! ERRO ao Tentar abrir o arquivo !!!\n\n");
		exit(0);
	}
	for (i = 0; i < 10000; i++) {
		fprintf(arquivo2, "%d ", numeros_10000[i]);
		printf("%d ", numeros_10000[i]);
	}
	printf("\n");
	fclose(arquivo2);
}
