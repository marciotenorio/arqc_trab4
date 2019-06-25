#ifndef PAINEIS_H
#define PAINEIS_H

#include <iostream>
#include "core.h"
//#include "variaveis.h"
using namespace std;

void PainelInicial(int &num_cores, int *memoria_principal);
void PainelTarefas(int *memoria_principal, Core *core, CacheL1 *cacheL1, CacheL2 *cacheL2, int num_cores);
int PainelSelecao(int num_cores);
void PainelLeitura(int *memoria_principal, int core_escolhido, Core core, CacheL1 *cacheL1, CacheL2 *cacheL2, int num_cores);
void PainelImprimir(int *memoria_principal, CacheL1 *cacheL1, CacheL2 *cacheL2, int num_cores);
void PainelEscrita(int *memoria_principal, int core_escolhido, Core core, CacheL1 *cacheL1, CacheL2 *cacheL2, int num_cores);
void WriteThrough(int novo_valor, int num_cores, int core_escolhido, int posicao_mem, CacheL1 &L1, CacheL2 &L2, int *memoria_principal);


#endif //PAINEIS_H