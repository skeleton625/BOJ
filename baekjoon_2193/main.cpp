#include <iostream>
using namespace std;

unsigned long long cash[90][2] = { {0, 1}, {0, 1}, {1, 1} };
int n;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 3; i < n; i++) {
		cash[i][0] = cash[i-1][1] + cash[i-1][0];
		cash[i][1] = cash[i - 1][0];
	}

	cout << cash[n - 1][0] + cash[n - 1][1];
	return 0;
}