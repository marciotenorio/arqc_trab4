#include "cache.h"

CacheL1::CacheL1(){
    for(int i = 0; i<4; i++){
        L1[i].posicao = -1;
        L1[i].valor = -1;
    }
}

int CacheL1::getL1Valor(int indice){
    return L1[indice].valor;
}

int CacheL1::getL1Posicao(int indice){
    return L1[indice].posicao;
}

void CacheL1::setL1Valor(int indice, int valor){
    L1[indice].valor = valor;
}

void CacheL1::setL1Posicao(int indice, int posicao){
    L1[indice].posicao = posicao;
}

/*
METODOS DA CLASSE CACHE L2
*/

CacheL2::CacheL2(){
    for(int i = 0; i<8; i++){
        L2[i].posicao = -1;
        L2[i].valor = -1;
    }
}

int CacheL2::getL2Valor(int indice){
    return L2[indice].valor;
}

int CacheL2::getL2Posicao(int indice){
    return L2[indice].posicao;
}

void CacheL2::setL2Valor(int indice, int valor){
    L2[indice].valor = valor;
}

void CacheL2::setL2Posicao(int indice, int posicao){
    L2[indice].posicao = posicao;
}