#include <iostream>
#include <algorithm>
using namespace std;

int t, l, c, tmp;
int *p;

int main() {
	cin >> t;
	cin.tie(0);
	ios::sync_with_stdio(false);
	while (t--) {
		cin >> l >> c;
		p = new int[c];
		for (int i = 0; i < c; i++)
			cin >> p[i];
		sort(p, p + c);
		tmp = p[0];
		for (int i = 1; i < c; i++) {
			if (l / 2 > p[i]) {
				if(tmp < p[i]) tmp = p[i];
			}
			else {
				if (tmp < l - p[i]) tmp = l - p[i];
			}
		}
		cout << tmp << ' ';
		if (l-p[0] > p[c-1]) cout << l-p[0] << '\n';
		else cout << p[c - 1] << '\n';
		delete p;
	}
	return 0;
}