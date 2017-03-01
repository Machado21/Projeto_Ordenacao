#include <stdlib.h>
#include <stdio.h>
#include "prototipos.h"

int existe(int valores[], int tamanho, int valor)
{
	int i;
	for (i = 0; i < tamanho; i++) {
		if (valores[i] == valor) {
			return 1;
		}
	}
	return 0;
}

void geraNumeros(int numeros[], int quantNumeros, int limite)
{
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


void BubbleSort(int *vet, int n) {
	int quantTrocas, quantComparacoes;
	quantTrocas = quantComparacoes = 0;
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
            quantComparacoes++;
		}
		fim--;
	} while (continua != 0);
	printf("Quantidade de Trocas: %d\n", quantTrocas);
	printf("Quantidade de Comparacoes: %d\n", quantComparacoes);

}
void selection_sort(int num[], int tam) {
	int quantTrocas, quantComparacoes;
	quantTrocas = quantComparacoes = 0;
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
		quantComparacoes++;
	}
	printf("SELECTION SORT\n");
	printf("Quantidade de Trocas: %d\n", quantTrocas);
	printf("Quantidade de Comparacoes: %d\n", quantComparacoes);
}
void insertionSort(int vetor[], int tamanho) {
    int quantTrocas, quantComparacoes;
	quantTrocas = quantComparacoes = 0;

	int i, sel, aux;

	for (i = 1; i < tamanho; i++) {
		sel = i;
		while (sel > 0 && vetor[sel] < vetor[sel - 1]) {
			aux = vetor[sel - 1];
			vetor[sel - 1] = vetor[sel];
			vetor[sel] = aux;
			sel--;
			quantTrocas++;
		}
		quantComparacoes++;
	}
	printf("INSERTION SORT\n");
	printf("Quantidade de Trocas: %d\n", quantTrocas);
	printf("Quantidade de Comparacoes: %d\n", quantComparacoes);
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
int particiona(int *vet , int inicio ,int fim){
    int quantComparacoes;
	quantComparacoes = 0;
    int quantTrocas;
	quantTrocas = 0;
    int esq, dir , pivo , aux;
    esq = inicio;
    dir = fim ;
    pivo = vet[inicio];
    while (esq < dir){
        while(vet[esq] <= pivo){
            esq++;
        }
        while(vet[dir] > pivo){
            dir--;
        }
        if( esq < dir){
            aux = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = aux;
            quantTrocas++;
        }
        quantComparacoes++;
    }
    vet[inicio] = vet[dir];
    vet[dir] = pivo;

    printf("QUICK SORT\n");
	printf("Quantidade de Comparacoes: %d\n", quantComparacoes);
	printf("Quantidade de Trocas: %d\n", quantTrocas);

    return dir;
}

void quick(int vet[], int inicio, int fim){
    int pivo;
    if( fim > inicio){
        pivo = particiona( vet , inicio , fim);
        quick(vet , inicio , pivo - 1);
        quick(vet , pivo + 1 , fim);
    }
}

 void mergeSort(int *vetor, int posicaoInicio, int posicaoFim) {

    int quantTrocas, quantComparacoes;
	quantTrocas = quantComparacoes = 0;

    int i, j, k, metadeTamanho, *vetorTemp;

    if(posicaoInicio == posicaoFim) return;

    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);


    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) {
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == posicaoFim + 1) {
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                    quantTrocas++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                    quantTrocas++;
                }
            }
        }
        quantComparacoes++;

    }
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
    printf("MERGE SORT\n");
	printf("Quantidade de Comparacoes: %d\n", quantComparacoes);
	printf("Quantidade de Trocas: %d\n", quantTrocas);
}

 int buscaLinear(char vetor[], int tamanho, char elementoProcurado) {
     int i;
     for (i = 0; i < tamanho; i++) {
         if (vetor[i] == elementoProcurado) {
             return i;
         }
     }

     return -1;
 }

 int PesquisaBinaria ( int vet[], int chave, int Tam)
{
     int inf = 0;
     int sup = Tam-1;
     int meio;
     while (inf <= sup)
     {
          meio = (inf + sup)/2;
          if (chave == vet[meio])
               return meio;
          if (chave < vet[meio])
               sup = meio-1;
          else
               inf = meio+1;
     }
     return -1;
}

void heapsort(int a[], int n) {
   int i = n / 2, pai, filho, t;
   for (;;) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}



// ### GERA ARQUIVO .TXT

void geraArquivo()
{
	int i;
	FILE* arquivo;
	FILE* arquivo1;
	FILE* arquivo2;
	FILE* arquivo3;
	int numeros_100[100];
	int numeros_1000[1000];
	int numeros_10000[10000];
	int numeros_100000[100000];

	/** 100 NUMEROS **/
	geraNumeros(numeros_100, 100, 101);
	arquivo = fopen("100_numeros.txt", "w");
	if (arquivo == NULL) {
		printf("!!! ERRO ao Tentar abrir o arquivo de escrita !!!\n\n");
		exit(0);
	}
	for (i = 0; i < 100; i++) {
		fprintf(arquivo, "%d ", numeros_100[i]);
	}
	fclose(arquivo);
	/*** 1000 NUMEROS ***/
	geraNumeros(numeros_1000, 1000, 1001);
	arquivo1 = fopen("1000_numeros.txt", "w+");
	if (arquivo1 == NULL) {
		printf("!!! ERRO ao Tentar abrir o arquivo !!!\n\n");
		exit(0);
	}
	for (i = 0; i < 100; i++) {
		fprintf(arquivo1, "%d ", numeros_1000[i]);
	}
	fclose(arquivo1);

	/** 10000 NUMEROS **/
	geraNumeros(numeros_10000, 10000, 10001);
	arquivo2 = fopen("10000_numeros.txt", "w+");
	if (arquivo2 == NULL) {
		printf("!!! ERRO ao Tentar abrir o arquivo !!!\n\n");
		exit(0);
	}
	for (i = 0; i < 10000; i++) {
		fprintf(arquivo2, "%d ", numeros_10000[i]);
	}
	fclose(arquivo2);

	/** 100.000 NUMEROS **/

	/*geraNumeros(numeros_100000, 100000, 100001);
	arquivo3 = fopen("100000_numeros.txt", "w+");
	if (arquivo3 == NULL) {
		printf("!!! ERRO ao Tentar abrir o arquivo !!!\n\n");
		exit(0);
	}
	for (i = 0; i < 100000; i++) {
		fprintf(arquivo3, "%d ", numeros_100000[i]);
	}
	fclose(arquivo3);*/
}
void arquivoOrdenadoBubbleSort100(){

    int numeros_100[100];
	char numeros[1000];
	char* numero;
	FILE* arquivo;
	int i;

    /* Leitura do Arquivo */

			/** LEITURA DE ARQUIVO DE 100 numeros **/

 			arquivo = fopen("100_numeros.txt","r");
			if (arquivo == NULL)
			{
				printf("\n\t!!! ERRO Ao tentar abrir o arquivo de leitura\n\n");
				system("pause");
				exit(0);
			}
			numeros[0] = fgetc(arquivo);
			for (i = 1; numeros[i-1] != EOF; i++) {
				numeros[i] = fgetc(arquivo);  /** LEITURA DE NUMERO POR NUMERO **/
			}
			numeros[i-1] = '\0';
			numero = strtok(numeros, " ");
			for (i = 0; numero != NULL; i++)
			{
				numeros_100[i] = atoi(numero); // COPIA DO VETOR AUX NUMEROS para numeros
				numero = strtok(NULL, " ");     // 100.
			}

			/** BUBBLE SORT **/
            printf("BUBBLE SORT 100 NUMEROS\n");
			BubbleSort(numeros_100, 100);
			arquivo = fopen("BubbleSort_100ORDENADO.txt", "w+");
			if (arquivo == NULL) {
				printf("!!! ERRO ao Tentar abrir o arquivo !!!\n\n");
			}
			for (i = 0; i < 100; i++) {
				fprintf(arquivo, "%d ", numeros_100[i]);
			}
			printf("\n");
			fclose(arquivo);

}

void arquivoOrdenadoBubbleSort1000(){

    int numeros_1000[1000];
	char numeros[10000];
	char* numero;
	FILE* arquivo;
	int i;

    /* Leitura do Arquivo */

			/** LEITURA DE ARQUIVO DE 1000 numeros **/

 			arquivo = fopen("1000_numeros.txt","r");
			if (arquivo == NULL)
			{
				printf("\n\t!!! ERRO Ao tentar abrir o arquivo de leitura\n\n");
				system("pause");
				exit(0);
			}
			numeros[0] = fgetc(arquivo);
			for (i = 1; numeros[i-1] != EOF; i++) {
				numeros[i] = fgetc(arquivo);  /** LEITURA DE NUMERO POR NUMERO **/
			}
			numeros[i-1] = '\0';
			numero = strtok(numeros, " ");
			for (i = 0; numero != NULL; i++)
			{
				numeros_1000[i] = atoi(numero); // COPIA DO VETOR AUX NUMEROS para numeros
				numero = strtok(NULL, " ");     // 100.
			}

			/** BUBBLE SORT **/
            printf("BUBBLE SORT 1000 NUMEROS\n");
			BubbleSort(numeros_1000, 1000);
			arquivo = fopen("BubbleSort_1000ORDENADO.txt", "w+");
			if (arquivo == NULL) {
				printf("!!! ERRO ao Tentar abrir o arquivo !!!\n\n");
			}
			for (i = 0; i < 1000; i++) {
				fprintf(arquivo, "%d ", numeros_1000[i]);
			}
			printf("\n");
			fclose(arquivo);





}
