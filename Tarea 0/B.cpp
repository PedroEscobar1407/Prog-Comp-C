#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num_casos;
    cin >> num_casos;

    vector<string> grilla(8);
    for (int i = 0; i < num_casos; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> grilla[j];
        }
        for (int columna = 0; columna < 8; columna++) {
            string palabra = "";
            for (int fila = 0; fila < 8; fila++) {
                if (grilla[fila][columna] != '.') {
                    palabra += grilla[fila][columna];
                }
            }

            if (palabra != "") {
                cout << palabra << endl;
            }
        }
    }

    return 0;
}