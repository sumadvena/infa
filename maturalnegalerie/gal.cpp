// Zad 4 2 WSTEP
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ifstream we("galerie_p.txt");
    if (!we) {
        cout << "plik nie zostal znaleziony" << endl;
        return 0;
    }
    string kraj, miasto;
    int T[140];
    int P[70];
    int pow = 0;
    int liczniklokali = 0;
    int min = 1000000;
    string n_min = "";
    int max = 0;
    string n_max = "";
    while (!we.eof()) {
        we >> kraj;  //  if(kraj == "") continue;               // zabezpieczenie przed pustym wierszem
        we >> miasto;

        for (int i = 0; i < 140; i++) we >> T[i];  //tablica wymiarow
        for (int k = 0; k < 70; k++) {
            P[k] = T[k * 2] * T[2 * k + 1];
            pow += P[k];
            if (P[k] != 0) liczniklokali++;
        }
        if (pow < min) {
            min = pow;
            n_min = miasto;
        }
        if (pow > max) {
            max = pow;
            n_max = miasto;
        }
        cout << miasto << " " << pow << " " << liczniklokali << endl;

        // koniec danych z wiersza

        //co dalej?
    }
    we.close();
    cout << n_min << " " << min << endl;
    cout << n_max << " " << max << endl;

    cout << "\nKONIEC" << endl;
    return 0;
}