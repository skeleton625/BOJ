#include <iostream>
using namespace std;


unsigned long long a, b, t, m, n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b;
	m = b; n = a;
	while (n) {
		t = m % n;
		m = n; n = t;
	}
	cout << (a * b) / m;
	return 0;
}