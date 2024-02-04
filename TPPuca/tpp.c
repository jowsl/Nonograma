//Caua Guenrick Alves 23.2.4002
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdio_ext.h>


int** alocaMatriz(int m, int n){
    int **matriz;
    matriz = malloc(m * sizeof(int*));      
    for(int i = 0; i < m; i++){
        matriz[i] = malloc(n * sizeof(int));
    }
    
    return matriz;
}

void imprimeCabecalhocol(int *qnumero, int tamanhocol, int **matcol, int numspc){
    int maiornum = matcol[0][0];
    int maiorq = qnumero[0];   
    //Verifica qual o maior valor da matriz para conferir se é maior que 10.
    for (int i = 0; i < tamanhocol; i++){ 
        for (int j = 0; j < qnumero[i]; j++){
            if(matcol[i][j] > maiornum)
            maiornum = matcol[i][j];  
        }
    }   
    
    //Verifica qual valor de qnumero e maior(o espacamento vai ser definido baseado nesse valor).
    for (int i = 1; i < tamanhocol; i++){
        if (qnumero[i] > maiorq)
            maiorq = qnumero[i];
    }
    //Para calcular os espacos.
    int *vdespc = malloc(tamanhocol * sizeof(int)), *vdespcaux = malloc(tamanhocol * sizeof(int)), test = -1;
    for (int i = 0; i < tamanhocol; i++){
        vdespc[i] = maiorq - qnumero[i];
        vdespcaux[i] = maiorq - qnumero[i];
    } 

    // Impressao do cabecalho.
    for (int i = 0; i < maiorq; i++){ 
        //Conta a quantidade de espacos necessaria.
        for (int i = 0; i < numspc; i++){
            printf(" ");
        }
        
        for (int j = 0; j < tamanhocol; j++){
            if(vdespc[j] > 0){
                vdespc[j]--;
                vdespcaux[j]--;
                printf("   ");
            }

            else if(test > j) {
                printf(" %-3d", matcol[j][vdespcaux[j]]);//tinha i ali. pensar sobre essa variaçao.
                vdespcaux[j]++;
                test = -1;
            }

            else if(matcol[j][vdespcaux[j]] >= 10) {
                printf("%d", matcol[j][vdespcaux[j]]);//tinha i ali. pensar sobre essa variaçao.
                vdespcaux[j]++;
                test = j + 100;
            }
            
            else{
                printf("%d  ", matcol[j][vdespcaux[j]]);
                vdespcaux[j]++;
            }
        }
        printf("\n");
    }
    for (int i = 0; i < numspc; i++){
        printf(" ");
    }
    for (int i = 0; i < tamanhocol; i++){
        printf("%c  ", 'A' + i);
    }
    printf("\n");
    free(vdespc);
    free(vdespcaux);
}

void imprimeCabecalholin(int *qnumero, int tamanholin, int **matlin, int maiorq, int maiornum, char **matc,int tamcol){   
    int qtespaco;
    for (int i = 0; i < tamanholin; i++){
        qtespaco = maiorq - qnumero[i];
        
        //Faz espaco especifico para quando o jogo tiver um valor maior do que 10.
        if(maiornum >= 10){
            for (int k = 0; k < 3*qtespaco; k++){
                printf(" ");
            }
            for (int j = 0; j < qnumero[i]; j++){
                printf("%2d ", matlin[i][j]);
            }
            printf(" %c ", 'A'+i);
            
            //Imprime a matriz do entrada.
            for (int l = 0; l < tamcol; l++){
                printf(" %c ", matc[i][l]);
            }
            printf("\n");
        }
        else{
            for (int k = 0; k < 2*qtespaco; k++){
                printf(" ");
            }
            for (int j = 0; j < qnumero[i]; j++){
                printf("%d ", matlin[i][j]);
            }
            printf(" %c ", 'A'+i);
            for (int l = 0; l < tamcol; l++){
                printf(" %c ", matc[i][l]);
            }
            printf("\n");
        }
    }
}

int valida(char corlin, char corcol, int tamlin, int tamcol){
    char maiorlin = 'A' + tamlin, maiorcol = 'A' + tamcol;
    //int cont;
     
    // Verificando se foi adicionada alguma letra que nao esta presente no nonograma.
    if (corlin >= maiorlin || corcol >= maiorcol){
        printf("\n\nArgumento invalido!\nLetra ou sequencia de letras nao compativeis com o jogo!\n\n");
        return 0;
    }
    
    // Verificando se algum caractere invalido foi digitado.
    if(corlin < 65 || corlin > 90 || corcol < 65 || corcol > 90){
        printf("\n\nArgumento invalido!\nPossivel carctere ou sequencia de caracteres imcompativeis!\n\n");
        return 0;
    }

    //AVISAR SE FOR COLOCAR MINUSCULA;
    //AVISAR SE O LUGAR QUE ELE FOR COLOCAR O X, POR EXEMPLO, JA TIVER O X.
    //AVISAR SE ELE COLOCAR SO UM ARGUMENTO, POR EXEMPLO.
    //O CARA TA CONSEGUINDO DIGITAR COISA DEPOIS DO COMANDO SEM DAR ERRO
    return 1;
}

void salvaNonograma(char nomearq[], int **lin, int **col, int tamlin, int tamcol, int *qtnumlin, int *qtnumcol, char **matc){
    FILE *salva = fopen(nomearq, "w");
    
    // Salva linha e coluna.
    fprintf(salva,"%d %d ", tamlin, tamcol);
    fprintf(salva, "\n");   

    // Salva o cabecalho das linhas.
    for(int i = 0; i < tamlin; i++){
        fprintf(salva,"%d ", qtnumlin[i]);
        
        for (int j = 0; j < qtnumlin[i]; j++){           
            fprintf(salva, "%d ", lin[i][j]);
        }
        fprintf(salva, "\n");   
    }

    // Salva o cabecalho das colunas.
    for(int i = 0; i < tamcol; i++){
        fprintf(salva, "%d ",qtnumcol[i]);
    
        for (int j = 0; j < qtnumcol[i]; j++){
            fprintf(salva, "%d ", col[i][j]);
        }   
        fprintf(salva, "\n");   
    }

    // Salva a matriz de char editada pelo usuario.
    for (int i = 0; i < tamlin; i++){
        for (int j = 0; j < tamcol; j++){
            
            __fpurge(stdin);
            fprintf(salva, "%c ", matc[i][j]);
        }
        fprintf(salva, "\n");   
    }   
    fclose(salva);
}

int main(int argc, char **argv){
    // Abrindo o arquivo.
    FILE *entrada = fopen(argv[1],"r");
    
    // Armazena a entrada da matriz.
    int tamlin, tamcol;
    fscanf(entrada,"%d %d", &tamlin, &tamcol);
    
    int **lin, *qtnumlin; //Os qts vao funcionar como um regulador dos prints. Devo olhar qual é o maior para saber os espacos
    
    qtnumlin = malloc(tamlin * sizeof(int));
    lin = malloc(tamlin * sizeof(int*));
    
    // Armazena os valores da matriz da linha (lin), juntamente com a quantidade de valores por linha(qtnumlin). 
    for(int i = 0; i < tamlin; i++){
        fscanf(entrada,"%d",&qtnumlin[i]);
        lin[i] = malloc(qtnumlin[i] * sizeof(int)); //???
        for (int j = 0; j < qtnumlin[i]; j++){           
            fscanf(entrada, "%d", &lin[i][j]);
        }   
    }        
    
    
    // Verifica qual valor de qnumero e maior(o espacamento vai ser definido baseado nesse valor).
    int maiorqlin = qtnumlin[0];
    for (int i = 0; i < tamlin; i++){
        if (qtnumlin[i] > maiorqlin)
            maiorqlin = qtnumlin[i];
    }
    
    
    // Verifica qual o maior valor da matriz para conferir se é maior que 10, e quantos sao.
    
    int maiornum = lin[0][0], cont10 = 0;
    for (int i = 0; i < tamlin; i++){ 
        for (int j = 0; j < qtnumlin[i]; j++){
            if(lin[i][j] > maiornum)
                maiornum = lin[i][j];
            if(lin[i][j] >= 10)
                cont10++;  
        }
    }   
    
    // Descobrindo a quantidade de espacoes (numspc) necessaria
    int numspc;
    if (cont10 > 0)
        numspc = (maiorqlin + 1)*3 + 1;
    else
        numspc = (maiorqlin*3 + 1)+ 1;

    // Armazena os valores da matriz do cabecalho das colunas
    int  *qtnumcol;
    int **col;
    
    qtnumcol = malloc(tamcol * sizeof(int));
    col = malloc(tamcol * sizeof(int*));
    
    for(int i = 0; i < tamcol; i++){
        fscanf(entrada, "%d",&qtnumcol[i]);
        col[i] = malloc(qtnumcol[i] * sizeof(int));
        for (int j = 0; j < qtnumcol[i]; j++){
            fscanf(entrada, "%d", &col[i][j]);
        }   
    }   
    // talvez eu tenha que perguntar antes dessa parte(na real é obvio, pq vou acessar o print em um forzao)
    //mas num geral acho q da pra fazer aqui em baixo msm
    
    // Armazena a matriz de caracteres (a que sera alterada).
    char **matc = malloc(tamlin * sizeof(char*)), rechar;
    for (int i = 0; i < tamlin; i++){
        matc[i] = malloc(tamcol * sizeof(char));
    }
    for (int i = 0; i < tamlin; i++){
        for (int j = 0; j < tamcol; j++){
            __fpurge(stdin);
            fscanf(entrada, " %c", &rechar);
            if(rechar == '\n' || rechar == ' '){
            j--;
            continue;
            }
            matc[i][j] = rechar;
        }
    }
    

    //talvez seja util retornar matrizes
    
    // Comecando o Jogo.
    printf("\nComandos e argumentos necessarios para jogar:\n");
    printf("\nComando   Argumento   Resultado");
    printf("\nx         AC          Preenche a célula da linha A e coluna C com um x.");
    printf("\n-         EC          Preenche a célula da linha E e coluna C com um -");
    printf("\n.         BA          Limpa a célula da linha B e coluna A.");
    printf("\nsalvar    out.txt     Salva o Nonograma tal como está no momento no arquivo “out.txt");
    printf("\nsair                  Encerra o programa (sem salvar as últimas alterações).\n");
    printf("\n\nBem vindo ao Nonograma! \n\n"); 
    imprimeCabecalhocol(qtnumcol, tamcol, col, numspc);
    imprimeCabecalholin(qtnumlin, tamlin, lin, maiorqlin, maiornum, matc, tamcol);

    // Looping de comandos.    OS QUE ESTAO BARRADOS NAO PRECISA DE USAR!!!
    char comando[9], corlin, corcol, nomearq[250]; //o comando em si pode ter no maximo 8 caracteres
    int val; // Esta variavel serve para retornar a validacao.
    do{
        printf("\n\nDigite um comando: ");
        
        __fpurge(stdin);
        scanf(" %8s", comando); //quando passa do valor limite ele fica bugado. se eu aumentar o tamanho funciona, mas conferir.
        //da pra deixar ele um pouco maior, e conferir se ele passa de oito. Dessa forma, da ate pra aparecer uma mensagem
        //especifica.
        
        // Validando o comando.
        if(strcmp(comando,"x") != 0 && strcmp(comando,"-") != 0 && strcmp(comando,".") != 0 && 
            strcmp(comando,"salvar") != 0 && strcmp(comando,"sair") != 0){
            //talvez esse if incubra todo comando
            printf("\n\nComando invalido!\n\n");
            imprimeCabecalhocol(qtnumcol, tamcol, col, numspc);
            imprimeCabecalholin(qtnumlin, tamlin, lin, maiorqlin, maiornum, matc, tamcol);
            continue;
        }

        // Substituindo por "x".
        if(strcmp(comando,"x") == 0){
            //verifica se tem espaco depois do c corlin. Se tiver ja tem que aparecer que é inválido.
           // __fpurge(stdin); 
            scanf(" %c %c", &corlin, &corcol);
           
            printf("\n\n");
            // Validacao dos argumentos.
            val = valida(corlin, corcol, tamlin, tamcol);
            if(val == 0){
                imprimeCabecalhocol(qtnumcol, tamcol, col, numspc);
                imprimeCabecalholin(qtnumlin, tamlin, lin, maiorqlin, maiornum, matc, tamcol);
                //aparecer a menssagem do erro aqui (depois do print) baseado no return da funcao!
                continue;
            }
            matc[corlin - 'A'][corcol - 'A'] = 'x';
            imprimeCabecalhocol(qtnumcol, tamcol, col, numspc);
            imprimeCabecalholin(qtnumlin, tamlin, lin, maiorqlin, maiornum, matc, tamcol);
            continue;
        }

        // Substituindo por "-".
        if(strcmp(comando,"-") == 0){
            //__fpurge(stdin);
            scanf(" %c %c", &corlin, &corcol);
            printf("\n\n");
            val = valida(corlin, corcol, tamlin, tamcol);
            if(val == 0){
                imprimeCabecalhocol(qtnumcol, tamcol, col, numspc);
                imprimeCabecalholin(qtnumlin, tamlin, lin, maiorqlin, maiornum, matc, tamcol);
                continue;
            }
            matc[corlin - 'A'][corcol - 'A'] = '-';
            imprimeCabecalhocol(qtnumcol, tamcol, col, numspc);
            imprimeCabecalholin(qtnumlin, tamlin, lin, maiorqlin, maiornum, matc, tamcol);
            continue;
        }
        
        // Substituindo por ".".
        if(strcmp(comando,".") == 0){
            //__fpurge(stdin);
            scanf(" %c %c", &corlin, &corcol);
            printf("\n\n");
            val = valida(corlin, corcol, tamlin, tamcol);
            if(val == 0){
                imprimeCabecalhocol(qtnumcol, tamcol, col, numspc);
                imprimeCabecalholin(qtnumlin, tamlin, lin, maiorqlin, maiornum, matc, tamcol);
                continue;
            }
            matc[corlin - 'A'][corcol - 'A'] = '.';
            imprimeCabecalhocol(qtnumcol, tamcol, col, numspc);
            imprimeCabecalholin(qtnumlin, tamlin, lin, maiorqlin, maiornum, matc, tamcol);
            continue;
        }

        // Comando para salvar o jogo.
        if(strcmp(comando,"salvar") == 0){
            //__fpurge(stdin);
            scanf(" %s", nomearq);
            salvaNonograma(nomearq, lin, col, tamlin, tamcol, qtnumlin, qtnumcol, matc);
            printf("Nonograma salvo com sucesso! ");
            continue;
        }
        
        // Comando para sair do jogo.
        if(strcmp(comando,"sair") == 0){
            break;        
        }

    } while (1);
    

    // Fechando arquivo de entrada.
    fclose(entrada);

    // Limpando memoria de todas as variaveis alocadas
    for (int i = 0; i < tamcol; i++){
        free(matc[i]);
    }
    free(matc);
    
    for (int i = 0; i < tamlin; i++){
        free(lin[i]);
    }
    free(lin);
    
    free(qtnumlin);
    free(qtnumcol);
    
    for (int i = 0; i < tamcol; i++){
        free(col[i]);
    }
    free(col);
    
    return 0;
}
