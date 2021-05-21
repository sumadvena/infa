#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int czt_j() {
    int zera{0}, jedynki{0}, licznik{0};
    string s;
    ifstream we("liczby.txt");
    while (!we.eof()) {
        we >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                zera++;
            else
                jedynki++;
        }
        if (zera > jedynki) licznik++;
    }
    return licznik;
}

void czt_d() {
    int licznikdwa{0}, licznikosiem{0};
    string s;
    ifstream we("liczby.txt");
    while (!we.eof()) {
        we >> s;
        if (s[s.size() - 1] == '1')
            continue;
        else if (s[s.size() - 1] == '0')
            licznikdwa++;
        else if (s[s.size() - 4] == '1')
            licznikosiem++;
    }
    cout << "Liczb podzielnych przez 2 jest: " << licznikdwa << ", a podzielnych przez 8: " << licznikosiem << endl;
}

void wypiszzwektora(vector<int> w) {
    for (int i = 0; i < w.size(); i++) cout << w[i] << " ";
}

void czt_t() {
    vector<string> T;
    vector<int> w_najm, w_najw;
    string s;
    ifstream we("liczby.txt");
    while (!we.eof()) {
        we >> s;
        for (int i = 0; i < 255; i++) {
            s = '0' + s;
        }
        T.push_back(s);
    }

    auto najw = max_element(T.begin(), T.end());
    auto najm = min_element(T.begin(), T.end());

    for (int i = 0; i < T.size(); i++) {
        if (T[i] == *najw) {
            w_najw.push_back(i);
        } else if (T[i] == *najm) {
            w_najm.push_back(i);
        }
    }
    cout << "Najmniejsza liczba znajduje się w wierszach: ";
    wypiszzwektora(w_najm);
    cout << ", a największa liczba znajduje się w wierszach: ";
    wypiszzwektora(w_najw);
    cout << "\n";
}

int main() {
    cout << "Liczba zer jest większa od liczby jedynek dla " << czt_j() << " liczb\n";
    czt_d();
    czt_t();
}
