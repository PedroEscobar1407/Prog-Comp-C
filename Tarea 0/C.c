#include <iostream>
#include <vector>

using namespace std;

int main() {
    string variables;
    cin >> variables;
    int largo = variables.size();
    char comparador = 'a';
    for(int i=0; i < largo; i++){
        if ( comparador < variables[i]){
            cout << "NO" << endl;
            return 0;
        }
        if (comparador == variables[i]){
            comparador++;
        }
    }
    
    cout << "YES" << endl;
    return 0;
}