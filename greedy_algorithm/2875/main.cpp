#include <iostream>
using namespace std;
#define MAX 100

int main() {
	int n, m, k, less;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	while (k--) {
		if (n % 2 == 0 && n/2 <= m) --m;
		else --n;
	}
	if (n / 2 > m) cout << m;
	else cout << n / 2;

	return 0;
}