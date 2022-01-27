#include <iostream>
#include <iomanip>
#include <vector>
#include <string>


using namespace std;
  
vector<string> dni = {"poniedzialek", "wtorek", "sroda", "czwartek", "piatek", "sobota", "niedziela"};


bool rok_przestepny(int rok) {
    if (rok <= 1582) {
        if (rok % 4 == 0) return true; // julianski
        else return false;
    } else {
        if ((rok % 4 == 0) && (rok % 400 == 0)) return true; //gregorianski
        else return false; 
    }
}

void liczenie(string& dzien, int rok) {\
    vector<int> daty_w_lutym;
    int d, m, r; //dzien, miesiac, rok
    string dz; // dzien tygodnia
    if(rok <= 1582) { // wystepowanie danych dni tygodnia w lutym w danym rok wg kalendarza julianskiego
        if (dzien == dni[0]) {  //poniedzialek
            d = 1;
            m = 10;
            r = 1582;
        } else if (dzien == dni[1]) {  //wtorek
            d = 2;
            m = 10;
            r = 1582;
        } else if (dzien == dni[2]) {  //sroda
            d = 3; 
            m = 10;
            r = 1582;
        } else if (dzien == dni[3]) {  //czwartek
            d = 4;
            m = 10;
            r = 1582;
        } else if (dzien == dni[4]) {  //piatek
            d = 30;
            m = 9;
            r = 1582;
        } else if (dzien == dni[5]) {  //sobota
            d = 29;
            m = 9;
            r = 1582;
        } else if (dzien == dni[6]) {  //niedziela
            d = 28;
            m = 9;
            r = 1582;
        }
        
        while (r <= rok) {
            if (d <= 7) {
                if (m = 1) {r--; m == 12;}
                    else m--;
                    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) d += 31;
                        else if (rok_przestepny(r) && m == 2) d += 28;
                        else if ((rok_przestepny(r) == false) && (m == 2)) d += 27; 
                        else d += 30;
                d -= 7;
            } else
                d -= 7;

            if ((r == rok) && (m == 2)) {
                daty_w_lutym.push_back(d);
            } else if ((r == rok) && (m == 1)) {
                for (int j = 0; j < daty_w_lutym.size(); j++ ) {
                    cout << setfill('0') << setw(2) << daty_w_lutym[j] << ".02." << rok << endl;
                }
            }
        }

    } else { // wystepowanie danych dni tygodnia w lutym w danym rok wg kalendarza julianskiego
        if (dzien == dni[4]) {  //piatek
            d = 15;
            m = 10;
            r = 1582;
        } else if (dzien == dni[5]) {  //sobota
            d = 16;
            m = 10;
            r = 1582;
        } else if (dzien == dni[6]) {  //niedziela
            d = 17;
            m = 10;
            r = 1582;
        } else if (dzien == dni[0]) {  //poniedzialek
            d = 18;
            m = 10;
            r = 1582;
        } else if (dzien == dni[1]) {  //wtorek
            d = 19;
            m = 10;
            r = 1582;
        } else if (dzien == dni[2]) {  //sroda
            d = 20;
            m = 10;
            r = 1582;
        } else if (dzien == dni[3]) {  //czwartek
            d = 21;
            m = 10;
            r = 1582;
        }

        while (r >= rok) {
            if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
                if(d >= 25) {
                    if(m == 12) {m = 1; r++;}
                        else m++;
                    d = d + 7 - 31;
                } else d += 7;
            } else if (m == 2 && rok_przestepny(r)) {
                if(d >= 22) {
                    m++;
                    d = d + 7 - 28;
                } else d += 7;
            } else if ((m == 2) && (rok_przestepny(r) == false)) {
                if(d >= 21) {
                    m++;
                    d = d + 7 - 27;
                } else d += 7;
            } else {
                if(d >= 24) {
                    m++;
                    d = d + 7 - 30;
                } else d += 7;
            }

            if ((r == rok) && (m == 2)) {
                daty_w_lutym.push_back(d);
            } else if ((r == rok) && (m == 3)) {
                for (int j = 0; j < daty_w_lutym.size(); j++ ) {
                    cout << setfill('0') << setw(2) << daty_w_lutym[j] << ".02." << rok << endl;
                }
            }
        }
    }
}

void podaj_dzien(string& dzien) { //cos mi gdzies ta funkcja nie dziala
    int znacznik = 0;
    cout << "Podaj dzień tygodnia: ";
    getline(cin, dzien);
    for (int i = 0; i < dni.size(); i++) {
        if (dni[i].compare(dzien) == 0){   
            znacznik++;
        } else continue;
    }
    if (znacznik = 0) {
        cout << "Podany dzień tygodnia jest w złej formie\n";
        podaj_dzien(dzien);
    }
}

void podaj_rok(int& rok) {  //sprawdza czy rok miesci sie w przedziale ustalonym w zadaniu
    cout << "Podaj rok: "; cin >> rok;
    if (rok < 1500 || rok > 2005) {
        cout << "Zła data. Powinno być od 1500 do 2005\n";
        podaj_rok(rok);
    }
}

int main() {
    string dzien;
    int rok;
    
    podaj_dzien(dzien);
    podaj_rok(rok);
    liczenie(dzien, rok);
}