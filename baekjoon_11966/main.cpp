#include <iostream>
using namespace std;

unsigned long long n;
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	while (n) {
		if (n & 1&&n!=1) {
			cout << 0;
			return 0;
		}
		n >>= 1;
	}
	cout << 1;
	return 0;
}