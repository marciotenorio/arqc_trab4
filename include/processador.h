#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include <iostream>
#include <vector>
using std::vector;

#include "core.h"
using namespace std;

class Processador {
    protected:
        Core core[2];
        Bloco cacheL2[8];

    public:
        Core getCore(int core_escolhido);
    
};
#endif //PROCESSADOR_H