#include <iostream>
using namespace std;
int ile(int n, int m) {
		if ((m == 1) || (m == n)) return 1;
		else return ile(n-1, m-1)+ile(n-1,m);
}

int main() {
	int m{2}, n{4};
	cout << ile(m, n) << endl;	
}
