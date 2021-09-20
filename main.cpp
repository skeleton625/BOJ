#include <iostream>
using namespace std;

int n, t;
void hanoi(int n, int from, int by, int to) {
	if (n == 1) cout << from << ' ' << to << '\n';
	else {
		hanoi(n - 1, from, to, by);
		cout << from << ' ' << to << '\n';
		hanoi(n - 1, by, from, to);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) t = 2 * t + 1;
	cout << t << '\n';
	hanoi(n, 1, 2, 3);
	return 0;
}