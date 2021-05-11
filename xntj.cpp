#include <iostream>

using namespace std;

int potega(int x, int k) {
	if (k == 0) return 1;
	else return x*potega(x, k-1);
}

int main() {
	cout << potega(2, 10) << endl;
}
