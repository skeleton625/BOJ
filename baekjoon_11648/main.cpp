#include <iostream>
using namespace std;

unsigned long long i1;
int m = 1, c;
int main() {
	cin >> i1;
	while (i1 >= 10) {
		while (i1) {
			m *= i1 % 10;
			i1 /= 10;
		}
		i1 = m; m = 1;
		c++;
	}
	cout << c << endl;
	return 0;
}