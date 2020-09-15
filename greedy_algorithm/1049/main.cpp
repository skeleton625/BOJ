#include <iostream>
#include <algorithm>
using namespace std;

int n, m, re;
int mc, nc, mmin=1000, nmin=1000;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> mc >> nc;
		mmin = min(mc, mmin);
		nmin = min(nc, nmin);

	}
	while (n) {
		if (n < 6) {
			re += min(nmin*n, mmin);
			n = 0;
		}
		else {
			re += min(nmin*6, mmin);
			n -= 6;
		}
	}
	cout << re;
	return 0;
}