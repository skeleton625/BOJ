#include <iostream>
using namespace std;

unsigned long long a, x, re = 1, tmp;

int main() {
	cin >> a >> x;
	tmp = a % 1000000007;
	while (x) {
		if (x & 1) {
			re = (re*tmp) % 1000000007;
		}
		tmp = (tmp*tmp) % 1000000007;
		x >>= 1;
	}
	cout << re;
	return 0;
}