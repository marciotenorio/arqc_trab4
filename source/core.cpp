#include "core.h"

Core::Core(){
}

int Core::LerDataL1(int posicao_mem, CacheL1 &L1, CacheL2 &L2, int *memoria_principal){
    if(posicao_mem == L1.getL1Posicao(posicao_mem%4)){//3 == (L1[3].posicao=-1)
        return L1.getL1Valor(posicao_mem%4);
    }else{
        LerDataL2(posicao_mem, L1, L2, memoria_principal);
        return L1.getL1Valor(posicao_mem%4);
    }
}

void Core::LerDataL2(int posicao_mem, CacheL1 &L1, CacheL2 &L2, int *memoria_principal){
    if(posicao_mem == L2.getL2Posicao(posicao_mem%8)){
        L1.setL1Posicao(posicao_mem%4, posicao_mem);
        L1.setL1Valor(posicao_mem%4, L2.getL2Valor(posicao_mem%8));
    }else{
        LerDataRAM(posicao_mem, L1, L2, memoria_principal);
        L1.setL1Posicao(posicao_mem%4, posicao_mem);
        L1.setL1Valor(posicao_mem%4, L2.getL2Valor(posicao_mem%8));
    }
}

void Core::LerDataRAM(int posicao_mem, CacheL1 &L1, CacheL2 &L2, int *memoria_principal){
    L2.setL2Posicao(posicao_mem%8, posicao_mem);
    L2.setL2Valor(posicao_mem%8, memoria_principal[posicao_mem]);
}
//WriteThrough(int novo_valor, int posicao_mem, CacheL1 &L1, CacheL2 &L2, int *memoria_principal);
