#include <iostream>
using namespace std;

int b, c;
unsigned long long n;
char r[1000];
int main() {
	cin >> n >> b;
	while (n > 0) {
		if (n%b > 9) r[c++] = 'A' + n % b - 10;
		else r[c++] = n % b + '0';
		n /= b;
	}
	while (c--) cout << r[c];
	return 0;
}