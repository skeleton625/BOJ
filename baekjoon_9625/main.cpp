#include <iostream>
using namespace std;

int t, a1 = 1, b1 = 0, a2 = 0, b2 = 1, tmp;
int main() {
	cin >> t;
	if (t == 1) cout << 0 << " " << 1;
	else {
		for (int i = 1; i < t; i++) {
			tmp = a2;
			a2 += a1; a1 = tmp;
			tmp = b2;
			b2 += b1; b1 = tmp;
		}
		cout << a2 << " " << b2;
	}
	return 0;
}