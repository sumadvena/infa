#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

bool czy_pierwsza(int n) {
    if (n < 2)
        return false;  //gdy liczba jest mniejsza niż 2 to nie jest pierwszą

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;  //gdy znajdziemy dzielnik, to dana liczba nie jest pierwsza
    return true;
}

int suma_cyfr(int x) {
    int suma = 0;
    while (x != 0) {
        suma += x % 10;
        x = x / 10;
    }
    return suma;
}

bool czy_prostokatny(int a, int b, int c) {
    if (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2) || pow(b, 2) + pow(c, 2) == pow(a, 2))
        return true;
    else
        return false;
}

// void szszJ(int a, int b, int c) {
//     cout << "66.1: \n";
//     ifstream we("trojki.txt");
//     while (!we.eof()) {
//         we >> a >> b >> c;  //wczytanie trzech kolejnych liczb oddzielonych spacją
//         if (suma_cyfr(a) + suma_cyfr(b) == c)
//             cout << a << " " << b << " " << c << endl;
//     }
//     we.close();
// }

// void szszD(int a, int b, int c) {
//     cout << "66.2: \n";
//     if (a * b == c && czy_pierwsza(a) && czy_pierwsza(b))
//         cout << a << " " << b << " " << c << endl;
// }

void szszT(int a, int b, int c) {
    int A, B, C;
    cout << "66.3: \n";
    ifstream we("trojki.txt");
    we >> a >> b >> c;
    while (!we.eof()) {
        we >> A >> B >> C;
        if (czy_prostokatny(a, b, c) && czy_prostokatny(A, B, C)) {
            cout << a << " " << b << " " << c << endl;
            cout << A << " " << B << " " << C << endl;
        }
        A = a;
        B = b;
        C = c;
    }
    we.close();
}

int main() {
    ifstream we("trojki.txt");
    if (!we) {
        cout << "Brak pliku\n";
        return 1;
    }
    int a, b, c;
    // szszJ(a, b, c);
    // szszD(a, b, c);
    szszT(a, b, c);

    we.close();
}