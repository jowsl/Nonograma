// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <stdlib.h>

int** alocaMatriz(int m, int n);
void liberaMatriz(int** matriz, int m);
void ajustes(int** matriz,int** matrizTemporaria, int X, int Y, int M, int N);
void printMatriz(int** matriz, int M, int N);
void lerDimensoes(int* M, int* N);
void lerMatriz(int** matriz, int M, int N);