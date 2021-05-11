#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream we("dane.txt");
    ofstream wy("wyniki.txt");
    string T[1000];
    string s;
    int i = 0, licznik = 0;
    if (!we) {
        cout << "Brak pliku\n";
        return 1;
    }

    while (!we.eof()) {
        we >> s;
        licznik++;
        if (s.size() > 2) {
            T[i] = s;
            i++;
        }
    }
    sort(T, T + i);

    for (int j = 0; j < i; j++) {
        cout << T[j] << endl;
        wy << T[j] << endl;
    }
    wy << "odczytano " << licznik << endl;
    wy << "sortowano " << i << endl;

    wy.close();
    we.close();
}