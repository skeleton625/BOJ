#include <iostream>
using namespace std;

int cost, rest, res, tmp;
int coin[6] = { 500, 100, 50, 10, 5, 1 };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> cost;
	rest = 1000 - cost;
	for (int i = 0; i < 6; i++) {
		tmp = rest / coin[i];
		if (tmp != 0) {
			res += tmp;
			rest %= coin[i];
		}
	}

	cout << res;
	return 0;
}