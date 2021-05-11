#include <iostream>

using namespace std;

float W(int n, float A[], float x) {
	if (n == 0) return A[n];
	else return W(n-1, A, x)*x + A[n];
}

int main() {
	int n = 3;
	float A[] = {2, 3, 5, 10};
	float x = 1;
	cout << W(n, A, x) << endl;
}
