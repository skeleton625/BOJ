#include <iostream>
using namespace std;

int a1, a2, b1, b2, a, b;
int main() {
	ios::sync_with_stdio(false);
	cin >> a1 >> a2;
	cin >> b1 >> b2;
	a = b2 / a1 + (b2%a1 != 0 ? 1 : 0);
	b = a2 / b1 + (a2%b1 != 0 ? 1 : 0);
	if (a < b) cout << "PLAYER A";
	else if (b > a) cout << "PLAYER B";
	else cout << "DRAW";
	return 0;
}