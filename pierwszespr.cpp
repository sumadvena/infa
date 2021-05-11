// 2D/2 Mateusz Władyka
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// uzywajac vectora sprawdza liczbe dzielnikow danej liczby, wypisujac je do pliku
void liczonko(int zakres_beg, int zakres_end) {
    ofstream primes;
    primes.open("wynik.txt");
    vector<int> dzielniki;
    int liczba = zakres_beg;
    int licznik_cyklu = 0;

    while (zakres_beg <= zakres_end) {
        liczba = zakres_beg;

        for (int i = 1; i <= liczba; i++) {
            if (liczba % i == 0) {
                dzielniki.push_back(i);
            }
        }

        if (dzielniki.size() == 2 && licznik_cyklu == 0) {
            primes << liczba << '\t';
            licznik_cyklu++;
        } else if (dzielniki.size() == 2 && licznik_cyklu == 1) {
            primes << liczba << '\n';
            licznik_cyklu--;
        }

        dzielniki.clear();
        zakres_beg++;
    }
    primes.close();
}

// losuje zakres a nastepnie wywoluje procedure
int main() {
    int zakres_beg, zakres_end;
    srand(time(NULL));
    zakres_beg = rand() % 50 + 50;
    zakres_end += zakres_beg + 1000;
    liczonko(zakres_beg, zakres_end);
}