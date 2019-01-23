#include <iostream>
#define p 1000000007
using namespace std;

int gcd(int x, int y) {
	int tmp;
	while (y) {
		tmp = y;
		y = x % y;
		x = tmp;
	}
	return x;
}

int main() {
	int t, s, g;
	unsigned long long n, ind, np, re = 0;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> t;

	while (t--) {
		np = 1;
		cin >> n >> s;
		g = gcd(n, s);
		n /= g, s /= g;
		if (s%n != 0) {
			ind = p - 2;
			while (ind) {
				if (ind & 1)
					np = (np*n) % p;
				n = (n*n) % p;
				ind >>= 1;
			}
			re = (re + (s * np)%p) % p;
		} else {
			re = (re + s / n) % p;
		}
	}
	cout << re;
	return 0;
}