#ifndef CACHE_h
#define CACHE_h

#include <iostream>

typedef struct Bloco{
    int posicao;
    int valor;
}Bloco;

class CacheL1{
    protected:
        Bloco L1[4];
    public:
        CacheL1();
        int getL1Valor(int indice);
        int getL1Posicao(int indice);
        void setL1Valor(int indice, int valor);
        void setL1Posicao(int indice, int posicao);


};

class CacheL2{
    private:
        Bloco L2[8];
    public:
        CacheL2();
        int getL2Valor(int indice);
        int getL2Posicao(int indice);
        void setL2Valor(int indice, int valor);
        void setL2Posicao(int indice, int posicao);

};

#endif //CACHE_H