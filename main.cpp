#include <iostream>
#define p 1500000
using namespace std;

int f1 = 0, f2 = 1, tmp;
unsigned long n;

int main() {
	cin >> n;
	if (n < 2) {
		cout << n;
	} else {
		n %= p;
		while (--n) {
			tmp = f2;
			f2 = (f1 + f2) % 1000000;
			f1 = tmp;
		}
		cout << f2;
	}
	return 0;
}