#include <stdio.h>
#include <stdlib.h>
#include "automato.h"

/* 
Uma célula viva se mantém viva se tiver 2 (duas) ou 3 (três) células vizinhas vivas; // pode-se ignorar ja que não vai mduar
Celula1 torna-se 0 se ouver: > 3 celulas1 na vizinhança (sufocamento) || se houver < 2 celulas1 próximas (solidão)
Celula0 so vai mudar de 0 para 1 se houver exatamente 3 celulas1 na vizinhança (renascimento)
*/





int main(int argc, char *argv[]){
    int **matriz, dimencoes, geracoes;
    
    matriz = alocarReticulado(m);

    for (int i = 0; i < m; i++){
        for(int j = 0; j < m; j++)
            fscanf(arquivo, "%d", &matriz[i][j]);
    }
    
    printMatriz(matriz, m);
    liberaMatriz(matriz, m);
    return 0;
}