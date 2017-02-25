/*
 * main.c
 *
 *  Created on: 25 de fev de 2017
 *      Author: gabri
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prototipos.h"

int existe(int valores[], int tamanho, int valor) {
	int i;
	for (i = 0; i < tamanho; i++) {
		if (valores[i] == valor) {
			return 1;
		}
	}
	return 0;
}

void geraNumeros(int numeros[], int quantNumeros, int limite) {
	srand(time(NULL));

	int valor, i;
	for (i = 0; i < quantNumeros; i++) {
		valor = rand() % limite;
		while (existe(numeros, i, valor)) {
			valor = rand() % limite;
		}
		numeros[i] = valor;
	}
}

int main() {
	int i, n;
	int numeros[10];
	FILE* arquivo;
	printf("%B0%B1%B2 Projeto Ordenacao %B2%B1%B0");
	printf("1 - Gerar Arquivo");
	scanf("%d", &n);
	printf("2 - Ordenar Arquivo");
	scanf("%d", &n);
	printf("3 - Sair");
	scanf("%d", &n);
	if(n == 1){
	arquivo = fopen("numeros.txt", "+w");
	if (arquivo == NULL) {
		printf("!!! ERRO ao Tentar abrir o arquivo");
	}
	geraNumeros(numeros, 10, 11);
	}
	for (i = 0; i < 10; i++) {
		printf("%d\t", numeros[i]);
	}
	//BubbleSort(numeros,10);
	//selection_sort(numeros,10);
	//insertionSort(numeros,10);
	radixsort(numeros, 10);
	for (i = 0; i < 10; i++) {
		printf("%d\t", numeros[i]);
	}
	return 0;
}
