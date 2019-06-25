#ifndef VARIAVEIS_h
#define VARIAVEIS_h

#include <iostream>
#include <cstdlib>

/*
    AQUI ESTÃO AS VARIÁVEIS GLOBAIS

    A QUANTIDADE DE CORES É INICIADA ZERADA E ATUALIZADA DEPOIS PELO USUÁRIO

    A MEMÓRIA PRINCIPAL É CRIADA COM 100 POSIÇÕES 
*/
struct Bloco{
    int posicao;
    int valor;
}Bloco;

struct CacheL1{
    struct Bloco bloco[4];
}CacheL1;

struct CacheL2{
    struct Bloco bloco[8];
}CacheL2;

int num_cores = 0;

int memoria_principal[100];

#endif //VARIAVEIS_H
