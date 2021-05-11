#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
void losuj ( int T[], int &n)
{
    srand(time(NULL));
    cout<<"podaj ilosc elementow ";     cin>>n;
    for (int i=0; i<n; i++)
            T[i]=rand()%(n+1);
}

void pokaz (int T[], int n)
{
    cout<<endl;
    for (int i=0; i<n; i++)
         cout<<"T=["<<i<<"] = "<<T[i]<<endl;
}


void sortuj(int T[], int n)
{
sort(T,T+n);
}

/* Napisz procedure scal tablice A i B do tablicy C  */
void scal(int A[], int B[], int C[], int dA, int dB)
{
    int w_1, w_2, w_3 =0;
while (w_1<dA && w_2<dB){
    if(A[w_1] < B[w_2]){
        C[w_3] = A[w_1];
        w_1++;}
        else {C[w_3] = B[w_2];
        w_2 ++;}
        w_3 ++;
    }
    if(w_1>=dA){
        for(int i = w_2; i<dB; i++){
            C[w_3] = B[i];
            w_3++;
        }
        
    }
    else
    for(int i=w_1; i<dA; i++){
        C[w_3] = A[i];
        w_3++;
    }
}



int main()
{
    int dA, dB, dC;
    int A[100], B[100], C[200];

    losuj (A, dA);
    pokaz (A, dA);
    sortuj(A, dA);

    losuj (B, dB);
    pokaz (B, dB);
    sortuj(B, dB);

    scal(A,B, C, dA, dB);

    dC= dA+dB;
    cout<<"---------------"<<endl;
    pokaz (C, dC);


  return 0;
}
