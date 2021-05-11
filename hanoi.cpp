#include <iostream>

using namespace std;

void hanoi(int n, char domysln, char pomocn, char cel) { 
	if(n == 1)
	{
		cout << "Przenies dysk " << n<< " z " << domysln << " do " << cel << endl;
	}
	
	hanoi(n-1,domysln,cel,pomocn);
	cout << "Przenies dysk " << n << " z " << domysln << " do " << cel << endl;
	hanoi(n-1,pomocn,domysln,cel);
}


int main() { 
	
	int n;
	cout << "Wpisz liczbe dyskow: ";	cin >> n;

	hanoi(n,'A','B','C');
}
