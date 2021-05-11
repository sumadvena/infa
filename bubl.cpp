#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

void losuj(int T[], int&n) {
	srand(time(NULL));
	cout << "podaj n";
	cin >> n;
	for(int i=0; i<n; i++)
	T[i] = rand()%(n+1);
}

void pokaz(int T[], int n) {
	for(int i=0; i<n; i++)
		cout <<"T[" << i <<"]=" << T[i] << endl;
}


void zamien(int &a, int &b) { // procedura zamiany miejscami a i b   
	int r;
	r = b;
	b = a;
	a = r;
}

int min_poz(int p, int k, int T[]) { // funkcja zwraca pozycje elementu minimalnego w podtablicy T[p...k]  
  
	int min = T[p];

	int poz = p; // p -> jak poczatek 
	
	for(int i = p+1; i < k; i++) {
		if (T[i] < min)   {min = T[i];  poz = i;} // umiesz znalez minimum zbioru tym razem zwroc jego pozycje
    	}
    	return poz;
}

void sort_wyb(int T[], int n)  // procedura sortowania prze wybor
{
    int k;
    for(int i = 0; i < n-1; i++) {
      	k = min_poz(i,n,T);    //znajdz index pokazujacy element min w tablicy  T[i...n] i podstaw pod k
      	zamien(T[i], T[k]);   //zamin mjscami elementy 
    }
}

int main() {
    int T[100];
    int n;
    losuj(T,n);  // masz to w swoim "dorobku"
    pokaz(T,n);  //jw
      
    sort_wyb(T,n);

    pokaz(T,n);
    return 0;
}
