#include <iostream>
using namespace std;

int a, b, tmp, m;
int reverse(int n) {
	int res = 0;
	while (n) {
		res = 10*res + n%10;
		n /= 10;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b;
	for (int i = 1; i <= b; i++) {
		tmp = reverse(a*i);
		if (m < tmp) m = tmp;
	}
	cout << m;
	return 0;
}