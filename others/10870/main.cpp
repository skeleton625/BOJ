#include <iostream>
using namespace std;

int n, t, a = 0, b = 1;
int main() {
	cin >> n;
	if (n == 0) cout << 0;
	else if (n == 1) cout << 1;
	else {
		for (int i = 1; i < n; i++) {
			t = a;
			a = b;
			b = b + t;
		}
		cout << b;
	}
	return 0;
}