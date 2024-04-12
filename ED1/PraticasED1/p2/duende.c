#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duende.h"

struct duende { /* PREENCHER AQUI */ };

struct time { /* PREENCHER AQUI */ };

// Manter como especificado
void lerQuantidade(int *qtdDuendes){ /* PREENCHER AQUI */ }

// Manter como especificado
Duende *alocaDuendes(int qtdDuendes){ /* PREENCHER AQUI */ }

// Manter como especificado
Time *alocaTimes(int qtdTimes){ /* PREENCHER AQUI */ }

// Manter como especificado
void desalocaDuendes(Duende **duendes){ /* PREENCHER AQUI */ }

// Manter como especificado
void desalocaTimes(Time **times){ /* PREENCHER AQUI */ }

// Manter como especificado
void lerDuendes(Duende *duendes, int qtdDuendes){ /* PREENCHER AQUI */ }

// Manter como especificado
void escalarTimes(Duende *duendes, Time *times, int qtdDuendes){
    int i, index;
    int qtdTime = qtdDuendes/4;
    // Escalando os lideres
    for (i=0; i<qtdTime; i++) {
        // Bucar o proximo mais velho disponivel
        // Marca o duende como escalado
        // Copiar o nome do duende encontrado como lider de um time
        // Copiar a idade do duende encontrado como lider de um time
    }

    // Escalando os confeiteiros
    for (i=0; i<qtdTime; i++) {
        // Bucar o proximo mais velho disponivel
        // Marca o duende como escalado
        // Copiar o nome do duende encontrado como confeiteiro de um time
        // Copiar a idade do duende encontrado como confeiteiro de um time
    }

    // Escalando os entregador
    for (i=0; i<qtdTime; i++) {
        // Bucar o proximo mais velho disponivel
        // Marca o duende como escalado
        // Copiar o nome do duende encontrado como entregador de um time
        // Copiar a idade do duende encontrado como entregador de um time
    }

    // Escalando os embrulhador
    for (i=0; i<qtdTime; i++) {
        // Bucar o proximo mais velho disponivel
        // Marca o duende como escalado
        // Copiar o nome do duende encontrado como embrulhador de um time
        // Copiar a idade do duende encontrado como embrulhador de um time
    }
}

int proximoMaisVelho(Duende *duendes, int qtdDuendes){ /* PREENCHER AQUI */ }

// Manter como especificado
void printTimes(Time *times, int qtdTimes){
    for (int i=0; i<qtdTimes; i++) {
        printf("Time %d\n", i+1);
        printf("PILOTO > %s %d\n", times[i]./* PREENCHER AQUI */, times[i]./* PREENCHER AQUI */);
        printf("CONFEI > %s %d\n", times[i]./* PREENCHER AQUI */, times[i]./* PREENCHER AQUI */);
        printf("ENTREG > %s %d\n", times[i]./* PREENCHER AQUI */, times[i]./* PREENCHER AQUI */);
        printf("EMBRUL > %s %d\n\n", times[i]./* PREENCHER AQUI */, times[i]./* PREENCHER AQUI */);
    }
}
