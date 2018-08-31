#include <iostream>
using namespace std;

int t, a1 = 1, b1 = 0, at, bt;
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		at = a1; bt = b1;
		a1 = bt; b1 += at;
	}
	cout << a1 << " " << b1;
	return 0;
}