#include <iostream>
#include <algorithm>
using namespace std;

int t, l, c, m, n, tmp;
int *p;

int main() {
	cin >> t;
	cin.tie(0);
	ios::sync_with_stdio(false);
	while (t--) {
		cin >> l >> c;
		p = new int[c];
		for (int i = 0; i < c; i++) {
			cin >> p[i];
			m = max( m, max(l - p[i], p[i]));
			n = max(n, min(p[i], l - p[i]));
		}
		cout << n << ' ' << m << '\n';
		delete p;
		m = 0; n = 0;
	}
	return 0;
}