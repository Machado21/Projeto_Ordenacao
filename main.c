#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prototipos.h"

int existe(int valores[], int tamanho, int valor)
{
    int i;
    for (i = 0; i < tamanho; i++){
        if (valores[i] == valor){
            return 1;
        }
    }
    return 0;
}

void geraNumeros(int numeros[], int quantNumeros, int limite)
{
    srand(time(NULL));

    int valor, i;
    for (i = 0; i < quantNumeros; i++){
        valor = rand() % limite;
        while (existe(numeros, i, valor)){
            valor = rand() % limite;
        }
        numeros[i] = valor;
    }
}

int main()
{
    int i, n = 1;
    int numeros[10];
    FILE* arquivo;
    //Menu Principal
    printf("\n\t|| Projeto Ordenacao ||\n");
    do{
        printf("1 - Gerar Arquivo\n");
        printf("2 - Ordenar Arquivo\n");
        printf("3 - Sair\n");
        scanf("%d", &n);

        if (n == 1){
            geraNumeros(numeros, 10, 11);
            arquivo = fopen("numeros.txt", "w+");
            if (arquivo == NULL){
                printf("!!! ERRO ao Tentar abrir o arquivo");
            }
            for (i = 0; i < 10; i++){
                fprintf(arquivo, "%d ", numeros[i]);
                printf("%d\t", numeros[i]);
            }
        }else if (n == 2){
            // ### BUBBLES ###
            //BubbleSort(numeros,10);
            arquivo = fopen("BubbleSort.txt", "w+");
            if (arquivo == NULL){
                printf("!!! ERRO ao Tentar abrir o arquivo");
            }
            for (i = 0; i < 10; i++){
                printf("%d\t", numeros[i]);
            }
            fclose(arquivo);
            // ### SELECTION ###
            //selection_sort(numeros,10);
            arquivo = fopen("SelectionSort.txt", "w+");
            if (arquivo == NULL){
                printf("!!! ERRO ao Tentar abrir o arquivo");
            }
            for (i = 0; i < 10; i++){
                printf("%d\t", numeros[i]);
            }
            fclose(arquivo);
            // ### INSERTION ###
            //insertionSort(numeros,10);
            arquivo = fopen("InsertionSort.txt", "w+");
            if (arquivo == NULL){
                printf("!!! ERRO ao Tentar abrir o arquivo");
            }
            for (i = 0; i < 10; i++){
                printf("%d\t", numeros[i]);
            }
            fclose(arquivo);
            // ### RADIX ###
            radixsort(numeros, 10);
            arquivo = fopen("RadixSort.txt", "w+");
            if (arquivo == NULL){
                printf("!!! ERRO ao Tentar abrir o arquivo");
            }
            for (i = 0; i < 10; i++){
                printf("%d\t", numeros[i]);
            }
            fclose(arquivo);
        }
        printf("Deseja Voltar ao Menu Principal ???");
        scanf("%d", &n);
    }while(n == 4);
    fclose(arquivo);
    return 0;
}