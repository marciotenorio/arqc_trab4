#include <iostream>
#include <vector>
using namespace std;

void teste(int *vetor, int n){
    for(int i=0; i<n; i++){
        vetor[i] = i+10;
        cout << vetor[i] << "\n";
    }
}

void teste2(vector<int> v){
    for(int i = 0 ; i < 10; i++){
        v.at(i) = i+10;
    }
    for(int i = 0 ; i < (int) v.size() ; i++){
        cout << v.at(i) << endl;
    }
}

int main(){
    vector<int> vetor(10);
    teste2(vetor);
    //int v[10];
    //teste(v, 10);
}