#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void losuj(int T[], int &n)
{
  srand(time(NULL));
  cout << "podaj n ";
  cin >> n;
  for (int i = 0; i < n; i++)
    T[i] = rand() % (n + 1);
}
void pokaz(int T[], int n)
{
  cout << endl;
  for (int i = 0; i < n; i++)
    cout << "T=[" << i << "] = " << T[i] << endl;
}

void scal(int T[], int lewy, int prawy)
{
  int w_l, w_p, w_r, sr;            // inkesl lewy - w_l ...
  int const MAX = prawy - lewy + 1; // rozmiar tablicy pomocniczej -> pom

  sr = (lewy + prawy) / 2; // wyznacz srodek tablicy
  w_l = lewy;              // ustaw wskaznik lewego podzbioru
  w_p = sr + 1;            // ustaw wskaznik prawego podzbioru
  w_r = 0;                 // wskaznik zbioru pomocniczego -> pom

  //Krok 1                              // Przygotowanie tablicy pom
  int pom[MAX];

  // Krok 2
  while (w_l <= sr && w_p <= prawy) // dopoki jeden ze zbiorow nie jest pusty r�b
  {
    if (T[w_l] < T[w_p])
    {
      pom[w_r] = T[w_l];
      w_l++;
    } // mniejszy z "czala" tablicy T umiesc w tablicy pom
    else
    {
      pom[w_r] = T[w_p];
      w_p++;
    }
    w_r++; // zwieksz wskaznik roboczy
  }
  // Kok 3
  if (w_p > prawy) // sprawdz ktory podzbior sie skonczyl
    for (int i = sr; i >= w_l; i--)
    {
      T[lewy] = pom[i]; //przenoszenie na koniec tablicy T
      lewy++;
    }

  // Krok 4                   // przepisanie z pom na pocz�tek T
}

void sortuj(int T[], int lewy, int prawy)
// dzieli na coraz mniejsze podzbiory az do 1 elementowych potem je scala
{
  if (lewy < prawy)
  {
    int srodek = (lewy + prawy) / 2;
    sortuj(T, lewy, srodek);
    sortuj(T, srodek + 1, prawy);
    scal(T, lewy, prawy);
  }
}

//------------------------
int main()
{
  int n = 5;
  int T[100] = {1, 8, 9, 2, 5};
  int lewy, prawy;
  losuj(T, n);
  pokaz(T, n);

  sortuj(T, 0, n - 1);

  pokaz(T, n);

  return 0;
}
