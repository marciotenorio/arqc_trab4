#include "paineis.h"

void PainelInicial(int &num_cores, int *memoria_principal){
    int opcao;
    do{ 
        system( "clear" );
        cout << "Simulador de hierarquia de memória\n" << endl;
        if(num_cores%2 != 0){
            cout << "Quantidade inválida! Digite um múltiplo de 2\n\n";
        }
        cout << "Digite a quantidade de cores que o sistema terá: ";
        cin >> num_cores;

        if(num_cores%2 == 0){
            system( "clear" );
            cout << "Simulador de hierarquia de memória\n" << endl;
            cout << "Foram criados " << num_cores/2 << " Processador[es] dual core!\n" << endl;
            cout << "Deseja prosseguir?\n\n\t1. SIM\n\t2. NAO\n";
            cout << "\n Digite sua opção: ";
            cin >> opcao;
        }
        
    }while(num_cores%2 != 0 || opcao != 1 );
    for(int i = 0; i<32; i++)
        memoria_principal[i] = i+100;

}

void PainelTarefas(int *memoria_principal, Core *core, CacheL1 *cacheL1, CacheL2 *cacheL2, int num_cores){
    int opcao = 1;
    int core_escolhido = 0;
    do{
        do{
            system( "clear" );
            cout << "Simulador de hierarquia de memória\n" << endl;
            if(opcao < 0 || opcao > 2 ){
                cout << "Opção inválida! Tente novamente!\n\n";
            }
            cout << "Escolha a tarefa desejada:\n\n";
            cout << "\t1. LER\n\t2. ESCREVER\n\n\t0. SAIR\n\n";
            cout << "Selecione uma opção: ";
            cin >> opcao;
        }while(opcao < 0 || opcao > 2);

        if(opcao == 1){
            //fazer operações de leitura
            core_escolhido = PainelSelecao(num_cores);
            PainelLeitura(memoria_principal, core_escolhido, core[core_escolhido], cacheL1, cacheL2, num_cores);
            //cout << memoria_principal[0];
            //int teste;
            //cin >> teste;
        }else if(opcao == 2){
            core_escolhido = PainelSelecao(num_cores);
            PainelEscrita(memoria_principal, core_escolhido, core[core_escolhido], cacheL1, cacheL2, num_cores);
            //MÁRCIO TENÓRIO
            //fazer operações de escrita
            //int core_escolhido = PainelSelecao(num_cores);
        }

    }while(opcao !=0);

}

int PainelSelecao(int num_cores){
    int selecao_core = 1;
    do{
        system( "clear" );
        cout << "Simulador de hierarquia de memória\n" << endl;
        if(selecao_core < 0 || selecao_core >= num_cores){
            cout << "Core inválido! Tente novamente\n" << endl;
        }
        cout << "Qual core deseja utilizar: ";
        cin >> selecao_core;
    }while(selecao_core < 0 || selecao_core >= num_cores);
    
    return selecao_core;
}

void PainelLeitura(int *memoria_principal, int core_escolhido, Core core, CacheL1 *cacheL1, CacheL2 *cacheL2, int num_cores){
    int posicao_mem;
    system( "clear" );
    cout << "Simulador de hierarquia de memória\n" << endl;
    cout << "Digite a posição de memória que deseja acessar: ";
    cin >> posicao_mem;
    int valor_lido;
    valor_lido = core.LerDataL1(posicao_mem, cacheL1[core_escolhido], cacheL2[core_escolhido/2], memoria_principal);
    cout << "\nPosição [" << posicao_mem << "] = " << valor_lido << endl;
    cout << "\nPressione ZERO [0] para continuar ";
    int pausa;
    do{
        cin >> pausa;
    }while(pausa != 0);
    
    PainelImprimir(memoria_principal, cacheL1, cacheL2, num_cores);

    cout << "\nPressione ZERO [0] para continuar ";
    do{
        cin >> pausa;
    }while(pausa != 0);
}
    
void PainelImprimir(int *memoria_principal, CacheL1 *cacheL1, CacheL2 *cacheL2, int num_cores){
    cout << "\nMEMORIA PRINCIPAL:";
    for(int i = 0; i<32; i++){
        cout << "\n [" << i << "] = " << memoria_principal[i]; 
    }
    for(int i=0; i<num_cores; i++){
        if(i%2 == 0){
            cout << "\n\nCACHE L2 [" << i/2 << "]:" << endl;
            for(int k=0; k<8; k++){
                cout << "[" << k << "] = " << cacheL2[i/2].getL2Posicao(k) << " | " <<cacheL2[i/2].getL2Valor(k) << endl;
            }
        }
        cout << "\n\n\tCACHE L1 [" << i << "]:" << endl;
        for(int j=0; j<4; j++){
            cout << "\t[" << j<< "] = " << cacheL1[i].getL1Posicao(j) << " | " <<cacheL1[i].getL1Valor(j) << endl;
        }
    }

}


void PainelEscrita(int *memoria_principal, int core_escolhido, Core core, CacheL1 *cacheL1, CacheL2 *cacheL2, int num_cores)
{
    int posicao_mem, novo_valor, pausa;

    system( "clear" );

    cout << "Simulador de hierarquia de memória\n" << endl;
    cout << "Digite a posição de memória que deseja editar: ";
        cin >> posicao_mem;
    cout << "Digite o novo valor: ";
        cin >> novo_valor;
    //int novo_valor, int posicao_mem, CacheL1 &L1, CacheL2 &L2, int *memoria_principal
    WriteThrough(novo_valor, num_cores, core_escolhido, posicao_mem, *cacheL1, *cacheL2, memoria_principal);

    cout << "\nPosição [" << posicao_mem << "] = " << novo_valor << endl;
    cout << "\nPressione ZERO [0] para continuar ";
    do{
        cin >> pausa;
    }while(pausa != 0);
    
    PainelImprimir(memoria_principal, cacheL1, cacheL2, num_cores);

    cout << "\nPressione ZERO [0] para continuar ";
    do{
        cin >> pausa;
    }while(pausa != 0);
}

void WriteThrough(int novo_valor, int num_cores, int core_escolhido, int posicao_mem, CacheL1 &L1, CacheL2 &L2, int *memoria_principal)
{
    //Dimensionando as posições
    int pos_L1, tam_L1, pos_L2, tam_L2;
    
    pos_L1 = ((core_escolhido + 1) * 4) - ((num_cores - core_escolhido) * 4);
    tam_L1 = num_cores * 4;
    pos_L2 = (((core_escolhido + 1)/2) * 8) - ((num_cores - core_escolhido) * 8);
    tam_L2 = (num_cores/2) * 8;

    memoria_principal[posicao_mem] = novo_valor;

    L1.setL1Posicao(pos_L1 % tam_L1, posicao_mem);
    L1.setL1Valor(pos_L1 % tam_L1, memoria_principal[posicao_mem]);
    //setL2Posicao(Posicao na cache, valor)1º |
    L2.setL2Posicao(pos_L2 % tam_L2, posicao_mem);
    //setL2Valor(posicao na chace, valor) | 2º
    L2.setL2Valor(pos_L2 % tam_L2, memoria_principal[posicao_mem]);


}