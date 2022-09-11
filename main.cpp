#include <iostream>
using namespace std;

int a, b, c, d, p;
int x, y;
int main() {
	cin >> a >> b >> c >> d >> p;
	x = p*a;
	y = b + (p <= c ? 0 : (p - c)*d);
	cout << (x > y ? y : x);
	return 0;
}