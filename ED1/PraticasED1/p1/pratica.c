// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <stdlib.h>
#include "pratica.h"


int main(int argc, char *argv[]){
    int M, N, **matriz, X , Y, **matrizTemporaria, contadorTestes = 0;

    lerDimensoes(&M, &N);
    while ((M != 0) && (N != 0)){
        contadorTestes++;
        matriz = alocaMatriz(M, N);
        matrizTemporaria = alocaMatriz(M, N);
        lerMatriz(matriz, M, N);

        scanf("%d %d", &X, &Y);
        while ((X != 0) || (Y != 0)){
            ajustes(matriz, matrizTemporaria, X, Y, M, N);
            scanf("%d %d", &X, &Y);
        }
        
        printf("Teste %d\n", contadorTestes);
        printMatriz(matriz, M, N);
        printf("\n");

        liberaMatriz(matriz, M);
        liberaMatriz(matrizTemporaria, M);
        lerDimensoes(&M, &N);
    }
    return 0;
}

void lerMatriz(int** matriz, int M, int N){
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

int** alocaMatriz(int m, int n){ 
    int **matriz = malloc (m * sizeof(int*));
    if (matriz == NULL){
        printf("Erro de alocação de memória -- DEBUG\n");
    }
    
    for (int i = 0; i < m; i++){
        matriz[i] = malloc(n * sizeof(int));
    }
    return matriz;
}

void liberaMatriz(int** matriz, int m){
    for (int i = 0; i < m; i++){
        free(matriz[i]);
    }
    free(matriz);
}

void ajustes(int** matriz, int** matrizTemporaria, int X, int Y, int M, int N){
    // matriz será deslocada para direita, ou não será afetada se X = 0. armazenada
    // printf("debug teste --- AJUSTE ");

    for (int i = 0; i <M; i++){
        for (int j = 0; j < N; j++){

            int deslocarX = (j + X) % N; // direita esquerda
            int deslocarY = (i - Y) % M; // cima baixo
            if (deslocarX < 0) 
                deslocarX += N; // caso seja negativo, soma com N para ir para direita
            if (deslocarY < 0) 
                deslocarY += M; // caso seja negativo, soma com M para ir para cima
            
            matrizTemporaria[deslocarY][deslocarX] = matriz[i][j];
        }
    }
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            matriz[i][j] = matrizTemporaria[i][j];
        }
    }
}   

void printMatriz(int** matriz, int M, int N){
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void lerDimensoes(int* M, int* N){
    scanf("%d %d", M, N);
}