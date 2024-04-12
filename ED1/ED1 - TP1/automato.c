#include <stdio.h>
#include <stdlib.h>
#include "automato.h"

int** alocarReticulado(int m){
    int **matriz = malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++){
        matriz[i] = malloc(m * sizeof(int));
    }
    return matriz;
}

void desalocarReticulado(int** matriz, int m){
    for (int i = 0; i < m; i++)
        free(matriz[i]);
    free(matriz);
}

void imprimeReticulado(int** matriz, int m){
        // print matriz
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

int LeituraReticulado(int** matriz, int m){
    FILE *arquivo = fopen (, "r");
    // check se existe o arquivo
    if(arquivo == NULL){
        printf("Arquivo não encontrado!");
        return 0;
    }

    fscanf(arquivo, "%d", &dimencoes);
    int m = dimencoes;
    fscanf(arquivo, "%d", &geracoes);
    fclose(arquivo);
}


/// Checagem das regras
int contadorDeVivos(int** matriz, int m){
    int cont = 0;
    for(int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            matriz

        }   
    }
    return cont;
}



