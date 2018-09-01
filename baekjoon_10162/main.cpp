#include <iostream>
using namespace std;

int n, a, b, c;
int main() {
	cin >> n;
	if (n / 300 > 0) {
		a = n / 300;
		n %= 300;
	}
	if (n / 60 > 0) {
		b = n / 60;
		n %= 60;
	}
	c = n / 10 + (n%10>0? 1: 0);
	cout << a << " " << b << " " << c;
	return 0;
}