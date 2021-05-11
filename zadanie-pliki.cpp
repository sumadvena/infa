#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;

fstream plik("dane.txt");
vector<int> v;
int n = rand()%50;

void czytaj() {
	for(int i = 0; i < n; i++)
		v.push_back(plik);
		plik >> v.push_back() << "\n";
}

double srednia() {
	int suma;
	for_each(v.begin(), v.end(), [&] (int k) {suma += k;});
	return suma/v.size();

}

double odchylenie_standardowe() {
	int suma = 0;
	for (int i = 0; i < n; i++)

	return sqrt(suma/(n-1));
}


int main() {
	
	srand(time(NULL));
	
	cout << "Wylosowano " << n << " liczb\n";
	
	for(int i = 0; i < n; i++)
		plik << (1 + rand()%20) << "\n";
	czytaj();
	cout << "Średnia wynosi: " << srednia() << "\n";
	cout << "Odchylenie standardowe wynosi: " << odchylenie_standardowe() << "\n";


	plik.close();
}
