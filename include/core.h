#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>
using std::vector;
#include <map>
using std::map;

#include "cache.h"


class Core{
    protected:
        int EnderecoAcesso;
    public:
        Core();//construtor padrão
        int LerDataL1(int posicao_mem, CacheL1 &L1, CacheL2 &L2, int *memoria_principal);
        void LerDataL2(int posicao_mem, CacheL1 &L1, CacheL2 &L2, int *memoria_principal);
        void LerDataRAM(int posicao_mem, CacheL1 &L1, CacheL2 &L2, int *memoria_principal);

        //void WriteThrough(int novo_valor, int posicao_mem, CacheL1 &L1, CacheL2 &L2, int *memoria_principal);
        //void EditarDataL2(int posicao_mem, CacheL1 &L1, CacheL2 &L2, int *memoria_principal);
        //void EditarDataRAM(int posicao_mem, CacheL1 &L1, CacheL2 &L2, int *memoria_principal);
};

#endif //CORE_H
