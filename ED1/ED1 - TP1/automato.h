#ifndef FUNCTIONS_H  // pratica comum para evitar erros de compilação
#define FUNCTIONS_H 

int** alocarReticulado(int m);
void desalocarReticulado(int** matriz, int m);
void imprimeReticulado(int** matriz, int m);
int LeituraReticulado(int** matriz, int m); // ler o reticulado do arquivo.
void evoluirReticulado(); // função recursiva que retorna o reticulado após o número de gerações.
int contadorDeVivos(int** matriz, int m);

#endif