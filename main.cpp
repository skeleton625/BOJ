#include <iostream>
#define p 1000000007
using namespace std;

unsigned long long A = 1, B = 1, BP = 1;
int n, k;

int main() {
	cin >> n >> k;
	if (k > n / 2) k = n - k;
	for (int i = 0; i < k; i++) {
		A = (A*(n - i)) % p;
		B = (B*(k - i)) % p;
	}

	unsigned long long ind = p - 2;
	while (ind) {
		if (ind & 1)
			BP = (BP*B) % p;
		B = (B*B) % p;
		ind >>= 1;
	}
	cout << (A*BP) % p;
	return 0;
}