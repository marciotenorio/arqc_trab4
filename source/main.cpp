#include "paineis.h"
using namespace std;

int num_cores = 0;

int memoria_principal[32];

int main(){
    PainelInicial(num_cores, memoria_principal);

    Core *cores = new Core[num_cores];
    CacheL1 *cacheL1 = new CacheL1[num_cores];
    CacheL2 *cacheL2 = new CacheL2[num_cores/2];

    PainelTarefas(memoria_principal, cores, cacheL1, cacheL2, num_cores);
    


    return 0;
}