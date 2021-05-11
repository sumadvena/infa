#include <iostream>

using namespace std;

int potega(int x, int n) {
	if (x == 0) return 1;
	int tmp = potega(x,n/2);
	if (x % 2 == 0) return tmp*tmp;
	else return tmp*tmp*x;
}

int main() {
	cout << potega(2,10) << endl;
	
}
