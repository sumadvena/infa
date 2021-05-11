#include <iostream>
#include <fstream>              // zadeklaruj biblioteke fstream
#include <string>
using namespace std;
int main ()
{
 ifstream fin("dane.txt");     //utworz obiekt klasy ifstream - do plik do odczytu
 if (!fin) cout<<"plik nie zostal znaleziony"<<endl;   // Testowanie otwarcia
 else  {
 ofstream fout("wyniki1.txt");  //utworz obiekt klasy ofstream - do plik do zapisu
 string s;
 while (!fin.eof())            // dopóki nie ma konca zbioru wejsciowego rób:
  {
    fin>>s;                    // czytaj do s z pliku wejsciowego
    if (s.size()%2==0) fout<<s<<"\n";
                               //uzupelnij aby zobaczyc na ekranie co wpisujemy do pliku
  }
 fin.close();
                // zamknij plik wejsciowy
 fout.close();
 }               // zamknij plik wyjsciowy

 return 0;
}
